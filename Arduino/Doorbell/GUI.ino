//=================================GUI.h==============================
// Handles drawing of GUI elements on ePaper display
//=====================================================================

//======================Variables for GUI==============================
String logbuffer[8] = { "", "", "", "", "", "", "", "" };
String cat = String();
const GFXfont* font = &FreeMonoBold9pt7b;

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
  delay(10000);
  digitalWrite(LEDERRPIN, LOW);
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
  //display.println("              Updated ");

  //Draw battery icon and percentage
  int vbatt = (float)(analogRead(BATTMONPIN) / 40.95);
  display.drawRect(1, 113, 30, 13, GxEPD_BLACK);
  display.drawRect(2, 114, 28, 11, GxEPD_BLACK);
  display.fillRect(31, 116, 3, 7, GxEPD_BLACK);
  display.fillRect(1, 113, (int)(vbatt / 3.33), 13, GxEPD_BLACK); //fill to battery %
  display.setCursor(35, 123);
  display.println((String)vbatt + "%");

  display.update(); //Send buffer to display
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

void showInfo() {
  //set up parameters
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
  while (digitalRead(BTNAPIN)) {}
  unsigned long tmr = millis();
  while ((millis() - tmr < 600000)) {
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
        unsigned long tmr = millis();
        while (digitalRead(BTNBPIN)) {
          if ((millis() - tmr < 50000)) {
            ESP.restart();
          }
        }
      }
      if (digitalRead(BTNBPIN)) ESP.restart();
    }
  }
  writeNames();
}
