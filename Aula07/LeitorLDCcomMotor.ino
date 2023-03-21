/* 
Display LCD
*/

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int motor = 10;
int potenciometro = A0;
int valor = 0;
int valor_convertido = 0;
int led = 3;


void setup(){
  lcd.begin(16,2);
  lcd.print("Inicio");

  
  pinMode(motor, OUTPUT);
    //colocando led---
    pinMode(led, OUTPUT);
  	//colocando led---
	Serial.begin(9600);

  
}


void loop(){
	valor = analogRead(potenciometro);
	valor_convertido = map(valor, 0, 1023, 0, 255);
	Serial.println(valor);
	analogWrite(motor, valor_convertido);
 	Serial.println(valor_convertido);
	
    //colocando led---
    if(valor <100){
    	digitalWrite(led, 0);
    }else
       digitalWrite(led, 1);
    //colocando led---
    lcd.clear();
	lcd.setCursor(0,1);
  lcd.print("Rotacao:");
	lcd.print(valor_convertido);
	delay(1000);
  delay(1000);
}