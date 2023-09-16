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
#include "U8x8lib.h"   //Library for Text Display
#include <Wire.h>      //Library for I2C interface

// DIYMORE OLED Display used
U8X8_SSD1309_128X64_NONAME0_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE);

// ======================================================================
// EXTERNS DO NOT CHANGE
// ======================================================================
extern float tval1;     // Temperature value of 1st sensor
extern float pval1;     // Pressure value of 1st sensor
extern float hval1;     // Humidity value of 1st sensor

extern float tval2;     // Temperature value of 2nd sensor
extern float hval2;     // Humidity value of 2nd sensor

extern float dewpoint;     // Dewpoint calculation
extern int counterA;
extern int counterB;

extern float max_amp1;
extern float max_amp2;
extern float max_amp3;
extern float amp1;
extern float amp2;
extern float amp3;
extern float av_volt;

// ======================================================================
// DEFINES AND VARIABLES
// ======================================================================
char tChar[4];     // Temperature as character array
char dChar[4];     // Dewpoint as character array
char aChar[4];     // Ampage as character array
char vChar[4];     // Voltage as character array

float sum_amp;
int temp;

// ======================================================================
// SETUP
// ======================================================================
void init_display()
{

  u8x8.begin();
  delay(1000); 

}

// ======================================================================
// CODE
// ======================================================================
void update_display() {

  String line11, line12, line21, line22, line31, line32, line41, line42, line51, line52, line61, line62, line71, line72;
  line11 = String("T: ");
  line21 = String("T: ");
  line12 = String("H: ");
  line22 = String("H: ");

  line31 = String("D: ");
  line32 = String("P: ");

  line41 = String("%: ");
  line51 = String("W: ");
  line61 = String("A: ");
  line71 = String("V: ");  

  line42 = String("%: ");
  line52 = String("W: ");
  line62 = String("A: ");
  //line62 = String("V: ");  
  
  //convert value to char with 2 digits and 1 decimal
  dtostrf(tval1, 2, 1, tChar);
  line11 += tChar;
  dtostrf(tval2, 2, 1, tChar);
  line21 += tChar;

  //add space if value needs it
  if(hval1 < 100){
    line12 += " ";
  }
  line12 += int(hval1);

  //add space if value needs it
  if(hval2 < 100){
    line22 += " ";
  }
  line22 += int(hval2);
  line22 += "  ";

  //convert value to char with 2 digits and 1 decimal
  dtostrf(dewpoint, 2, 1, dChar);
  line31 += dChar;

  //add space if value needs it
  if(pval1 < 1000){
    line32 += " ";
  }
  line32 += int(pval1);


  //add space if value needs it
  if(counterA < 100){
    line41 += " ";
  }
  if(counterA < 10){
    line41 += " ";
  }
  line41 += int(counterA);

  //add space if value needs it
  if(counterB < 100){
    line42 += " ";
  }
  if(counterB < 10){
    line42 += " ";
  }
  line42 += int(counterB);

  //add space if value needs it
  temp = int(max_amp1 * av_volt * counterA / 100.);
  if(temp < 10){
    line51 += " ";
  }
  line51 += temp;

  //add space if value needs it
  sum_amp = max_amp2 + max_amp3;
  temp = int(sum_amp * av_volt * counterB / 100.);
  if(temp < 10){
    line52 += " ";
  }
  line52 += temp;


  dtostrf(max_amp1, 2, 1, aChar);
  line61 += aChar;

  dtostrf(sum_amp, 2, 1, aChar);
  line62 += aChar;

  dtostrf(av_volt, 2, 1, vChar);
  line71 += vChar;
  
  u8x8.setFont(u8x8_font_artossans8_r);  // select font for display
  u8x8.drawString(0,0,line11.c_str());   // write line 1
  u8x8.drawString(0,1,line21.c_str());   // write line 2
  u8x8.drawString(0,2,line31.c_str());   // write line 3
  u8x8.drawString(0,4,line41.c_str());   // write line 5
  u8x8.drawString(0,5,line51.c_str());   // write line 6
  u8x8.drawString(0,6,line61.c_str());   // write line 7
  u8x8.drawString(0,7,line71.c_str());   // write line 8

  u8x8.drawString(8,0,line12.c_str());   // write line 1
  u8x8.drawString(8,1,line22.c_str());   // write line 2
  u8x8.drawString(8,2,line32.c_str());   // write line 3
  u8x8.drawString(8,4,line42.c_str());   // write line 5
  u8x8.drawString(8,5,line52.c_str());   // write line 6
  u8x8.drawString(8,6,line62.c_str());   // write line 7
  //delay(1000); 

}