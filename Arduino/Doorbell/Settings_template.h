//Rename this file to Settings.h

//=========================Variables for wifi==========================
String ssid     = "name"; //Set to EDUROAM for eduroam
String wifipsk = "key";
String EAP_IDENTITY = ""; //if connecting from another corporation, use identity@organisation.domain in Eduroam
String EAP_PASSWORD = ""; //your Eduroam password
String www_username = "admin";
String www_password = "esp32";

//===============Variables for doorbell operation======================
String room = "T815";
String lecturerNames[5] = { "Name1", "Name2", "Name3", "", ""};
String lecturerIFTTkeys[5] = { "Key1", "Key2", "Key3", "", ""};
String lecturerStatus[5] = { "Availible", "Away", "Busy", "", ""};
float thres = 2; //Threshold for sensor

//======================Definitions for hardware=======================
#define BTNAPIN 34
#define BTNBPIN 35
#define INTERRUPTPIN 32
#define LEDAVAILPIN 19
#define LEDBUSYPIN 17
#define LEDOKPIN 2
#define LEDERRPIN 13
#define BATTMONPIN 33

//==========================Definitions for VCNL=======================
#define TCAADDR 0x70 //default 0X70
#define LEDCURR 10 //current in IR LED 10=100mA
#define TRIES 3 //number of tries to initialise each VCNL
#define N_THRES_SAMPLES 10 //number of samples to take when setting proximity threshold
#define SCAN_INTERVAL 250 //interval in ms between scans of all sensors
#define CAL_INTERVAL 360 //interval in seconds between recalibration of all sensors
#define DEBUG_READINGS 0 //Stream proximity readings to serial port 1/0
