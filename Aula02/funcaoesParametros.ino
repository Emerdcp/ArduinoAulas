// Funções Parametros
#define ledVermelho 13
#define ledAmarelo 12
#define ledVerde 11
int tempo = 500;

void setup()
{
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
}

void loop()//Chamando a Função
{
  controleLed(ledVermelho);
  controleLed(ledAmarelo);
  controleLed(ledVerde);
  controleLed(ledAmarelo);
}

//Criando um função
void controleLed(int led)
{
  digitalWrite(led, 1);
  delay(tempo);
  digitalWrite(led, 0);
  delay(tempo);
}


/*
outra maneira para priorizar o tempo

void loop()//Chamando a Função
{
  controleLed(ledVermelho, 100);
  controleLed(ledAmarelo, 200);
  controleLed(ledVerde, 500);
}

//Criando um função
void controleLed(int led, int tempoPersonalizado)
{
  digitalWrite(led, 1);
  delay(tempoPersonalizado);
  digitalWrite(led, 0);
  delay(tempoPersonalizado);
}

*/