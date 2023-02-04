//Controle de Sinaleiro, controle de led para aceder e fazer a contagem em 10, e retornar

#define ledVermelho 4
#define ledVerde 2
#define ledAmarelo 3

int led_verde = 11;
String comando = "Vamos acender um led";
int numero = 0;

void setup() {
  pinMode(led_verde,OUTPUT);
  Serial.begin(9600);
  Serial.println(comando);
  Serial.println("Vai comercar");

  pinMode(ledVermelho,OUTPUT);
  pinMode(ledVerde,OUTPUT);
  pinMode(ledAmarelo,OUTPUT);


}

void loop() {
  digitalWrite(led_verde,1);
  Serial.println("Led Aceso");
  delay(300);
  digitalWrite(led_verde, 0);
  Serial.println("Led Apagado");
  delay(300);
  numero = numero + 1;
  Serial.println(numero);
  if(numero == 10){
    digitalWrite(led_verde,1);
    delay(3000);
    numero = 0;
  }

  //controleVermelho();
  //controleVerde();
  //controleAmarelo();
}

void controleVermelho()
{
  digitalWrite(ledVermelho,1);
  delay(1000);
  digitalWrite(ledVermelho,0);
  delay(100);
}

void controleVerde()
{
  digitalWrite(ledVerde,1);
  delay(1000);
  digitalWrite(ledVerde,0);
  delay(100);
}

void controleAmarelo()
{
  digitalWrite(ledAmarelo,1);
  delay(1000);
  digitalWrite(ledAmarelo,0);
  delay(100);
}