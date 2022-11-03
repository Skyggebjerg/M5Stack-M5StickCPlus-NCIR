#include <Arduino.h>
#include "M5StickCPlus.h"
#include <Wire.h> // I2C library, required for MLX90614
#include <SparkFunMLX90614.h> //Click here to get the library: http://librarymanager/All#Qwiic_IR_Thermometer by SparkFun

IRTherm therm; // Create an IRTherm object to interact with throughout

void setup() 
{
    M5.begin();
    M5.Lcd.setRotation(3);
    M5.Lcd.setTextSize(3);

  Wire.begin(); //Joing I2C bus
  
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
    M5.Lcd.setCursor(2, 30);
    M5.Lcd.print("IR:  " + String(therm.object(), 2));
    M5.Lcd.setCursor(2, 70);
    M5.Lcd.print("Ref: " + String(therm.ambient(), 2));
  }
  delay(1000);
}