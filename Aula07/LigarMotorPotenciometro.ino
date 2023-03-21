/*
Ligando um Motor com controle de velocidade pelo potenciometro
*/

int motor = 11;
int potenciometro = A0;
int valor = 0;
int valor_convertido = 0;
int led = 3;

void setup(){
 	pinMode(motor, OUTPUT);
    //colocando led---
    pinMode(led, OUTPUT);
  	//colocando led---
	Serial.begin(9600);
  	Serial.println("incio");
}

void loop(){
	valor = analogRead(potenciometro);
	valor_convertido = map(valor, 0, 1023, 0, 255);
	Serial.println(valor);
	analogWrite(motor, valor_convertido);
 	Serial.println(valor_convertido);
	
    //colocando led se motor ligardo led acende---
    if(valor <100){
    	digitalWrite(led, 0);
    }else
       digitalWrite(led, 1);
    //colocando led---
    
    
    
  delay(1000);
}
   