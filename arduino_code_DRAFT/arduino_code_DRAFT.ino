
// Pin set up
int solenoidPin1 = 4;    //Select utput pin
int solenoidPin2 = 2;    //Select utput pin

void setup() {
  //Set up pins
  pinMode(solenoidPin1, OUTPUT);
  pinMode(solenoidPin2, OUTPUT);

  // Set up print
  Serial.begin(9600); // Print setup
  Serial.println("Controller start!"); 
}

void loop() {
  // Wait before first open                 
  digitalWrite(solenoidPin1, HIGH);  
  delay(30000); //30s

  // Open period
  Serial.println("Valve open");                  
  digitalWrite(solenoidPin1, LOW);    //Switch Solenoid ON
  delay(2500); // 2.5s
  
  // Closed period
  Serial.println("Valve closed");                  
  digitalWrite(solenoidPin1, HIGH);     //Switch Solenoid OFF
  delay(43200000); // 12h

}
