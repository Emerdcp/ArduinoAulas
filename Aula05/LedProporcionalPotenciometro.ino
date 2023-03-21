/*
Acender um LED porporcional ao potenciomêtro
*/

int led = 11;
int valor = 0;
int valor_mapeado = 0;

void setup(){
	pinMode(led, OUTPUT);
	Serial.begin(9600);
}

void loop(){
	valor = analogRead(A0);
LedProporcionalPotenciometro.ino	valor_mapeado = map(valor, 0, 1023, 0, 2555);
	//map(potenciomêtro, inicio pot, fim pot, inicio led, fim)
	analogWrite(led, valor_mapeado);
	Serial.println(valor_mapeado);
	delay(100);
}
