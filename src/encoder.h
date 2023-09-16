// ======================================================================
// ESP32_pwm_mini DEFINITIONS
// Code for an astronomy dew controller
// (c) Copyright Norman Cleesattel
// DO NOT CHANGE
// ======================================================================

// ======================================================================
// INCLUDES DO NOT CHANGE
// ======================================================================


// ======================================================================
// DEFINES AND VARIABLES
// ======================================================================
int lim_volt = 500;             // voltage threshold be interpreted as 1
int counterA = 50;
int counterB = 50;

int currentStateCLKA;
int currentStateCLKB;
static int lastStateCLKA;
static int lastStateCLKB;

int currentStateCLK_aA;
int currentStateCLK_aB;
static int lastStateCLK_aA;
static int lastStateCLK_aB;

int currentStateDT_aA;
int currentStateDT_aB;
int currentStateDTA;
int currentStateDTB;

String currentDirA = "";
String currentDirB = "";
unsigned long lastButtonPressA = 0;
unsigned long lastButtonPressB = 0;

int count = 0;


// ======================================================================
// SETUP
// ======================================================================
void init_encoder() {
  // Set encoder pins as inputs
  pinMode(RA_CLK, INPUT);
  pinMode(RA_DT, INPUT);
  pinMode(RA_SW, INPUT_PULLUP);

  pinMode(RB_CLK, INPUT);
  pinMode(RB_DT, INPUT);
  pinMode(RB_SW, INPUT_PULLUP);

  // Read the initial state of CLK
  lastStateCLK_aA = analogRead(RA_CLK);
  if (lastStateCLK_aA < lim_volt) {
    lastStateCLKA = 0;
  } else {
    lastStateCLKA = 1;
  }

  // Read the initial state of CLK
  lastStateCLK_aB = analogRead(RB_CLK);
  if (lastStateCLK_aB < lim_volt) {
    lastStateCLKB = 0;
  } else {
    lastStateCLKB = 1;
  }
  delay(1000);
}

// ======================================================================
// CODE
// ======================================================================
void read_encoder() {


  // Read the current state of CLK
  currentStateCLK_aA = analogRead(RA_CLK);
  if (currentStateCLK_aA < lim_volt) {
    currentStateCLKA = 0;
  } else {
    currentStateCLKA = 1;
  }

  currentStateDT_aA = analogRead(RA_DT);
  if (currentStateDT_aA < lim_volt) {
    currentStateDTA = 0;
  } else {
    currentStateDTA = 1;
  }

  // If last and current state of CLK are different, then pulse occurred
  // React to only 1 state change to avoid double count
  if (currentStateCLKA != lastStateCLKA && currentStateCLKA == 1) {

    // If the DT state is different than the CLK state then
    // the encoder is rotating CCW so decrement
    if (currentStateDTA != currentStateCLKA) {
      if (counterA > 0) {
        counterA -= 10;
      }
      currentDirA = "CCW";
    } else {
      // Encoder is rotating CW so increment
      if (counterA < 100) {
        counterA += 10;
      }
      currentDirA = "CW";
    }

    //Serial.print("Direction: ");
    //Serial.print(currentDirA);
    //Serial.print(" | Counter: ");
    //Serial.println(counterA);
  }

  // Remember last CLK state
  lastStateCLKA = currentStateCLKA;

  // Read the current state of CLK
  currentStateCLK_aB = analogRead(RB_CLK);
  if (currentStateCLK_aB < lim_volt) {
    currentStateCLKB = 0;
  } else {
    currentStateCLKB = 1;
  }

  currentStateDT_aB = analogRead(RB_DT);
  if (currentStateDT_aB < lim_volt) {
    currentStateDTB = 0;
  } else {
    currentStateDTB = 1;
  }

  // If last and current state of CLK are different, then pulse occurred
  // React to only 1 state change to avoid double count
  if (currentStateCLKB != lastStateCLKB && currentStateCLKB == 1) {

    // If the DT state is different than the CLK state then
    // the encoder is rotating CCW so decrement
    if (currentStateDTB != currentStateCLKB) {
      if (counterB > 0) {
        counterB -= 10;
      }
      currentDirB = "CCW";
    } else {
      // Encoder is rotating CW so increment
      if (counterB < 100) {
        counterB += 10;
      }
      currentDirB = "CW";
    }

    //Serial.print("Direction: ");
    //Serial.print(currentDirB);
    //Serial.print(" | Counter: ");
    //Serial.println(counterB);
  }

  // Remember last CLK state
  lastStateCLKB = currentStateCLKB;


  //delay(1);
}