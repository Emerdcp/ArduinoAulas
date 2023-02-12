// Fade
// Programa que faz um led acender e apagar com brilho

int led_vermelho = 11;
int brilho = 0;
int intensidade = 5;
String comando = "aumentar";

void setup()
{
  pinMode(led_vermelho, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  Serial.println(comando);
  Serial.println(brilho);
  analogWrite(led_vermelho, brilho);
    
  if(comando == "aumentar"){
     brilho = brilho + intensidade;    
  }else{
     brilho = brilho - intensidade;
  }

  if(brilho >= 255){
     comando = "diminuir";
  }else if(brilho <= 0){
     comando = "aumentar";
  }
  delay(100);
}