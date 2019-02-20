//===========================Inclusions for ESP========================
#include <WiFi.h>
#include "Settings.h"
#include "bitmaps.h"
#include <HTTPClient.h>
#include "SPIFFS.h"
#include <FS.h>
#include "NTPClient.h"


#define NTP_OFFSET  19800 // In seconds
#define NTP_ADDRESS  "1.pool.ntp.org"
//WiFiUDP ntpUDP;
//NTPClient timeClient(ntpUDP);

//==========================Inclusions for epaper=======================
#include <GxEPD.h>

// select the display class to use, only one
#include <GxGDEH029A1/GxGDEH029A1.h>      // 2.9" b/w


#if !defined(_GxFont_GFX_TFT_eSPI_H_)
// FreeFonts from Adafruit_GFX
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>

#endif
#if defined(_ADAFRUIT_TF_GFX_H_)
#include <Fonts/Open_Sans_Bold_12pt.h>
#endif

#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>


//==========================Definitions for epaper============================
GxIO_Class io(SPI, /*CS=5*/ 15, /*DC=*/ 4, /*RST=*/ 5);
GxEPD_Class display(io, /*RST=*/ 5, /*BUSY=*/ 16);

#if defined(_GxGDEW0154Z04_H_) || defined(_GxGDEW0213Z16_H_) || defined(_GxGDEW029Z10_H_) || defined(_GxGDEW027C44_H_) || defined(_GxGDEW042Z15_H_) || defined(_GxGDEW075Z09_H_)
#define HAS_RED_COLOR
#endif

//======================Variables for GUI================================
String logbuffer[8] = { "", "", "", "", "", "", "", "" };
String cat = String();
const GFXfont* font = &FreeMonoBold9pt7b;


//======================Definitions for hardware================================
#define BTNAPIN 34
#define BTNBPIN 35
#define INTERRUPTPIN 32
#define LEDAVAILPIN 31
#define LEDBUSYPIN 28
#define LEDOKPIN 24
#define LEDERRPIN 16
#define BATTMONPIN 33

//===========================Inclusions for VCNL========================
#include <Wire.h>
#include "Adafruit_VCNL4010.h"


//==========================Definitions for VCNL============================
Adafruit_VCNL4010 vcnl;
#define TCAADDR 0x70 //default 0X70
#define LEDCURR 10 //current in IR LED 10=100mA
#define TRIES 3 //number of tries to initialise each VCNL
#define N_THRES_SAMPLES 10 //number of samples to take when setting proximity threshold
#define SCAN_INTERVAL 250 //interval in ms between scans of all sensors
#define CAL_INTERVAL 360 //interval in seconds between recalibration of all sensors
#define DEBUG_READINGS 0 //Stream proximity readings to serial port 1/0


//======================Variables for VCNL================================
long average[] =   {0, 0, 0, 0, 0, 0, 0, 0};
long threshold[] = {0, 0, 0, 0, 0, 0, 0, 0};
long reading[] =   {0, 0, 0, 0, 0, 0, 0, 0};
int doorbells = 0;

File fSettings;



void setup() {
  Wire.begin();
  Serial.begin(115200);
  Serial.println("[INFO] VCNL4010 test");
  initGPIO();
  display.init(); // enable diagnostic output on Serial 115200
 
  displayVersion();

  initFilesystem();
  fSettings.println("This is a test");
  fSettings.println("...");
  fSettings.close();

  fSettings = SPIFFS.open("/f.txt", "r");
  if (!fSettings) {
    Serial.println("file open failed");
  }
  Serial.println("Dump " + (String)fSettings.size() + " bytes:");
  //Serial.println(fSettings.readStringUntil('\n'));
  for (int i = 0; i < fSettings.size(); i++) //Read upto complete file size
  {
    Serial.print((char)fSettings.read());
  }
  fSettings.close();  //Close file
  Serial.println("Dump complete");


  detectVCNLs();
  calibrateVCNLs();
  connectWifi();

  //timeClient.begin();
  //timeClient.update();
  //Serial.println(timeClient.getFormattedTime());

  delay(3000);

  updateNames();
  writeNames();
}


