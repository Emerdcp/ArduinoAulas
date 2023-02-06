const byte Led = 2;       //Led 2 ou 16 para piscar led, usado para comunicação.
                          //D0 - GPIO16 / D2 - GPIO02
void setup() {
  pinMode(Led, OUTPUT);
}

void loop() {
  digitalWrite(Led, LOW); //liga o Led
  delay(1000);            //espera 1 segundo
  digitaWrite(Led, HIGH); //liga o led
  delay(1000);            //espera 1 segundo
}