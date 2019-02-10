//===============Variables for wifi========================
//Rename this file to WiFi_Settings.h

//WPA2 network settings
const char* ssid     = "name"; //Set to EDUROAM for eduroam
const char* password = "pass"; //Leave blank for eduroam

//WPA2 connection details above will be used by default. Complete the fields below to override this with eduroam mode.
const char* EAP_IDENTITY = ""; //if connecting from another corporation, use identity@organisation.domain in Eduroam
const char* EAP_PASSWORD = ""; //your Eduroam password


//===============Variables for doorbell operation========================
String room = "T815";
String lecturerNames[5] = { "Name1", "Name2", "", "", ""};
String lecturerIFTTkeys[5] = { "1234", "", "", "", ""};
String lecturerStatus[5] = { "Availible", "", "", "", ""};
float thres = 1.5; //Threshold for sensor
