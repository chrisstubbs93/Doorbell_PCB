//================================Config.h=============================
// Handles SPIFFS filesystem, loading of configuration files, saving of configuration files.
//=====================================================================

void initFS(){
    Serial.println("[INFO] Mounting filesystem...");
  if (!SPIFFS.begin()) {
    errorMsg("Failed to mount file sys.\nAttempting to format.\nThis is normal for 1st use.\nPlease wait 30 seconds.");
    SPIFFS.format();
    if (SPIFFS.begin()) {
      Serial.println("[INFO] SPIFFS format complete");
    } else{
      return;
    }
  }
  delay(10);
}

bool loadConfig() {
  File configFile = SPIFFS.open("/config.json", "r");
  if (!configFile) {
    errorMsg("Failed to open config file");
    settingMode = true;
    return false;
  }
  size_t size = configFile.size();
  if (size > 1024) {
    errorMsg("Config file size is too large");
    settingMode = true;
    return false;
  }
  std::unique_ptr<char[]> buf(new char[size]);  // Allocate a buffer to store contents of the file.
  configFile.readBytes(buf.get(), size); //Mutable buffer
  StaticJsonBuffer<5000> jsonBuffer;
  JsonObject& json = jsonBuffer.parseObject(buf.get());
  if (!json.success()) {
    errorMsg("Failed to parse cfg file.\nThis is normal for 1st use.");
    settingMode = true;
    return false;
  }
  //Restore basic device settings
  EAP_IDENTITY = (const char*)json["EAP_IDENTITY"];
  EAP_PASSWORD = (const char*)json["EAP_PASSWORD"];
  ssid = (const char*)json["ssid"];
  wifipsk = (const char*)json["wifipsk"];
  www_username = (const char*)json["www_username"];
  www_password = (const char*)json["www_password"];
  room = (const char*)json["room"];
  thres = json["thres"];

  //Restore lecturer details
  for (int i = 0; i < 5; i++) {
    lecturerNames[i] = (const char*)json["lecturerNames"][(String)i];
    lecturerIFTTkeys[i] = (const char*)json["lecturerIFTTkeys"][(String)i];
    lecturerStatus[i] = (const char*)json["lecturerStatus"][(String)i];
  }

  Serial.print("[INFO] Parameters loaded:");
  json.printTo(Serial);
  Serial.println();
  return true;
}
bool saveConfig() {
  StaticJsonBuffer<5000> jsonBuffer;
  JsonObject& json = jsonBuffer.createObject();
  //Store basic device settings
  json["EAP_IDENTITY"] = EAP_IDENTITY;
  json["EAP_PASSWORD"] = EAP_PASSWORD;
  json["ssid"] = ssid;
  json["wifipsk"] = wifipsk;
  json["www_username"] = www_username;
  json["www_password"] = www_password;
  json["room"] = room;
  json["thres"] = thres;

  //Store lecturer details
  JsonObject& jsonLecNames = jsonBuffer.createObject();
  JsonObject& jsonLecKeys = jsonBuffer.createObject();
  JsonObject& jsonLecStatus = jsonBuffer.createObject();
  for (int i = 0; i < 5; i++) {
    jsonLecNames[(String)i] = lecturerNames[i];
    jsonLecKeys[(String)i] = lecturerIFTTkeys[i];
    jsonLecStatus[(String)i] = lecturerStatus[i];
  }
  json["lecturerNames"] = jsonLecNames;
  json["lecturerIFTTkeys"] = jsonLecKeys;
  json["lecturerStatus"] = jsonLecStatus;

  Serial.print("[INFO] Parameters stored:");
  json.printTo(Serial);
  Serial.println();

  File configFile = SPIFFS.open("/config.json", "w");
  if (!configFile) {
    Serial.println("[ERROR] Failed to open config file for writing");
    return false;
  }
  json.printTo(configFile);
  return true;
}
