// Funções
#define ledVermelho 13
#define ledAmarelo 12
#define ledVerde 11
int tempo = 500;

void setup()
{
  pinMode(ledVermelho, OUTPUT);image.pngimage.png
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
}

void loop()
{
  controleVermelho();//Chamando a função
  controleAmarelo();
  controleVerde();
}

//Criando um função
void controleVermelho()
{
  digitalWrite(ledVermelho, 1);
  delay(tempo);
  digitalWrite(ledVermelho, 0);
  delay(tempo);
}

void controleAmarelo()
{
  digitalWrite(ledAmarelo, 1);
  delay(tempo);
  digitalWrite(ledAmarelo, 0);
  delay(tempo);
}
  
void controleVerde()
{
  digitalWrite(ledVerde, 1);
  delay(tempo);
  digitalWrite(ledVerde, 0);
  delay(tempo);
}