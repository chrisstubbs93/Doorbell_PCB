//================================Web.h===============================
// Handles WiFi access point, WiFi client, DNS server, webservers for initial setup wizard and configuration, IFTTT integration.
// Also contains all HTML for webservers
//=====================================================================

const IPAddress apIP(192, 168, 1, 1);
const char* apSSID = "_SETUP";
String ssidList;

void wifiTasks() {
  if (settingMode) {
    dnsServer.processNextRequest();
  }
  webServer.handleClient();
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

boolean checkConnection() {
  int count = 0;
  Serial.print("[INFO] Connecting to " + ssid);
  addToLog("Conn to. " + ssid);
  while ( count < 30 ) {
    if (WiFi.status() == WL_CONNECTED) {
      Serial.println("\n[INFO] Connected!");
      settingMode = false;
      return (true);
    }
    delay(500);
    Serial.print(".");
    count++;
  }
  Serial.println();
  errorMsg("WiFi connection timed out.");
  settingMode = true;
  return false;
}

void startWebServer() {
  if (settingMode) { //Set up webserver to serve captive portal for wifi setup wizard
    Serial.println((String)"[INFO] Starting Web Server at " + WiFi.softAPIP().toString());
    clearLog();
    addToLog((String)"Join " + apSSID + " and go to");
    addToLog((String)WiFi.softAPIP().toString() + " to set up.");
    webServer.on("/settings", handleSettings);
    webServer.on("/eduroam", handleEduroam);
    webServer.on("/setap", handleSetAP);
    webServer.onNotFound(handleSetupRoot);
  }
  else { //Set up webserver to serve normal setup page
    Serial.print("[INFO] Starting Web Server at ");
    Serial.println(WiFi.localIP().toString());
    addToLog((String)"IP addr: " + WiFi.localIP().toString());
    webServer.on("/", handleRoot);
    webServer.on("/reset", handleReset);
    webServer.on("/savesettings.do", saveSettings);
    webServer.onNotFound(handleNotFound);
  }
  webServer.begin();
}

void setupMode() {
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  int n = WiFi.scanNetworks();
  delay(100);
  Serial.println("");
  for (int i = 0; i < n; ++i) {
    ssidList += "<option value=\"";
    ssidList += WiFi.SSID(i);
    ssidList += "\">";
    ssidList += WiFi.SSID(i);
    ssidList += "</option>";
  }
  delay(100);
  WiFi.mode(WIFI_AP);
  delay(250);
  WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));
  delay(100);
  WiFi.softAP(apSSID);
  delay(100);
  dnsServer.setErrorReplyCode(DNSReplyCode::NoError);
  dnsServer.start(53, "*", apIP);
  startWebServer();
  Serial.println((String)"[INFO] Starting Access Point at " + apSSID);
}

String makePage(String title, String contents) {
  String s = "<!DOCTYPE html><html><head>";
  s += "<meta name=\"viewport\" content=\"width=device-width,user-scalable=0\">";
  s += "<title>Lecturer availability door announcer</title>";
  s += "<style> body { background-color: #cccccc; font-family: Arial, Helvetica, Sans-Serif; Color: #000088; } </style>";
  s += "</head><body>";
  s += contents;
  s += "</body></html>";
  return s;
}

String urlDecode(String input) {
  String s = input;
  s.replace("%20", " ");
  s.replace("+", " ");
  s.replace("%21", "!");
  s.replace("%22", "\"");
  s.replace("%23", "#");
  s.replace("%24", "$");
  s.replace("%25", "%");
  s.replace("%26", "&");
  s.replace("%27", "\'");
  s.replace("%28", "(");
  s.replace("%29", ")");
  s.replace("%30", "*");
  s.replace("%31", "+");
  s.replace("%2C", ",");
  s.replace("%2E", ".");
  s.replace("%2F", "/");
  s.replace("%2C", ",");
  s.replace("%3A", ":");
  s.replace("%3A", ";");
  s.replace("%3C", "<");
  s.replace("%3D", "=");
  s.replace("%3E", ">");
  s.replace("%3F", "?");
  s.replace("%40", "@");
  s.replace("%5B", "[");
  s.replace("%5C", "\\");
  s.replace("%5D", "]");
  s.replace("%5E", "^");
  s.replace("%5F", "-");
  s.replace("%60", "`");
  return s;
}

