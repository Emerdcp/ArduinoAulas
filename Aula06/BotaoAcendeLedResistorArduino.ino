/*
Botão
Programa onde você aperta um botão e o led acende

Usando o resistor Interno do Arduino
*/

int led = 13;
int botao = 5;

int estado_do_botao = 0;

void setup(){
	pinMode(led, OUTPUT);
	pinMode(botao, INPUT_PULLUP);
	
	Serial.begin(9600);
	Serial.println("Começou");
}

void loop(){
	estado_do_botao = digitalRead(botao);
	Serial.println(estado_do_botao);
	
  	digitalWrite(led, estado_do_botao);
  
  	/*if(estado_do_botao == 1){
		digitalWrite(led, 1);
    }else{
		digitalWrite(led, 0);
    }*/
	
	delay(300);
}