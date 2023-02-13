const byte Led = D1;       //D1 - GPIO05 - usar uma saído GND
                          
void setup() {
  pinMode(Led, OUTPUT);
}

void loop() {
  digitalWrite(Led, LOW);
  delay(1000);            
  digitaWrite(Led, HIGH);
  delay(1000);            
}