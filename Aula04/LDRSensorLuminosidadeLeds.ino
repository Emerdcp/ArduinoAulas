int ldr = A0;
int valor = 0;
int led_azul = 10;
int led_vermelho = 6;
int led_amarelo = 11;
int led_verde = 9;

void setup(){
	pinMode(led_azul, OUTPUT);
  pinMode(led_vermelho, OUTPUT);
  pinMode(led_amarelo, OUTPUT);
  pinMode(led_verde, OUTPUT);
	Serial.begin(9600);
}

void loop(){
	valor = analogRead(ldr);
	Serial.println(valor);
		
	if(valor < 100){
    digitalWrite(led_azul, 1);
    digitalWrite(led_vermelho, 1);
    digitalWrite(led_amarelo, 1);
    digitalWrite(led_verde, 1);
	}else if(valor < 200){
    digitalWrite(led_azul, 1);
    digitalWrite(led_vermelho, 1);
    digitalWrite(led_amarelo, 1);
  }else if(valor < 300){
    digitalWrite(led_azul, 1);
    digitalWrite(led_vermelho, 1);
  }else if(valor < 400){    
		digitalWrite(led_azul, 1);
  }else{
		digitalWrite(led_azul, 0);
    digitalWrite(led_vermelho, 0);
    digitalWrite(led_amarelo, 0);
    digitalWrite(led_verde, 0);
	}
	delay(1000);
}