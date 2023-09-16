// ======================================================================
// ESP32_pwm_mini DEFINITIONS
// Code for an astronomy dew controller
// (c) Copyright Norman Cleesattel
// DO NOT CHANGE
// ======================================================================

// ======================================================================
// INCLUDES - DO NOT CHANGE ANYTHING IN THIS SECTION
// ======================================================================
#include <Arduino.h>
#include <math.h>
#include <Adafruit_BME280.h>              // needed for BME280 sensor
#include <Adafruit_Sensor.h>
#include <DHT.h>                          // needed for DTH21 sensor
#include <DHT_U.h>                        // needed for DTH21 sensor

// ======================================================================
// CONDITIONAL DEFINES - DO NOT CHANGE ANYTHING IN THIS SECTION
// ======================================================================

// ======================================================================
// EXTERNS DO NOT CHANGE
// ======================================================================

// ======================================================================
// DEFINES AND VARIABLES
// ======================================================================
float tval1;                             // ambient temperature value
float pval1;                             // ambient pressure
float hval1;                             // relative humidity
float dewpoint;                          // dewpoint

float tval2;                             // ambient temperature value
float hval2;

Adafruit_BME280 bme;                          
#define DHTTYPE    DHT22     // the HTU21D sensor, returns 998 is sensor not detected and 999 if CRC is bad
DHT dht(CH1TEMPPIN, DHTTYPE);

// ======================================================================
// SETUP
// ======================================================================
void calc_dewpoint(float t, float h)
{
  float logEx;
  // calculates dew point
  // input:   humidity [%RH], temperature [°C]
  // output:  dew point [°C]
  logEx = 0.66077 + 7.5 * t / (237.3 + t) + (log10(h) - 2);
  dewpoint = (logEx - 0.66077) * 237.3 / (0.66077 + 7.5 - logEx);
}

void read_bme280_sensor()
{
  tval1 = bme.readTemperature() - 3.5;       // read the ambient temperature and offset by 3.5°
  pval1 = bme.readPressure() / 100.0;        // read the ambient pressure in hPa
  hval1 = bme.readHumidity();                // read the humidity, 998=timeout, 999=crc invalid

  //calc_dewpoint(tval1, hval1);    
}

void read_dht_sensor()
{
  tval2 = dht.readTemperature();       // read the ambient temperature
  hval2 = dht.readHumidity();          // read the humidity, 998=timeout, 999=crc invalid

  // check if valid temperature value is given
  if (isnan(tval2) || isnan(hval2)) {

  } else {
    calc_dewpoint(tval2, hval2);
  }      
  
}

void init_sensor()
{
  // check for BME280 sensor
  bme.begin();
  delay(250);                            // wait enough time for reset to end, should take 15ms
  dht.begin();
  delay(1000);                            // wait enough time for reset to end, should take 15ms

  read_bme280_sensor();                 // trigger humidity and ambient and calc dew_point
  read_dht_sensor();
}

// ======================================================================
// CODE
// ======================================================================
void read_sensor()
{
  read_dht_sensor();                 // read humidity and ambient and calc dew_point  
  read_bme280_sensor();
}



