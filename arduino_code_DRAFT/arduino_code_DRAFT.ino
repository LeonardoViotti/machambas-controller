// Regador - v0

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

  // Open period
  Serial.println("Valve open");                  
  digitalWrite(solenoidPin, LOW);    //Switch Solenoid ON
  delay(2000);
  
  // Closed period
  Serial.println("Valve closed");                  
  digitalWrite(solenoidPin, HIGH);     //Switch Solenoid OFF
  delay(60000);  


}
