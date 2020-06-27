#include "RTClib.h"


// Pin set up
// RTC SDA - Arduino SDA
// RTC SCL - Arduino SCL
// RTC GND - Arduino GND
// RTC VCC - Arduino 5V


RTC_DS3231 rtc;


void setup() {  

  Serial.begin(9600); // Set baud rate

  delay(3000); // Wait for console opening

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

  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  rtc.adjust(DateTime(2020, 6, 27, 16, 0, 0));


}

void loop() {

    DateTime now = rtc.now();
  

    // Print date, time and temperature.
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
    delay(3000);

}