void loop() {
  for (int bus = 0; bus < doorbells; bus++) {
    tcaselect(bus);
    vcnl.setLEDcurrent(LEDCURR); //Set IR LED on to take measurement
    delay(10); //small delay to allow IR LED to stabilise
    reading[bus] = vcnl.readProximity();
    if (reading[bus] > threshold[bus]) {
      Serial.println((String)"[INFO] Doorbell pressed on bus " + bus + " reading:" + reading[bus]);
      ring(bus);
      while (reading[bus] > threshold[bus])
      {
        reading[bus] = vcnl.readProximity();
        delay(SCAN_INTERVAL);
      }
    }
    //Set LED off to save power
    vcnl.setLEDcurrent(0);
  }
  if (DEBUG_READINGS == 1) {
    Serial.print("[DEBUG] Current readings:,");
    for (int i = 0; i <= 7; i++) {
      char buf[50];
      sprintf(buf, "%05d,", reading[i]);
      Serial.print(buf);
    }
    Serial.print("[DEBUG] Thresholds:      ,");
    for (int i = 0; i <= 7; i++) {
      char buf[50];
      sprintf(buf, "%05d,", threshold[i]);
      Serial.print(buf);
    }
  }

  //Check buttons
  if (digitalRead(BTNAPIN)) {
    Serial.println("[INFO] Button A Pressed");
    while (digitalRead(BTNAPIN)) {}
  }
  if (digitalRead(BTNBPIN)) {
    Serial.println("[INFO] Button B Pressed");
    while (digitalRead(BTNBPIN)) {}
  }

  delay(SCAN_INTERVAL);
}

void tcaselect(uint8_t i) { //sets the bus and checks it, retrying if it's not correct
  if (i > 7) return;
  do {
    if (DEBUG_READINGS == 1) {
      Serial.println((String)"[DEBUG] Selecting bus " + i);
    }
    Wire.beginTransmission(TCAADDR);
    Wire.write(1 << i);
    Wire.endTransmission();
  } while (!(tcaget() == i));
}

int tcaget() { //returns the current bus of the mux 0...7
  Wire.requestFrom(TCAADDR, 1);
  byte c = Wire.read();
  for (int i = 0; i <= 7; i++) {
    if (c == 0x01) return i;
    c = c >> 1;
  }
}


void connectWifi() {
  Serial.println((String)"[INFO] Connecting to " + ssid);
  addToLog((String)"Connecting to " + ssid);
  WiFi.begin(ssid, password);
  int wifitimeout = 0;
  while ((WiFi.status() != WL_CONNECTED) and (wifitimeout < 20)) {
    delay(500);
    Serial.print(".");
    wifitimeout++;
  }
  Serial.println();
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("[INFO] WiFi connected");
    Serial.println("[INFO] IP address: " + WiFi.localIP().toString());
    addToLog((String)"IP: " + WiFi.localIP().toString());
  } else {
    errorMsg((String)"Failed conn. to " + ssid + "\nCheck SSID and password.\nRestarting in 10 seconds.");
    delay(10000);
    ESP.restart();
  }
}

