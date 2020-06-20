// Regador - v0

<<<<<<< Updated upstream
// Run this on terminal on linux to change porte writing rights
// ls -l /dev/ttyACM*
// sudo chmod a+rw /dev/ttyACM0

// Global variables
//int timeOpen = 2000; // 2 second
//int timeClosed = 6000; // 1 minute
=======
// Pin set up
int solenoidPin1 = 4;    //Pump 1 in relay-IN1
int solenoidPin2 = 2;    //Pump 2 in relay-IN2
// Relay GND - Arduino GND
// Relay VCC - Arduino 5V
>>>>>>> Stashed changes


// Pin set up
int solenoidPin = 4;    //Select utput pin
 
void setup() {    
  pinMode(solenoidPin, OUTPUT);
  Serial.begin(9600); // Print setup

  Serial.println("Controller start!");                  

} 
 
void loop() {
<<<<<<< Updated upstream
  
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


=======
  // Set both pins to high (relay closed) and wait before first open.                 
  digitalWrite(solenoidPin1, HIGH);  
  digitalWrite(solenoidPin2, HIGH);  
  delay(30000); //30s

  // Open period 1
  Serial.println("Pump 1 open");
  digitalWrite(solenoidPin1, LOW);
  delay(2500); // 2.5s
  
  // Closed period 1
  Serial.println("Pump 1 closed");
  digitalWrite(solenoidPin1, HIGH);    

  // Add delay here for safety
  delay(10000);
  
  // Open period 2
  Serial.println("Pump 2 open");                  
  digitalWrite(solenoidPin2, LOW);
  delay(2500); // 2.5s
  
  // Closed period 2
  Serial.println("Pump 2 closed");                  
  digitalWrite(solenoidPin2, HIGH);

  // Closed period for both pumps
  delay(30000); // 30s
  //delay(43200000); // 12h
 
>>>>>>> Stashed changes
}
