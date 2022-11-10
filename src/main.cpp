#include <Arduino.h>
#include "M5StickCPlus.h"
#include <Wire.h> // I2C library, required for MLX90614
#include <SparkFunMLX90614.h> //Click here to get the library: http://librarymanager/All#Qwiic_IR_Thermometer by SparkFun
#include "7seg70.h"
#include "7seg20.h"

IRTherm therm; // Create an IRTherm object to interact with throughout

void setup() 
{
    M5.begin();
    M5.Lcd.setRotation(3);
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setSwapBytes(true);
    //M5.Lcd.setTextSize(4);

  Wire.begin(0, 26); //Joing I2C bus Wire.begin(0,26) is for the NCIR Hat
  
  if (therm.begin() == false){ // Initialize thermal IR sensor
    // Serial.println("Qwiic IR thermometer did not acknowledge! Freezing!");
    while(1);
  }
  // Serial.println("Qwiic IR Thermometer did acknowledge.");
  
  therm.setUnit(TEMP_C); // Set the library's units to Farenheit
  // Alternatively, TEMP_F can be replaced with TEMP_C for Celsius or
  // TEMP_K for Kelvin.
}

void loop() 
{
  // Call therm.read() to read object and ambient temperatures from the sensor.
  if (therm.read()) // On success, read() will return 1, on fail 0.
  {
    // Use the object() and ambient() functions to grab the object and ambient
	// temperatures.
	// They'll be floats, calculated out to the unit you set with setUnit().
    M5.Lcd.setFreeFont(&DSEG7_Classic_Regular_64);
    M5.Lcd.setTextColor(TFT_WHITE, TFT_BLACK);
    //M5.Lcd.setTextSize(4);
    //M5.Lcd.setCursor(0, 70);
    M5.Lcd.drawString(String(therm.object(), 1),30,15);
    //M5.Lcd.print(String(therm.object(), 1));
    //M5.Lcd.setTextSize(3);
    M5.Lcd.setFreeFont(&DSEG7_Classic_Bold_30);
    M5.Lcd.setTextColor(YELLOW, TFT_BLACK);
    //M5.Lcd.setCursor(0, 130);
    M5.Lcd.drawString(String(therm.ambient(), 1),140,100);
    //M5.Lcd.print(String(therm.ambient(), 1));
  }
  delay(1000);
}