void detectVCNLs() {
  Serial.println(); Serial.println("[INFO] Autodetecting sensors....");
  addToLog("Autodetecting sensors....");
  for (int bus = 0; bus <= 7; bus++) {
    tcaselect(bus);
    int trynum = 1;
    while (! vcnl.begin() && trynum < TRIES) {
      trynum++;
      delay(100);
    }
    if (trynum < TRIES) {
      //found
      Serial.println((String)"[INFO] Found VCNL40xx on bus " + bus);
      doorbells++;
    }
    else {
      //not found
      Serial.println((String)"[INFO] No VCNL40xx on bus " + (String)bus + " terminating autodetection.");
      break;
    }
  }
  Serial.println("[INFO] Number of doorbells found: " + (String)doorbells);
  addToLog((String)doorbells + " sensors found");
}
void calibrateVCNLs() {
  for (int bus = 0; bus < doorbells; bus++) {
    tcaselect(bus);
    Serial.print("[INFO] Calibrating proximity threshold on bus " + (String)bus + " ");
    addToLog((String)"Calibrating sensor " + bus);
    vcnl.setLEDcurrent(LEDCURR); //Set IR LED on to take measurement
    delay(10); //small delay to allow IR LED to stabilise
    for (int i = 0; i <= N_THRES_SAMPLES; i++) {
      int tmp = vcnl.readProximity();
      average[bus] = average[bus] + tmp;
      Serial.print((String)((100 / N_THRES_SAMPLES)*i) + "% ");
      delay(100);
    }
    vcnl.setLEDcurrent(0); //Set IR LED off
    average[bus] = average[bus] / N_THRES_SAMPLES;
    threshold[bus] = average[bus] * thres;
    Serial.println((String)"Average level was: " + average[bus] + " Threshold set to: " + threshold[bus]);
  }
  Serial.println("[INFO] Calibration done");
}



void ring(const int bus)
{
  display.setRotation(1);
  display.fillScreen(GxEPD_WHITE);
  display.setTextColor(GxEPD_BLACK);
  display.setFont(font);
  display.setCursor(0, 16 * 4);
  display.print("Contacting "); display.print(lecturerNames[bus]); display.println("...");
  display.update();
  if ((WiFi.status() == WL_CONNECTED)) {
    HTTPClient http;
    Serial.println((String)"[INFO] HTTP Req: https://maker.ifttt.com/trigger/" + room + "/with/key/" + lecturerIFTTkeys[bus]);
    http.begin((String)"https://maker.ifttt.com/trigger/" + room + "/with/key/" + lecturerIFTTkeys[bus]);
    int httpCode = http.GET();
    if (httpCode > 0) {
      String payload = http.getString();
      Serial.println((String)"[INFO] httpCode: " + httpCode);
      Serial.println((String)"[INFO] payload: " + payload);
      if (httpCode != 200) {
        //Error communicating with IFTTT service.
        if (httpCode == 302) {
          //"Temporarily moved" (common error for no key)
          errorMsg("Error communicating with \nIFTTT.\n\nDid you set the room and\nlecturer key?");
        }
        errorMsg("Error communicating with IFTTT " + (String)httpCode + " " + payload);
        errorMsg("Req: " + (String)"https://maker.ifttt.com/trigger/" + room + "/with/key/" + lecturerIFTTkeys[bus]);
      }
      if (httpCode == 200) {
        //success
        display.setRotation(1);
        display.fillScreen(GxEPD_WHITE);
        display.setTextColor(GxEPD_BLACK);
        display.setFont(font);
        display.setCursor(0, 16 * 4);
        display.print(lecturerNames[bus]); display.println(" has been notified.");
        display.update();
      }
    }
    else {
      errorMsg("Unknown error in HTTP request.");
    }
    http.end(); //Free the resources
  } else {
    errorMsg("Wifi not connected. Restarting in 30 seconds.");
    delay(30000);
    ESP.restart();
  }
  delay(2000);
  writeNames();
}

void displayVersion() //Displays an LSBU splashscreen followed by a description/version no. splashscreen
{
  //set up parameters
  display.setRotation(1);
  display.fillScreen(GxEPD_WHITE);
  display.setTextColor(GxEPD_BLACK);
  display.setFont(font);
  //show LSBU logo
  display.drawBitmap(0, 0, BmpLSBU, 296, 128, GxEPD_BLACK);
  display.update();
  delay(5000);
  //Show version
  display.setCursor(0, 0);
  display.println();
  display.println("Lecturer availability door");
  display.println("announcer");
  display.println();
  display.println("Final year BEng project");
  display.println("By Chris Stubbs 2018/19");
  display.println("FW Revision: 0a ");
  display.println("Starting up...");
  display.update();
  delay(2000);
}

