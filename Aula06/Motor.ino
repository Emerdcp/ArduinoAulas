/*
Ligar Motor
*/

int botao = 5;
int led = 13;
int motor = 11;

int estado_do_botao = 0;

void setup(){
	pinMode(motor, OUTPUT);
	pinMode(led, OUTPUT);
	pinMode(botao, INPUT_PULLUP);
	
	Serial.begin(9600);
	Serial.println("Ligou");
}

void loop(){
  	estado_do_botao = digitalRead(botao);
  	Serial.println(estado_do_botao);
  	digitalWrite(motor, estado_do_botao);
    if(estado_do_botao == digitalRead(botao)){
      digitalWrite(led, estado_do_botao);
    }

    delay(300);
}