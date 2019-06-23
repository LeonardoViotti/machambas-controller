// Regador - v0

// Run this on terminal on linux to change porte writing rights
// ls -l /dev/ttyACM*
// sudo chmod a+rw /dev/ttyACM0

// Global variables
//int timeOpen = 2000; // 2 second
//int timeClosed = 6000; // 1 minute


// Pin set up
int solenoidPin = 4;    //Select utput pin
 
void setup() {    
  pinMode(solenoidPin, OUTPUT);
  Serial.begin(9600); // Print setup

  Serial.println("Controller start!");                  

} 
 
void loop() {
  
  // Wait before first open                 
  digitalWrite(solenoidPin, HIGH);  
  delay(30000); //30s

  // Open period
  Serial.println("Valve open");                  
  digitalWrite(solenoidPin, LOW);    //Switch Solenoid ON
  delay(2500); // 2.5s
  
  // Closed period
  Serial.println("Valve closed");                  
  digitalWrite(solenoidPin, HIGH);     //Switch Solenoid OFF
  delay(43200000); // 12h


}