void updateNames()
{
  display.setRotation(1);
  display.fillScreen(GxEPD_WHITE);
  display.setTextColor(GxEPD_BLACK);
  display.setFont(font);
  display.setCursor(0, 16 * 4);
  display.println("        Updating...        ");
  display.update();
  delay(1000);
}

void errorMsg(String ermsg)
{
  String tmpermsg = ermsg;
  tmpermsg.replace("\n", " ");
  Serial.println("[ERROR] " + tmpermsg);
  display.setRotation(1);
  display.fillScreen(GxEPD_WHITE);
  display.setTextColor(GxEPD_BLACK);
  display.setFont(font);
  display.setCursor(0, 0);
  display.println();
  display.println("!!!----!!! Error !!!----!!!");
  display.println(ermsg);
  display.update();
  delay(10000);
}

void writeNames()
{
  display.setRotation(1);
  display.fillScreen(GxEPD_WHITE);
  display.setTextColor(GxEPD_BLACK);
  display.setFont(font);
  display.setCursor(0, 14);
  display.println("-------- Room " + room + " --------");
  for (int i = 0; i < 5; i++) {
    display.setCursor(0, 35 + (16 * i));
    display.println(lecturerNames[i]);
    display.setCursor(175, 35 + (16 * i));
    if (lecturerNames[i] != "") display.println("-");
    display.setCursor(190, 35 + (16 * i));
    display.println(lecturerStatus[i]);
  }
  display.setCursor(0, 123);
  //String formattedTime = timeClient.getFormattedTime();
  display.println("              Updated ");// + formattedTime);

  int vbatt = (float)(analogRead(BATTMONPIN) / 40.95);
  display.drawRect(1, 113, 30, 13, GxEPD_BLACK);
  display.drawRect(2, 114, 28, 11, GxEPD_BLACK);
  display.fillRect(31, 116, 3, 7, GxEPD_BLACK);
  display.fillRect(1, 113, (int)(vbatt / 3.33), 13, GxEPD_BLACK); //fill to battery %
  display.setCursor(35, 123);
  display.println((String)vbatt + "%");
  display.update();
}
void addToLog(const String n)
{
  for (int i = 0; i < 7; i++) {
    logbuffer[i] = logbuffer[i + 1];
  }
  logbuffer[7] = n;
  displayLog();
}

void displayLog()
{
  display.setRotation(1);
  display.fillScreen(GxEPD_WHITE);
  display.setTextColor(GxEPD_BLACK);
  display.setFont(font);
  display.setCursor(0, 0);
  for (int i = 0; i < 8; i++) {
    display.println(logbuffer[i]);
  }
  display.update();
}
void clearLog()
{
  for (int i = 0; i <= 7; i++) {
    logbuffer[i] = "";
  }
}

void initFilesystem() {
  if (SPIFFS.begin())
  {
    Serial.println("[INFO] SPIFFS Initialized");
  }
  else
  {
    Serial.println("[ERROR] SPIFFS Init failed");
    addToLog("SPIFFS Init failed");
  }
  fSettings = SPIFFS.open("/settings.txt", "w");
  while (!fSettings) {
    Serial.println("[ERROR] settings file open failed");
    addToLog("Settings file open failed");
    addToLog("Formatting.. wait 30s");
    if (SPIFFS.format())
    {
      Serial.println("[INFO] File System Formated");
      addToLog("Formatted. Retrying.");
    }
    else
    {
      Serial.println("[ERROR] File System Formatting Error");
      addToLog("Format error.");
    }
    fSettings = SPIFFS.open("/settings.txt", "w");
  }
  Serial.println("[INFO] Filesystem ready");
  addToLog("Filesystem ready");
}

void initGPIO() {
  pinMode(BTNAPIN, INPUT);
  pinMode(BTNBPIN, INPUT);
  pinMode(INTERRUPTPIN, INPUT);
  pinMode(BATTMONPIN, INPUT);

  pinMode(LEDAVAILPIN, OUTPUT);
  pinMode(LEDBUSYPIN, OUTPUT);
  pinMode(LEDOKPIN, OUTPUT);
  pinMode(LEDERRPIN, OUTPUT);
}
