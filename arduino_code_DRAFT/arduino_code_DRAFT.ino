// Regador - v0

int solenoidPin = 4;   
 
void setup() {    
  pinMode(solenoidPin, OUTPUT);    
}
 
void loop() {
  digitalWrite(solenoidPin, HIGH);    //Switch Solenoid ON
  delay(1000);                        //Wait 1 Second
  digitalWrite(solenoidPin, LOW);     //Switch Solenoid OFF
  delay(1000);                        //Wait 1 Second
}
