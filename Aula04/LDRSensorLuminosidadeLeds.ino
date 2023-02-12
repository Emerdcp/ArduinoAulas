/*
LDR Sensor de Luminosidade "Entrada de Dados"
O Led acende o sensor LDR estiver com valor menor do que 500
*/

int ldr = A0;
int valor = 0;
int led1 = 11;
int led2 = 10;
int led3 = 9;

void setup(){
	pinMode(led1, OUTPUT);
  	pinMode(led2, OUTPUT);
  	pinMode(led3, OUTPUT);
	Serial.begin(9600);
}

void loop(){
	valor = analogRead(ldr);
	Serial.println(valor);
		
	if(valor < 100){
		digitalWrite(led1, 1);
		digitalWrite(led2, 1);
		digitalWrite(led3, 1);
	}else if(valor < 300){
		digitalWrite(led1, 1);
		digitalWrite(led2, 1);
	}else if(valor < 500){
		digitalWrite(led1, 1);
	}else{
		digitalWrite(led1, 0);
		digitalWrite(led2, 0);
		digitalWrite(led3, 0);
	}
	delay(1000);
}