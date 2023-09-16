// ======================================================================
// ESP32_pwm_mini DEFINITIONS
// Code for an astronomy dew controller
// (c) Copyright Norman Cleesattel
// DO NOT CHANGE
// ======================================================================

// ======================================================================
// INCLUDES DO NOT CHANGE
// ======================================================================
#include <Arduino.h>

// ======================================================================
// EXTERNS DO NOT CHANGE
// ======================================================================
extern int counterA;
extern int counterB;

// ======================================================================
// DEFINES AND VARIABLES
// ======================================================================


// ======================================================================
// SETUP
// ======================================================================
void init_pwm()
{
  // configure PWM functionalitites
  ledcSetup(PWMCHANNELA, PWMFREQ, PWMRES);
  ledcSetup(PWMCHANNELB, PWMFREQ, PWMRES);

  // attach the channel to the GPIO to be controlled
  ledcAttachPin(CH1PWMPIN, PWMCHANNELA);
  ledcAttachPin(CH2PWMPIN, PWMCHANNELB);
  ledcAttachPin(CH3PWMPIN, PWMCHANNELB);

  delay(100);

}

// ======================================================================
// CODE
// ======================================================================
void update_pwm() {

  PWMPOWERA = counterA / 100. * PWMDUTYCYCLE;
  PWMPOWERB = counterB / 100. * PWMDUTYCYCLE;
  //Serial.println(PWMPOWER);
  //Serial.println(counter);
  // changing the power output with PWM
  ledcWrite(PWMCHANNELA, PWMPOWERA);
  ledcWrite(PWMCHANNELB, PWMPOWERB);

}