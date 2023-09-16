// ======================================================================
// ESP32_pwm_mini DEFINITIONS
// Code for an astronomy dew controller
// (c) Copyright Norman Cleesattel
// May need to adapt to your hardware
// ======================================================================

#include <Arduino.h>

// ======================================================================
// GLOBAL DEFINES
// ======================================================================
#define SERIALSPEED                 57600

// ======================================================================
// PWM DEFINITIONS
// ======================================================================
const int PWMCHANNELA   = 0;
const int PWMCHANNELB   = 1;
const int PWMFREQ      = 71993;
const int PWMRES       = 8;
const int PWMDUTYCYCLE = 255;
float PWMPOWERA;
float PWMPOWERB;

// ======================================================================
// StateMachine definitions
// ======================================================================
const int LOWFREQ = 3000;   // frequency of main updates in ms
const int MIDFREQ = 400;     // frequency of encoder updates in ms
const int HIGHFREQ = 10;     // frequency of encoder updates in ms
const int ULTRAFREQ = 1;     // frequency of encoder updates in ms
enum MachineStates { state_idle, state_low, state_mid, state_high, state_ultra};
  
// ======================================================================
// HARDWARE MAPPINGS
// ======================================================================

#define SDAPIN                      21                  // SDA
#define SCLPIN                      22                  // SCL

//PWM PINS
const int CH1PWMPIN = 25;  // corresponds to GPIO25
const int CH2PWMPIN = 33;  // corresponds to GPIO33
const int CH3PWMPIN = 32;  // corresponds to GPIO32

//CURRENT MEASUREMENT
const int CH1AMPPIN = 26;  // corresponds to GPIO26
const int CH2AMPPIN = 27;  // corresponds to GPIO27
const int CH3AMPPIN = 14;  // corresponds to GPIO14

//VOLTAGE MEASUREMENT
const int VOLTPIN = 13;  // corresponds to GPIO13

//TEMPERATURE MEASUREMENTS
const int CH1TEMPPIN = 19;  // corresponds to GPIO19
const int CH2TEMPPIN = 18;  // corresponds to GPIO18

//ROTARY ENCODER INPUTS
const int RB_CLK = 39;  // corresponds to GPIO39
const int RB_DT  = 36;  // corresponds to GPIO36
const int RB_SW  = 16;  // corresponds to GPIO16

const int RA_CLK = 34;  // corresponds to GPIO35
const int RA_DT  = 35;  // corresponds to GPIO34
const int RA_SW  = 17;  // corresponds to GPIO17

