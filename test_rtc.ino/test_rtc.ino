// Date and time functions using a DS3231 RTC connected via I2C and Wire lib
#include "RTClib.h"

RTC_DS3231 rtc;


void setup() {  

  Serial.begin(9600); // Set baud rate

  delay(3000); // Wait for console opening

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

}

void loop() {

DateTime now = rtc.now();

    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');

    Serial.print("Temperature: ");
    Serial.print(rtc.getTemperature());
    Serial.println(" C");

    Serial.println();
    delay(3000);

}
