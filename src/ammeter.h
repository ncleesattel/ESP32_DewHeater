// ======================================================================
// ESP32_pwm_mini DEFINITIONS
// Code for an astronomy dew controller
// (c) Copyright Norman Cleesattel
// DO NOT CHANGE
// ======================================================================

// ======================================================================
// INCLUDES - DO NOT CHANGE ANYTHING IN THIS SECTION
// ======================================================================

// ======================================================================
// DEFINES AND VARIABLES
// ======================================================================
float sig_a1, sig_a2, sig_a3;             // signal of FET1, 2, 3
float sig_v1;                             // voltage of FET1

float amp1, amp2, amp3;                   // amp of FET1, 2, 3
float volt;                              // volt of FETs

float av_volt=0.;
float max_amp1=0;
float max_amp2=0;
float max_amp3=0;
int i=1;
int ii=1;

// ======================================================================
// SETUP
// ======================================================================
void init_ammeter()
{
  pinMode(CH1AMPPIN, INPUT);
  pinMode(CH2AMPPIN, INPUT);
  pinMode(CH3AMPPIN, INPUT);
  pinMode(VOLTPIN, INPUT);
}

void calc_amps(float a1, float a2, float a3, float v1)
{
  amp1 = (((a1 / 4096. * 5.) - 2.5) * 2.5) * 0.7414;
  amp2 = (((a2 / 4096. * 5.) - 2.5) * 2.5) * 0.7414;
  amp3 = (((a3 / 4096. * 5.) - 2.5) * 2.5) * 0.7414;
  volt = v1 / 4096. * 27.76;

  if(i <= 2000){
    if(amp1 > max_amp1){
        max_amp1 = amp1;
      }
    if(amp2 > max_amp2){
        max_amp2 = amp2;
      }
    if(amp3 > max_amp3){
        max_amp3 = amp3;
      }
    i++;
  }else{
    max_amp1 = 0.;
    max_amp2 = 0.;
    max_amp3 = 0.;
    i = 1;
  }

  av_volt = av_volt + ((-av_volt + volt) / 100.);

}

// ======================================================================
// CODE
// ======================================================================
void read_ammeter()
{
  sig_a1 = analogRead(CH1AMPPIN);
  //Serial.println(sig_a1);
  sig_a2 = analogRead(CH2AMPPIN);
  sig_a3 = analogRead(CH3AMPPIN);
  sig_v1 = analogRead(VOLTPIN);
  calc_amps(sig_a1, sig_a2, sig_a3, sig_v1);
}


