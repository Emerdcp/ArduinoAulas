/*
Acender um LED de acordo com o Potenciômetro
*/

int valor = 0;
int led = 11;

void setup(){
	pinMode(led, OUTPUT);
	Serial.begin(9600);
  	Serial.println("incio");
}

void loop(){
	valor = analogRead(A0);
  	Serial.print("Valor = ");
  	Serial.println(valor);
  
  if(valor > 500){
    digitalWrite(led, 1);
  }else{
    digitalWrite(led, 0);
  }
	delay(1000);
}