/**
    \file Settings_template.h
    Contains user settings and presets that can be changed for build. Rename this file to Settings.h.
*/

//=========================Variables for wifi==========================
String ssid = ""; //!< WiFi SSID the device will connect to. Set from setup wizard.
String wifipsk = ""; //!< WiFi pre-shared key (password) the device will connect with. Set from setup wizard.
String EAP_IDENTITY = ""; //!< WPA2-ENTERPRISE (eduroam) email address. Set from setup wizard.
String EAP_PASSWORD = ""; //!< WPA2-ENTERPRISE (eduroam) password. Set from setup wizard.
String www_username = "admin"; //!< Defualt username for web config interface. Set from web config interface.
String www_password = "esp32"; //!< Defualt password for web config interface. Set from web config interface.

//===============Variables for doorbell operation======================
String room = "T815"; //!< Name of room device is fixed to. Set from web config interface.
String lecturerNames[5] = { "Name1", "Name2", "Name3", "", ""}; //!< Array of lectureres names. Set from web config interface.
String lecturerIFTTkeys[5] = { "Key1", "Key2", "Key3", "", ""}; //!< Array of lecturer IFTTT keys. Set from web config interface.
String lecturerStatus[5] = { "Available", "Away", "Busy", "", ""}; //!< Array of lecturer status. Set from web config interface.
float thres = 2; //!< Threshold for sensor.
bool busyNotif = false; //!< Notify lecturer anyway if they are busy?
bool powerSave = false; //!< Enter power saving mode after inactivity?
int sleepDelay = 15; //!< Period of inactivity in mins before entering power save mode.

//======================Definitions for hardware=======================
#define BTNAPIN 34 //!< GPIO pin number for A button.
#define BTNBPIN 35 //!< GPIO pin number for B button.
#define INTERRUPTPIN 32 //!< GPIO pin number for VCNL interrupt summary.
#define LEDAVAILPIN 19 //!< GPIO pin number for Available LED.
#define LEDBUSYPIN 17 //!< GPIO pin number for Busy LED.
#define LEDOKPIN 2 //!< GPIO pin number for OK LED.
#define LEDERRPIN 13 //!< GPIO pin number for Error LED.
#define BATTMONPIN 33 //!< GPIO pin number for battery voltage divider.
#define INTERRUPTPINMASK 0xC00000000 //!< Bit mask for button interrupt. Binary string of selected GPIO pins with GPIO0 being LSB, converted to hex. 0xC00000000 selects 34, 35.

//==========================Definitions for VCNL=======================
#define TCAADDR 0x70 //!< Default address of the multiplexer 0X70.
#define LEDCURR 10 //!< Current in IR LED, 10=100mA.
#define TRIES 3 //!< Number of tries to initialise each VCNL.
#define N_THRES_SAMPLES 10 //!< Number of samples to take when setting proximity threshold.
#define SCAN_INTERVAL 250 //!< Interval in ms between scans of all sensors.
#define DEBUG_READINGS 0 //!< Stream proximity readings to serial port 1/0.
