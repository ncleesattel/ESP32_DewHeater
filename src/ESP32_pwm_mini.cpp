// ======================================================================
// ESP32_pwm_mini DEFINITIONS
// Code for an astronomy dew controller
// (c) Copyright Norman Cleesattel
// DO NOT CHANGE
// ======================================================================

// ======================================================================
// INCLUDES DO NOT CHANGE
// ======================================================================
#include "defines.h"
#include "display.h"
#include "sensor.h"
#include "encoder.h"
#include "pwmchannels.h"
#include "ammeter.h"

// ======================================================================
// DEFINES AND VARIABLES
// ======================================================================
unsigned long currenttime, lowcounter, midcounter, highcounter, ultracounter;

// ======================================================================
// SETUP
// ======================================================================

void setup() {

  // opens serial port, sets data rate to 115200 bps
  Serial.begin(SERIALSPEED);

  // init the display
  init_display();
  init_sensor();
  init_encoder();
  init_pwm();
  init_ammeter();
}

// ======================================================================
// MAIN LOOP
// ======================================================================

void loop() {

  //Serial.print("Code is running on Core: ");Serial.println( xPortGetCoreID());
  static MachineStates machine_state = state_idle;

  currenttime = millis();

  if (currenttime > (ultracounter + ULTRAFREQ)) {
    machine_state = state_ultra;
    ultracounter = currenttime;
  }

  if (currenttime > (highcounter + HIGHFREQ)) {
    machine_state = state_high;
    highcounter = currenttime;
  }

  if (currenttime > (midcounter + MIDFREQ)) {
    machine_state = state_mid;
    midcounter = currenttime;
  }

  if (currenttime > (lowcounter + LOWFREQ)) {
    machine_state = state_low;
    lowcounter = currenttime;
  }

  switch (machine_state) {
    case state_low:
      read_sensor();  // read temperature probes [every second cycle]
      machine_state = state_idle;
      break;

    case state_mid:
      update_display();  // update display [every second cycle]
      update_pwm();      // update pwm [every second cycle]
      machine_state = state_idle;
      break;

    case state_high:
      read_ammeter();  // update amp [every second cycle]
      machine_state = state_idle;
      break;

    case state_ultra:
      read_encoder();  // update encoder [every second cycle]
      machine_state = state_idle;
      break;

    default:
      machine_state = state_idle;
      break;
  }
  //delay(2000);
}
