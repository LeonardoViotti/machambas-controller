// Regador - v0

// Global variables
int timeOpen = 2000; // 2 second
int timeClosed = 60000; // 1 minute


// Pin set up
int solenoidPin = 13;    //This is the output pin on the Arduino we are using
 
 
void setup() {    
  pinMode(solenoidPin, OUTPUT);    
}
 
void loop() {                 
  
  digitalWrite(solenoidPin, LOW);    //Switch Solenoid ON
  delay(timeOpen);  
                    
  digitalWrite(solenoidPin, HIGH);     //Switch Solenoid OFF
  delay(timeClosed);  

}
