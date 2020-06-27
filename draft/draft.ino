/* 
  MACHAMBAS IRRIGATION CONTROLLER
  
  Hardware:
    - Arduino Uno
    - SainSmart 2 channel relay module
    - RTC DS3231 AT24C32 IIC module (under development)

  Usefull links and references
    - https://randomnerdtutorials.com/guide-for-relay-module-with-arduino/

 */

//-------------------------------------------------------------------------
// IMPORT MODULES

#include "RTClib.h"
RTC_DS3231 rtc;

//-------------------------------------------------------------------------
// GLOBALS
int pump1_open_t = 2500;
int pump2_open_t = 5000;

// Pin set up
int solenoidPin1 = 4;    //Pump 1 in relay-IN1
int solenoidPin2 = 2;    //Pump 2 in relay-IN2
// Relay GND - Arduino GND
// Relay VCC - Arduino 5V

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
  if(now.hour() == 14 && now.minute() == 40 ){
        
    // Open period 1
    Serial.println("Pump 1 open");
    digitalWrite(solenoidPin1, LOW);
    delay(pump1_open_t); // 2.5s
  
    // Closed period 1
    Serial.println("Pump 1 closed");
    digitalWrite(solenoidPin1, HIGH);    
    // Add delay here for safety
    delay(10000);
  
    // Open period 2
    Serial.println("Pump 2 open");                  
    digitalWrite(solenoidPin2, LOW);
    delay(pump2_open_t); // 2.5s
  
    // Closed period 2
    Serial.println("Pump 2 closed");                  
    digitalWrite(solenoidPin2, HIGH);
    
    // Delay 1 minute so cycle only happens once per day
    delay(60000);

  }



    
}
