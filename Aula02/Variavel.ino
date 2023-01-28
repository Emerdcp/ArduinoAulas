// Variáveis
int ledVermelho = 13;
int ledVerde = 12;
int tempo = 0;
  
void setup()
{
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledVerde, OUTPUT);
}

void loop()
{
  tempo = tempo + 10;
  digitalWrite(ledVermelho, 1);
  delay(tempo);
  digitalWrite(ledVermelho, 0);
  delay(tempo);çç
  
  digitalWrite(ledVerde, 1);
  delay(tempo);
  digitalWrite(ledVerde, 0);
  delay(tempo);
}