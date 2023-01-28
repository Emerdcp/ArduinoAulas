/* Piscar um Led personalizado
*/
void setup()
{
  pinMode(13, OUTPUT);
  pinMode(05, OUTPUT);
}

void loop()
{
  //Piscar led vermelho
  digitalWrite(13, 1);//pode colocar "HIGH ou 1 para acender" ou "LOW ou 0 para pagar"
  delay(1000);
  digitalWrite(13, 0);
  delay(1000);
  
  //piscar led azul
  digitalWrite(05, 1);
  delay(1000);
  digitalWrite(05, 0);
  delay(1000);
  
  //piscar led verde
  digitalWrite(04, 1);
  delay(1000);
  digitalWrite(04, 0);
  delay(1000);
}