void handleRoot() {
  if (!webServer.authenticate(&www_username[0u], &www_password[0u])) {
    return webServer.requestAuthentication();
    webServer.send(200, "text/plain", "Login OK");
  }
  else {
    int sec = millis() / 1000;
    int min = sec / 60;
    int hr = min / 60;
    char timestamp [100];
    snprintf(timestamp, 100, "%02d:%02d:%02d", hr, min % 60, sec % 60);

    String temp = "<html>\
  <head>\
    <title>Lecturer availability door announcer</title>\
    <style>\
      body { background-color: #cccccc; font-family: Arial, Helvetica, Sans-Serif; Color: #000088; }\
    </style>\
  </head>\
  <body>\
    <h1>Lecturer availability door announcer</h1>\
    Final year BEng project by Chris Stubbs (2019)\
    <h2>Status</h2>\
    <p>Uptime: " + (String)timestamp + "</p>\
    <p>Battery: " + (String)99 + "%</p>\
    <h2>Settings</h2>\
<form action='/savesettings.do' method='post'>\
Sensor threshold: <input name='threshold' type='text' value='" + (String)thres + "'>\
<br /><br />\
Room name: <input name='room' type='text' value='" + room + "'>\
<br /><br />\
Admin password: <input name='adminpw' type='text' value='" + www_password + "'>\
<br /><br />\
<table width='500'>\
  <tr>\
    <td>&nbsp;</td>\
    <td>Lecturer 1</td>\
    <td>Lecturer 2</td>\
    <td>Lecturer 3</td>\
    <td>Lecturer 4</td>\
    <td>Lecturer 5</td>\
  </tr>\
  <tr>\
    <td>Name</td>\
    <td><input name='l1name' type='text' value='" + lecturerNames[0] + "'></td>\
    <td><input name='l2name' type='text' value='" + lecturerNames[1] + "'></td>\
    <td><input name='l3name' type='text' value='" + lecturerNames[2] + "'></td>\
    <td><input name='l4name' type='text' value='" + lecturerNames[3] + "'></td>\
    <td><input name='l5name' type='text' value='" + lecturerNames[4] + "'></td>\
  </tr>\
  <tr>\
    <td>Key</td>\
    <td><input name='l1key' type='text' value='" + lecturerIFTTkeys[0] + "'></td>\
    <td><input name='l2key' type='text' value='" + lecturerIFTTkeys[1] + "'></td>\
    <td><input name='l3key' type='text' value='" + lecturerIFTTkeys[2] + "'></td>\
    <td><input name='l4key' type='text' value='" + lecturerIFTTkeys[3] + "'></td>\
    <td><input name='l5key' type='text' value='" + lecturerIFTTkeys[4] + "'></td>\
  </tr>\
</table>\
<input type='submit' value='Save'>\
</form>\
<br /><br />\
<p><a href='/reset'>Reset all settings and run Wi-Fi setup</a></p>\
  </body>\
</html>";
    webServer.send(200, "text/html", temp);
  }
}

void saveSettings() {
  if (!webServer.authenticate(&www_username[0u], &www_password[0u])) {
    return webServer.requestAuthentication();
    webServer.send(200, "text/plain", "Login OK");
  }
  else {
    room = webServer.arg("room");
    thres = webServer.arg("threshold").toFloat();
    www_password = webServer.arg("adminpw");
    lecturerNames[0] = webServer.arg("l1name");
    lecturerNames[1] = webServer.arg("l2name");
    lecturerNames[2] = webServer.arg("l3name");
    lecturerNames[3] = webServer.arg("l4name");
    lecturerNames[4] = webServer.arg("l5name");
    lecturerIFTTkeys[0] = webServer.arg("l1key");
    lecturerIFTTkeys[1] = webServer.arg("l2key");
    lecturerIFTTkeys[2] = webServer.arg("l3key");
    lecturerIFTTkeys[3] = webServer.arg("l4key");
    lecturerIFTTkeys[4] = webServer.arg("l5key");
    String out = "";
    out += "Saved!\n";
    out += "<a href='/'>Go back</a>\n";
    webServer.send(200, "text/html", out);
    saveConfig(); //commit new settings to config file
    writeNames(); //update the display
  }
}

void handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += webServer.uri();
  message += "\nMethod: ";
  message += (webServer.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += webServer.args();
  message += "\n";

  for (uint8_t i = 0; i < webServer.args(); i++) {
    message += " " + webServer.argName(i) + ": " + webServer.arg(i) + "\n";
  }
  webServer.send(404, "text/plain", message);
}

void handleReset() {
  if (!webServer.authenticate(&www_username[0u], &www_password[0u])) {
    return webServer.requestAuthentication();
    webServer.send(200, "text/plain", "Login OK");
  }
  else {
    SPIFFS.remove("/config.json");
    String s = "<h1>Wi-Fi settings reset.</h1><p>The device will now restart.</p>";
    s += "<p>Scan for and connect to the Setup access point.</p>";
    s += "<p>You may now close this page.</p>";
    webServer.send(200, "text/html", makePage("Reset Wi-Fi Settings", s));
    delay(1000); //delay to finish serving the page before restart
    ESP.restart();
  }
}

void handleSetupRoot() {
  String s = "<h1>Lecturer availability door announcer</h1>";
  s += "<p>Final year BEng project by Chris Stubbs (2019)</p>";
  s += "<p><a href=\"/settings\">Setup wizard for standard WiFi (WPA2)</a></p>";
  s += "<p><a href=\"/eduroam\">Setup wizard for eduroam (WPA2-Enterprise)</a></p>";
  webServer.send(200, "text/html", makePage("Setup Wizard", s));
}
void handleSettings() {
  String s = "<h1>Wi-Fi Settings</h1><p><a href=\"/\">Go back</a></p><p>Please enter settings for standard WiFi (WPA2).</p>";
  s += "<form method=\"get\" action=\"setap\">";
  s += "<table><tr>";
  s += "<td>SSID:</td><td><select name=\"ssid\">";
  s += ssidList;
  s += "</select></td></tr><td>Password:</td><td><input name=\"pass\" length=64 type=\"password\"></td></tr>";
  s += "<tr><td><input type=\"submit\"></td></tr></table></form>";
  webServer.send(200, "text/html", makePage("Wi-Fi Settings", s));
}
void handleEduroam() {
  String s = "<h1>Wi-Fi Settings</h1><p><a href=\"/\">Go back</a></p><p>Please enter settings for eduroam (WPA2-Enterprise).</p><p>Password is typically left blank.</p><p>EAP Identity is typically your university email address.</p><p>EAP Password is typically your university password.</p>";
  s += "<form method=\"get\" action=\"setap\">";
  s += "<table><tr>";
  s += "<td>SSID:</td><td><select name=\"ssid\"><option selected value=\"eduroam\">eduroam</option>";
  s += ssidList;
  s += "</select></td></tr><td>Password:<?td><td><input name=\"pass\" length=64 type=\"password\"></td></tr>";
  s += "<tr><td>EAP Identity:</td><td><input name=\"eapidentity\" length=64></td></tr>";
  s += "<tr><td>EAP Password:</td><td><input name=\"eappass\" length=64 type=\"password\"></td></tr>";
  s += "<tr><td><input type=\"submit\"></td></tr></table></form>";
  webServer.send(200, "text/html", makePage("Wi-Fi Settings", s));
}
void handleSetAP() {
  ssid = urlDecode(webServer.arg("ssid"));
  wifipsk = urlDecode(webServer.arg("pass"));
  EAP_IDENTITY = urlDecode(webServer.arg("eapidentity"));
  EAP_PASSWORD = urlDecode(webServer.arg("eappass"));
  saveConfig();

  String s = "<h1>Setup complete.</h1><p>Device will be connected to \"";
  s += ssid;
  s += "\" after the restart.</p>";
  s += "<p>Check the IP address displayed on the device and access this page from your web browser to continue the setup process.</p>";
  s += "<p>The username and password for the settings portal will be " + www_username + "/" + www_password + ".</p>";

  s += "<p>You may now close this page.</p>";
  webServer.send(200, "text/html", makePage("Wi-Fi Settings", s));
  delay(1000); //delay to finish serving the page before restart
  ESP.restart();
}
