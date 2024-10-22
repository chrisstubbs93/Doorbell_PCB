/**
    \file Hardware.ino
    Handles I2C multiplexer, connection to VCNL IR proximity sensors, proximity sensor related functions, initialisation of GPIO, scanning of buttons.
*/

//======================Variables for VCNL==============================
long average[] =   {0, 0, 0, 0, 0, 0, 0, 0}; //!< Array of average reading of all sensors.
long threshold[] = {0, 0, 0, 0, 0, 0, 0, 0}; //!< Array of threshold limits to trigger each sensor.
long reading[] =   {0, 0, 0, 0, 0, 0, 0, 0}; //!< Current reading of each sensor.

Adafruit_VCNL4010 vcnl; //!< Object for the VNCL sensor.

//======================Variables for sleep==============================
unsigned long lastPressed = 0; //!< Time in ms since boot that a sensor was last pressed. Used to determine when to enter sleep mode after inactivity.

/*! Initialise the GPIO pins. This should be run AFTER initialising the display so the MISO pin can be detached from the pin matrix and reused. */
void initGPIO() {
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

/*! Set the VCOM. This isn't normally needed unless the ePaper is particularly bad. */
void setVCOM(unsigned char d) {
  digitalWrite(4, LOW);
  digitalWrite(15, LOW);
  SPI.transfer(0x2C); //Write VCOM register
  digitalWrite(15, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(15, LOW);
  SPI.transfer(d);
  digitalWrite(15, HIGH);
}

/*! Selects which i2c sub-bus on the mux for a specific sensor to connect to and checks it, retrying if it's not correct. (input 0...7) */
void tcaselect(uint8_t i) { 
  if (i > 7) return;
  do {
    if (DEBUG_READINGS == 1) Serial.println((String)"[DEBUG] Selecting bus " + i);
    Wire.beginTransmission(TCAADDR);
    Wire.write(1 << i);
    Wire.endTransmission();
  } while (!(tcaget() == i));
}

/*! Check the current i2c sub-bus for a specific sensor. Output 0...7 */
int tcaget() { 
  Wire.requestFrom(TCAADDR, 1);
  byte c = Wire.read();
  for (int i = 0; i <= 7; i++) {
    if (c == 0x01) return i;
    c = c >> 1;
  }
}

/*! Attempt to initialise connected VCNL's one by one */
void detectVCNLs() {
  Serial.println("[INFO] Autodetecting sensors....");
  //addToLog("Autodetecting sensors....");
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
  //addToLog((String)doorbells + " sensors found.");
  if (doorbells == 0) {
    errorMsg("Hardware error.\nNo VCNL sesnors found.\nContact support.");
  }
}

/*! Calibrate VCNL threshold by averaging N_THRES_SAMPLES samples and multiplying by thres */
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

/*! Check if hardware buttons are pressed and run actions. */
void checkButtons() {
  if (digitalRead(BTNAPIN)) {
    lastPressed = millis(); //record the button was pressed for sleep mode
    Serial.println("[INFO] Button A Pressed");
    showInfo();
    while (digitalRead(BTNAPIN)) {}
  }
  if (digitalRead(BTNBPIN)) {
    lastPressed = millis(); //record the button was pressed for sleep mode
    Serial.println("[INFO] Button B Pressed");
    while (digitalRead(BTNBPIN)) {}
  }
}

/*! Determine if device should enter deep sleep for power saving. */
void manageSleep() {
  if (powerSave) {
    if (millis() - lastPressed > sleepDelay * 60000) {
      //go to sleep if no activity for x mins
      setupVCNLinterrupt(); //set up the VCNLs for interrupt
      sleeping = true; //set the sleeping flag
      writeNames(); //show the sleeping flag on screen
      entersleep(); //go to sleep
    }
  }
}

/*! Set up interrupts to wake device, then go to deep sleep for power saving. */
void entersleep() {
  Serial.println("[INFO] Entering sleep mode");
  esp_sleep_enable_ext0_wakeup(GPIO_NUM_32, 0); //interrupt on VCNL sum
  esp_sleep_enable_ext1_wakeup(INTERRUPTPINMASK, ESP_EXT1_WAKEUP_ANY_HIGH); //interrupt on A/B buttons
  esp_sleep_enable_timer_wakeup(1800 * 1000000); //interrupt every hour to update battery etc
  delay(500); //delay to finish setup before CPU halted
  esp_deep_sleep_start();
}

/*! Print the reason for wakeup to the serial port. */
void wakeup_reason() {
  esp_sleep_wakeup_cause_t wakeup_reason;
  wakeup_reason = esp_sleep_get_wakeup_cause();
  switch (wakeup_reason)
  {
    case 1  : Serial.println("[INFO] Wakeup caused by external signal using RTC_IO"); break; //EXT0 - VCNL
    case 2  : Serial.println("[INFO] Wakeup caused by external signal using RTC_CNTL"); break; //EXT1 - A/B
    case 3  : Serial.println("[INFO] Wakeup caused by timer"); break;
    case 4  : Serial.println("[INFO] Wakeup caused by touchpad"); break;
    case 5  : Serial.println("[INFO] Wakeup caused by ULP program"); break;
    default : Serial.println("[INFO] Wakeup was not caused by deep sleep"); break;
  }
}

/*! Determine type of boot mode. 1 = sensor interrupt, 2 = button interrupt, 3 = periodic timer wakeup, 6 = normal startup. */
int bootmode() {
  esp_sleep_wakeup_cause_t wakeup_reason;
  wakeup_reason = esp_sleep_get_wakeup_cause();
  if (wakeup_reason > 5 or wakeup_reason < 1){
    return 6;
  } else {
    return wakeup_reason;
  }
}

/*! Take reading from each sensor. Notify lecturer if above threshold. */
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

/*! Set up interrupt on each device when threshold exceeded. (allows detection of touch interaction when CPU asleep). */
void setupVCNLinterrupt() {
  //once the interrupt is set up, the proximity must only be read using background measurement
  for (int bus = 0; bus < doorbells; bus++) {
    tcaselect(bus);
    Serial.println("[INFO] Setting interrupt on bus " + (String)bus + " ");
    vcnl.setLEDcurrent(LEDCURR); //Set IR LED on to take measurement
    delay(10); //small delay to allow IR LED to stabilise
    vcnl.write8(0x89, 0x02); //set up interrupt type
    //set low thres to 0
    vcnl.write8(0x8A, 0x00);
    vcnl.write8(0x8B, 0x00);
    //set high thres to value from array
    vcnl.write8(0x8C, highByte(threshold[bus]));
    vcnl.write8(0x8D, lowByte(threshold[bus]));
    //run continuous measurements
    vcnl.write8(0x80, 0x03);
  }
}

/*! Take a proximity reading without disturbing the interrupt setup. */
uint16_t getBackgroundProximity() {
  vcnl.setLEDcurrent(LEDCURR); //Set IR LED on to take measurement
  delay(10); //small delay to allow IR LED to stabilise
  vcnl.write8(0x80, 0x03); //run continuous measurements
  uint16_t p = vcnl.read8(0x87);
  p = p << 8;
  p = p + vcnl.read8(0x88);
  return p;
}

/*! Determine which sensor caused a hardware interrupt. */
int interruptSource() {
  for (int bus = 0; bus < doorbells; bus++) {
    tcaselect(bus);
    //Serial.print((String)"Device " + bus + " has an interrupt register with contents "); Serial.println(vcnl.read8(0x8E),HEX);
    if (vcnl.read8(0x8E) & 0x01) { //check interrupt register on VCNL
      return bus;
    }
  }
  return 0;
}
