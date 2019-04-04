/**
    \file GUI.ino
    Handles drawing of GUI elements on ePaper display
*/

//======================Variables for GUI==============================
String logbuffer[8] = { "", "", "", "", "", "", "", "" }; //!< Buffer of last 8 log messages to show on screen. FIFO queue.
const GFXfont* font = &FreeMonoBold9pt7b; //!< Define the font used for the GUI.

/*! Displays an LSBU splashscreen followed by a description/version no. splashscreen. */
void displayVersion()
{
  //set up parameters
  display.setRotation(1);
  display.fillScreen(GxEPD_WHITE);
  display.setTextColor(GxEPD_BLACK);
  display.setFont(font);
  //show LSBU logo
  display.drawBitmap(0, 0, BmpLSBU, 296, 128, GxEPD_BLACK);
  display.update();
  delay(2000);
  //Show version
  display.fillScreen(GxEPD_WHITE);
  display.setCursor(0, 0);
  display.println();
  display.println("Lecturer availability door");
  display.println("announcer");
  display.println();
  display.println("Final year BEng project");
  display.println("By Chris Stubbs 2018/19");
  display.println((String)"FW Revision: " + (String)VERSION);
  display.println("Starting up...");
  display.update();
  delay(3000);
}

/*! Displays a full screen error message with title and content for 5 seconds. Can be dismissed by pressing either button. Message is also printed to the serial port and the ERROR LED flashed. */
void errorMsg(String ermsg)
{
  digitalWrite(LEDERRPIN, HIGH);
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
  unsigned long tmr = millis();
  while ((millis() - tmr < 5000)) {
    if (digitalRead(BTNAPIN)) break; //allow button press to dismiss error
    if (digitalRead(BTNBPIN)) break;
  }
  digitalWrite(LEDERRPIN, LOW);
}

/*! Instructs user to connect to access point and run setup wizard. */
void setupMsg(String apSSID)
{
  Serial.println((String)"[INFO] Starting config access point named " + apSSID);
  Serial.println((String)"[INFO] Starting config web server at " + WiFi.softAPIP().toString());
  display.setRotation(1);
  display.fillScreen(GxEPD_WHITE);
  display.setTextColor(GxEPD_BLACK);
  display.setFont(font);
  display.setCursor(0, 14);
  display.println("------- Config Mode -------");
  display.println("Scan for access points");
  display.println("and connect to " + apSSID + ".");
  display.println();
  display.println("Go to " + WiFi.softAPIP().toString());
  display.println("to set up.");
  display.update();
}

/*! Write the room name, all lecturer names, status, battery percentage and sleep status to the display. */
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
  display.setCursor(270, 122);
  if (sleeping) display.println("Zz");

  //Draw battery icon and percentage
  float VBAT = ((200.0f / 100.0f) * 3.30f * float(analogRead(BATTMONPIN)) / 4095.0f) + 0.2f; // LiPo battery
  int vbatt = (float)((100.0f / 4.2f) * VBAT);
  Serial.print("[INFO] Battery Voltage = "); Serial.print(VBAT, 2); Serial.println(" V");
  display.drawRect(1, 113, 30, 13, GxEPD_BLACK);
  display.drawRect(2, 114, 28, 11, GxEPD_BLACK);
  display.fillRect(31, 116, 3, 7, GxEPD_BLACK);
  display.fillRect(1, 113, (int)(vbatt / 3.33), 13, GxEPD_BLACK); //fill to battery %
  display.setCursor(35, 123);
  display.println((String)vbatt + "%");

  display.update(); //Send buffer to display
}

/*! Shuffle the log buffer and add a new time. Display log. */
void addToLog(const String n)
{
  for (int i = 0; i < 7; i++) {
    logbuffer[i] = logbuffer[i + 1];
  }
  logbuffer[7] = n;
  displayLog();
}

/*! Display all log items in the buffer, most recent at the bottom. */
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

/*! Remove all entries in the log buffer. */
void clearLog()
{
  for (int i = 0; i <= 7; i++) {
    logbuffer[i] = "";
  }
}

/*! Shows simple menu with FW version, IP, n sensors found. Also allows user to initiate a reset of the device configuration. */
void showInfo() {
  //set up parameters
  bool shown = false;
  while (!shown) {
    display.setRotation(1);
    display.fillScreen(GxEPD_WHITE);
    display.setTextColor(GxEPD_BLACK);
    display.setFont(font);
    display.fillScreen(GxEPD_WHITE);
    display.setCursor(0, 14);
    display.println((String)"FW Revision: " + (String)VERSION);
    display.println("IP addr: " + WiFi.localIP().toString());
    display.println("Connected to " + ssid);
    display.println((String)doorbells + " sensors found");
    display.println();
    display.println();
    display.println("[A]-Close  [B]-Reset");
    display.update();
    shown = true;
    while (digitalRead(BTNAPIN)) {}
    unsigned long tmr = millis();
    while ((millis() - tmr < 60000)) {
      wifiTasks();//Run WiFi background tasks while waiting
      if (digitalRead(BTNAPIN)) break;
      if (digitalRead(BTNBPIN)) {
        while (digitalRead(BTNBPIN)) {}
        display.fillScreen(GxEPD_WHITE);
        Serial.println("Are you sure you want to\nreset this device?");
        display.setCursor(0, 14);
        display.println("Are you sure you want to");
        display.println("reset this device?");
        display.println();
        display.println("All settings will be lost.");
        display.println();
        display.println("[A]-No");
        display.println("[B]-Yes (hold for 5 sec)");
        display.update();
        if (digitalRead(BTNAPIN)) break;
        while (1) {
          if (digitalRead(BTNAPIN)) {
            shown = false;
            break;
          }
          if (digitalRead(BTNBPIN)) {
            unsigned long tmr2 = millis();
            while (digitalRead(BTNBPIN)) {
              if ((millis() - tmr2 > 5000)) {
                //Clear settings and restart
                SPIFFS.remove("/config.json");
                delay(1000);
                ESP.restart();
              }
            }
          }
        }
      }
    }
  }
  writeNames();
}

/*! Wrap words around spaces to print nicely on screen. */
String wordWrap(String in) {
  if (in.length() > 27) {
    for (int i = 27; i > 1; i--) { //work backwards from limit of string to first space
      if (in.charAt(i) == ' ') {
        return (in.substring(0, i) + "\n" + in.substring(i + 1, in.length())); //there is a space to replace with a line break
      }
    }
    return in; //There were no spaces to replace, return plain string
  } else {
    return in; //String will fit on screen, return plain string
  }
}
