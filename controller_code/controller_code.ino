/* 
  MACHAMBAS IRRIGATION CONTROLLER
 */

// GLOBALS
int pump1_open_t = 2500;
int pump2_open_t = 5000;
int irr_interval_t = 30000;
//int irr_interval_t = 43200000;


// Pin set up
int solenoidPin1 = 4;    //Pump 1 in relay-IN1
int solenoidPin2 = 2;    //Pump 2 in relay-IN2
// Relay GND - Arduino GND
// Relay VCC - Arduino 5V

void setup() {
  //Set up pins
  pinMode(solenoidPin1, OUTPUT);
  pinMode(solenoidPin2, OUTPUT);

  // Set up print
  Serial.begin(9600); // Print setup
  Serial.println("Controller start!"); 
}

void loop() {
  // Set both pins to high (relay closed) and wait before first open.                 
  digitalWrite(solenoidPin1, HIGH);  
  digitalWrite(solenoidPin2, HIGH);  
  delay(10000); //10s

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

  // Closed period for both pumps
  delay(irr_interval_t); // 30s
  //delay(43200000); // 12h
 
}
