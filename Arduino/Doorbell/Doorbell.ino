//================================Doorbell.h=============================
// Main file for the Lecturer Availability Door Announcer final year BEng project by Chris Stubbs.
//=====================================================================

#define VERSION "0.4"//update when comitted to github

#include <WiFi.h>
#include <DNSServer.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h> //needed?
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

GxIO_Class io(SPI, /*CS*/ 15, /*DC*/ 4, /*RST*/ 5);
GxEPD_Class display(io, /*RST*/ 5, /*BUSY*/ 16);
DNSServer dnsServer;
WebServer webServer(80);
boolean settingMode;
int doorbells = 0;

void setup() {
  Wire.begin();
  Serial.begin(115200);
  Serial.println((String)"[INFO] Lecturer availability door announcer version " + (String)VERSION);
  display.init();
  initGPIO();
  displayVersion();
  initFS();
  if (loadConfig()) {
    if (EAP_IDENTITY == "") {
      //if wpa2-psk
      Serial.println((String)"[INFO] WPA2-PSK mode.");
      WiFi.begin(ssid.c_str(), wifipsk.c_str());
    } else {
      //if eduroam
      Serial.println((String)"[INFO] WPA2-Enterprise mode.");
      WiFi.disconnect(true);
      WiFi.mode(WIFI_STA);
      const unsigned char* EAP_IDENTITY_A = reinterpret_cast<const unsigned char *>( EAP_IDENTITY.c_str() ); //convert strings to unsigned char for enterprise functions
      const unsigned char* EAP_PASSWORD_A = reinterpret_cast<const unsigned char *>( EAP_PASSWORD.c_str() );
      esp_wifi_sta_wpa2_ent_set_username(EAP_IDENTITY_A, strlen(EAP_IDENTITY.c_str())); //set enterprise wifi parameters
      esp_wifi_sta_wpa2_ent_set_password(EAP_PASSWORD_A, strlen(EAP_PASSWORD.c_str()));
      esp_wpa2_config_t config = WPA2_CONFIG_INIT_DEFAULT(); //set config settings to default
      esp_wifi_sta_wpa2_ent_enable(&config); //enable enterprise mode
      WiFi.begin(ssid.c_str(), wifipsk.c_str()); //connect to AP
    }
    if (checkConnection()) {
      startWebServer();
    } else {
      setupMode();
      return; //abort boot to carry out initial setup wizard
    }
  }
  else {
    setupMode();
    return; //abort boot to carry out initial setup wizard
  }
  detectVCNLs();
  calibrateVCNLs();
  writeNames();
}

void loop() {
  wifiTasks();
  scanVCNLs();
  checkButtons();
  delay(SCAN_INTERVAL);
}
