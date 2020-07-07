/* 
  MACHAMBAS IRRIGATION CONTROLLER
  
  Hardware:
    - Arduino Uno
    - SainSmart 2 channel relay module
    - RTC DS3231 AT24C32 IIC module

  Usefull links and references
    - https://randomnerdtutorials.com/guide-for-relay-module-with-arduino/

 */

//-------------------------------------------------------------------------
// IMPORT MODULES

#include "RTClib.h"
RTC_DS3231 rtc;

//-------------------------------------------------------------------------
// GLOBALS

// Watering cycle time
int cycle_hour = 17;
int cycle_minute = 28;

// Watering cycle size
int pump1_open_t = 2500;
int pump2_open_t = 5000;

// Pin set up
int solenoidPin1 = 4;    //Pump 1 in relay-IN1
int solenoidPin2 = 2;    //Pump 2 in relay-IN2
// Relay GND - Arduino GND
// Relay VCC - Arduino 5V
// RTC SDA - Arduino SDA
// RTC SCL - Arduino SCL
// RTC GND - Arduino GND
// RTC VCC - Arduino 5V

//-------------------------------------------------------------------------
void setup() {
  //Set up pins
  pinMode(solenoidPin1, OUTPUT);
  pinMode(solenoidPin2, OUTPUT);  
  
  // Set baud rate
  Serial.begin(9600); // Print setup
  Serial.println("Controller start!");  
  
  // Test if rtc module is working
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  // If needed to set the time of the uncomment lines below and
  // upload the code once. After that, comment the line again
  // and if RTC module has power it will keep the correct time.
  // January 21, 2014 at 3am you would call:
  // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));

  //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  //rtc.adjust(DateTime(2020, 7, 1, 19, 10, 0));



}

//-------------------------------------------------------------------------
void loop() {
  
  //-----------------------------------------------------------------------
  // Set both pins to high (relay closed) and wait before first open.                 
  digitalWrite(solenoidPin1, HIGH);  
  digitalWrite(solenoidPin2, HIGH);  

  //-----------------------------------------------------------------------
  // Time setup 
  DateTime now = rtc.now();

  //-----------------------------------------------------------------------
  // Irrigation cycle interval
  //  This sets a period of one minute in the day when the cycle can happen. 
  if(now.hour() == cycle_hour && now.minute() == cycle_minute ){
    IrrigationCycle(pump1_open_t, pump2_open_t);  
  
    // Delay 1 minute so cycle only happens once per day
    delay(60000);
  }

  //-----------------------------------------------------------------------
  // Print date, time and temperature.
  PrintTimeTemp(now);

}

//-------------------------------------------------------------------------
// FUNCTIONS DEFINITION

void IrrigationCycle(int pump1_t, int pump2_t) {
      // Open period 1
    Serial.println("Pump 1 open");
    digitalWrite(solenoidPin1, LOW);
    delay(pump1_t);
  
    // Close 1
    Serial.println("Pump 1 closed");
    digitalWrite(solenoidPin1, HIGH);
        
    // Add a delay between pumps for safety
    delay(10000);
  
    // Open period 2
    Serial.println("Pump 2 open");                  
    digitalWrite(solenoidPin2, LOW);
    delay(pump2_t);
  
    // Close 2
    Serial.println("Pump 2 closed");                  
    digitalWrite(solenoidPin2, HIGH);

}


void PrintTimeTemp(DateTime now) {
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(' ');

    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(' ');
    
    Serial.print("Temperature: ");
    Serial.print(rtc.getTemperature());
    Serial.println(" C");

    Serial.println();
}
