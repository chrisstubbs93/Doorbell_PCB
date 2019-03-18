//===============================Hardware.h============================
// Handles I2C multiplexer, connection to VCNL IR proximity sensors, proximity sensor related functions, initialisation of GPIO, scanning of buttons.
//=====================================================================



//======================Variables for VCNL==============================
long average[] =   {0, 0, 0, 0, 0, 0, 0, 0};
long threshold[] = {0, 0, 0, 0, 0, 0, 0, 0};
long reading[] =   {0, 0, 0, 0, 0, 0, 0, 0};

Adafruit_VCNL4010 vcnl;

void initGPIO() {
  //Initialise the GPIO pins. This should be run AFTER initialising the display so the MISO pin can be detached from the pin matrix and reused.
  pinMode(BTNAPIN, INPUT);
  pinMode(BTNBPIN, INPUT);
  pinMode(INTERRUPTPIN, INPUT);
  pinMode(BATTMONPIN, INPUT);

  pinMatrixInDetach(VSPIQ_OUT_IDX, false, false); //detatch pin 19 from the VSPI MISO.
  pinMode(LEDAVAILPIN, OUTPUT);
  pinMode(LEDBUSYPIN, OUTPUT);
  pinMode(LEDOKPIN, OUTPUT);
  pinMode(LEDERRPIN, OUTPUT);
}

void setVCOM(unsigned char d) {
  //Set the VCOM. This isn't normally needed unless the ePaper is particularly bad.
  digitalWrite(4, LOW);
  digitalWrite(15, LOW);
  SPI.transfer(0x2C); //Write VCOM register
  digitalWrite(15, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(15, LOW);
  SPI.transfer(d);
  digitalWrite(15, HIGH);
}

void tcaselect(uint8_t i) { //sets the bus and checks it, retrying if it's not correct
  if (i > 7) return;
  do {
    if (DEBUG_READINGS == 1) Serial.println((String)"[DEBUG] Selecting bus " + i);
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

void detectVCNLs() {
  Serial.println("[INFO] Autodetecting sensors....");
  addToLog("Autodetecting sensors....");
  for (int bus = 0; bus <= 7; bus++) {
    tcaselect(bus);
    int trynum = 1;
    while (! vcnl.begin() && trynum < TRIES) {
      if (DEBUG_READINGS == 1) Serial.println((String)"[DEBUG] Try " + trynum);
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
  addToLog((String)doorbells + " sensors found.");
  if (doorbells == 0) {
    errorMsg("Hardware error.\nNo VCNL sesnors found.\nContact support.");
  }
}
void calibrateVCNLs() {
  for (int bus = 0; bus < doorbells; bus++) {
    tcaselect(bus);
    Serial.print("[INFO] Calibrating proximity threshold on bus " + (String)bus + " ");
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

void checkButtons() {
  if (digitalRead(BTNAPIN)) {
    Serial.println("[INFO] Button A Pressed");
    showInfo();
    while (digitalRead(BTNAPIN)) {}
  }
  if (digitalRead(BTNBPIN)) {
    Serial.println("[INFO] Button B Pressed");
    while (digitalRead(BTNBPIN)) {}
  }
}

void scanVCNLs() {
  if (settingMode) return;
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
}
