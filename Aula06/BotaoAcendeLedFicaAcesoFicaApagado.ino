/*
Botão
Programa onde você aperta um botão e o led acende

Aperta Botão fica Acesso, e depois apertar fica apagado.
*/

int led = 13;
int botao = 5;

int estado_do_botao = 0;

int estadoLed = 0;

void setup(){
	pinMode(led, OUTPUT);
	pinMode(botao, INPUT_PULLUP);
	
	Serial.begin(9600);
	Serial.println("Começou");
}

void loop(){
	estado_do_botao = digitalRead(botao);
	Serial.println(estado_do_botao);
  	Serial.print("Estado Led ");
 	Serial.println(estadoLed);
	if(estado_do_botao == 0){
		if(estadoLed == 1){
            estadoLed = 0;
		}else{
			estadoLed = 1;
		}
	}
  
	digitalWrite(led, estadoLed);
	delay(300);
}

 Mais simples feito pelo Guto
void loop(){
	estado_do_botao = digitalRead(botao);
	if(estado_do_botao == 0){
		if(digitalRead(led) == 1){
			digitalWrite(led, !digitalRead(led);
			delay(50);
	}
	delay(300);
}
