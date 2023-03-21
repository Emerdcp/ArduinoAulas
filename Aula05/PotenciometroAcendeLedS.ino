/*
Acender um LED 3 de acordo com o Potenciômetro
*/

int valor = 0;
int ledVermelho = 11;
int ledAmarelo = 10;
int ledVerde = 9;

void setup(){
	pinMode(ledVermelho, OUTPUT);
 	pinMode(ledAmarelo, OUTPUT);
 	pinMode(ledVerde, OUTPUT);
	Serial.begin(9600);
  	Serial.println("incio");
}

void loop(){
	valor = analogRead(A0);
  	Serial.print("Valor = ");
  	Serial.println(valor);
  
  if(valor < 500){
	  leds(0,0,0);
  }else if(valor <700){
	  leds(1,0,0);
  }else if(valor < 900){
	  leds(1,1,0);
  }else{
	  leds(1,1,1);
  }
}

void leds(int led1, int led2, int led3){
	digitalWrite(ledVermelho, led1);
	digitalWrite(ledAmarelo, led2);
	digitalWrite(ledVerde, led3);
}