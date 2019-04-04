/**
    \file Doorbell.ino
    Main file for the Lecturer Availability Door Announcer final year BEng project by Chris Stubbs.
*/

#define VERSION "1.1"//update when comitted to github

#include <WiFi.h>
#include <DNSServer.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include "esp_wpa2.h"
#include <ArduinoJson.h>
#include "Settings.h" //Initial settings
#include "bitmaps.h"
#include <HTTPClient.h>
#include "SPIFFS.h"
#include <Wire.h>
#include "Adafruit_VCNL4010.h"
#include <GxEPD.h>
#include <GxIO/GxIO.h>
#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxGDEH029A1/GxGDEH029A1.h>      // select the display class to use: 2.9" b/w
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>

GxIO_Class io(SPI, /*! CS */ 15, /*! DC */ 4, /*! RST */ 5); //!< Define the hardware pins used by the ePaper display for SPI. 15=CS, 4=DC, 5=RST.
GxEPD_Class display(io, /*!RST*/ 5, /*!BUSY*/ 16); //!< Define the hardware pins used by the ePaper display for control. 5=RST, 16=BUSY..
DNSServer dnsServer; //!< DNS server used for captive portal in setup mode.
WebServer webServer(80); //!< Web server used for setup wizard and config interface.
boolean settingMode; //!< Is the device in setup wizard mode (true) or normal mode (false)?
int doorbells = 0;  //!< Number of VCNL4020 sensors detected.
bool sleeping = false; //!< Is the device in or about to enter deep sleep mode for power saving?

/*! Setup function runs once on startup. Detect boot mode (normal or waking up from deep sleep). Perform setup. */
void setup() {
  Wire.begin();
  Serial.begin(115200);
  Serial.println((String)"[INFO] Lecturer availability door announcer version " + (String)VERSION);
  wakeup_reason();
  display.init();
  initGPIO();
  if (bootmode() == 6) displayVersion();
  initFS();
  bool configstatus = loadConfig();
  if (bootmode() == 3) { //wakeup cause by timer. Update battery % on screen and go back to sleep.
    sleeping = true; //set the sleeping flag
    writeNames(); //show the sleeping flag on screen
    entersleep(); //go to sleep
  }
  if (configstatus) {
    //Config loaded OK. Try to connect to WiFi.
    if (connectWiFi()) {
      //WiFi connected OK. Start config web server and continue boot.
      startWebServer();
    } else {
      //WiFi failed to connect. Start setup mode and abort boot.
      setupMode();
      return;
    }
  }
  else {
    setupMode();
    return; //abort boot to carry out initial setup wizard
  }
  detectVCNLs();
  if (bootmode() == 1) {
    int source = interruptSource();
    Serial.println((String)"[INFO] Interrupt triggered by sensor " + interruptSource());
    ring(source);
  }
  calibrateVCNLs();
  writeNames();
}

/*! Loop function runs continuously. Poll devices and run background tasks. */
void loop() {
  wifiTasks();
  scanVCNLs();
  checkButtons();
  manageSleep();
  delay(SCAN_INTERVAL);
}
