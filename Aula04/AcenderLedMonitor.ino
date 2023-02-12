/*
Acender Led Monitor
Acender um led pelo monitor serial, se aperta a tecla A acende, se apertar a tecl B apagado
*/

int led_vermelho = 11;
int led_amarelo = 10;
int led_verde = 9;
String comando = "Vamos acender um LED";
String letras = "Digite a Letra para acender (A, C ou E), e para apagar (B, D ou E).";

void setup(){
	pinMode(led_vermelho, OUTPUT);
	pinMode(led_amarelo, OUTPUT);
	pinMode(led_verde, OUTPUT);
	Serial.begin(9600);
	Serial.println(comando);
  	Serial.println(letras);
}

void loop(){
	if(Serial.available()){
		switch(Serial.read()){
			case 'A':
				digitalWrite(led_vermelho, 1);
				Serial.println("Led Vermelho Acesso");
          		Serial.println(letras);
				break;
			case 'B':
				digitalWrite(led_vermelho, 0);
				Serial.println("Led Vermelho Apagado");
          		Serial.println(letras);
				break;
			case 'C':
				digitalWrite(led_amarelo, 1);
				Serial.println("Led AmareloAcesso");
          		Serial.println(letras);
				break;
			case 'D':
				digitalWrite(led_amarelo, 0);
				Serial.println("Led Amarelo Apagado");
          		Serial.println(letras);
				break;
			case 'E':
				digitalWrite(led_verde, 1);
				Serial.println("Led Verde Acesso");
          		Serial.println(letras);
				break;
			case 'F':
				digitalWrite(led_verde, 0);
				Serial.println("Led Verde Apagado");
          		Serial.println(letras);
				break;
		}
	}
}