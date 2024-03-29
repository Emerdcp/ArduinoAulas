/*
*      CÓDIGO:  Q0492
*      AUTOR:   BrincandoComIdeias
*      LINK:    https://www.youtube.com/brincandocomideias ; https://www.youtube.com/user/amazoniano1
*      CURSOS:  https://cursodearduino.net/ ; https://cursoderobotica.net/
*      COMPRE:  https://www.arducore.com.br/
*      SKETCH:  Arduino nas Miniaturas - feat. Mister M das Miniaturas
*      DATA:    20/08/2019
*/

// INCLUSÃO DE BIBLIOTECAS
#include <SoftwareSerial.h>
#include <Servo.h>
#include <PiscaLed.h>

// DEFINIÇÕES DE PINOS
#define pinA 5
#define pinB 6
#define pinServo 12

#define pinRx 2
#define pinTx 3

// FIOS LEDS TRAZEIRA
#define pinPiscaTraseira A1 // AMARELO
#define pinRe A2 // CINZA
#define pinLanterna A3 // AZUL
#define pinFreio A4 // VERMELHO

// FIOS LEDS FRENTE
#define pinPiscaFrente 8 // VERDE
#define pinFarol  9 // BRANCO
#define pinFarol2 10 // ROSA
#define pinMilha 11 // VERMELHO

// DEFINIÇÕES
#define velMin 100
#define velMax 250

#define intervaloDirecao 50
#define maxEsq 70
#define maxDir 120

#define DEBUG
// INSTANCIANDO OBJETOS
SoftwareSerial btSerial(pinRx, pinTx);
PiscaLed piscaTraseira(pinPiscaTraseira, 400);
PiscaLed piscaFrente(pinPiscaFrente, 400);
Servo volante;

// DECLARAÇÃO DE FUNÇÕES
void btLoop();
void motorLoop(int modo);
void ledLoop();
void volanteLoop();

// DECLARAÇÃO DE VARIÁVEIS GLOBAIS
byte direcaoServo = 95;
byte velocidade = velMin;
int sentido = 0;

bool farol = LOW;
bool lanterna = LOW;
bool pisca = false;
bool luzRe = LOW;
bool luzFreio = LOW; // IMPLEMENTAR 

char controle = 'D';
char controleAnt = 'S';

unsigned long controleTempo = 0;

// ***************** INÍCIO DO SETUP *************************
void setup() {
  Serial.begin(9600);
  btSerial.begin(9600);

  volante.attach(pinServo);

  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);

  pinMode(pinPiscaTraseira, OUTPUT);
  pinMode(pinFreio, OUTPUT);
  pinMode(pinRe, OUTPUT);
  pinMode(pinLanterna, OUTPUT);
  pinMode(pinPiscaFrente, OUTPUT);
  pinMode(pinFarol, OUTPUT);
  pinMode(pinFarol2, OUTPUT);
  pinMode(pinMilha, OUTPUT);

  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);

  digitalWrite(pinPiscaTraseira, HIGH);
  digitalWrite(pinFreio, HIGH);
  digitalWrite(pinRe, HIGH);
  digitalWrite(pinLanterna, HIGH);
  digitalWrite(pinPiscaFrente, HIGH);
  digitalWrite(pinFarol, HIGH);
  digitalWrite(pinFarol2, HIGH);
  digitalWrite(pinMilha, HIGH);

  delay(1000);

  digitalWrite(pinPiscaTraseira, LOW);
  digitalWrite(pinFreio, LOW);
  digitalWrite(pinRe, LOW);
  digitalWrite(pinLanterna, LOW);
  digitalWrite(pinPiscaFrente, LOW);
  digitalWrite(pinFarol, LOW);
  digitalWrite(pinFarol2, LOW);
  digitalWrite(pinMilha, LOW);

  while(!btSerial.available())

#ifdef DEBUG
  Serial.println("Fim Setup");
#endif
}
// ***************** FIM DO SETUP ***************************

// ***************** INÍCIO DO LOOP *************************
void loop() {

  btLoop();
  ledLoop();
  motorLoop(sentido);
  volanteLoop();

}
// ***************** FIM DO LOOP ***************************

// IMPLEMENTO DE FUNÇÕES
void btLoop() {

  if ( btSerial.available() ) {
    controle = btSerial.read();
  }

  if (controle != controleAnt) {

    if (controle == 'F' || controle == 'G' || controle == 'I') {      
      sentido = 1;
      luzRe = false;
      luzFreio = false;

    } else if (controle == 'B' || controle == 'H' || controle == 'J') {      
      sentido = -1;
      luzRe = true;
      luzFreio = false;

    } else if (controle == 'D' || controle == 'S') {      
      sentido = 0;
      luzRe = false;
      luzFreio = true;

    } else if (controle > 'S') {

      switch (controle) {
        case 'W': {
            farol = HIGH;
            break;
          }
        case 'w': {
            farol = LOW;
            break;
          }
        case 'U': {
            lanterna = HIGH;
            break;
          }
        case 'u': {
            lanterna = LOW;
            break;
          }
        case 'X': {
            pisca = true;
            break;
          }
        case 'x': {
            pisca = false;
            break;
          }
      }
    } else if ( controle < 58) {
      velocidade = map( (int)controle, 48, 57, velMin, velMax );
    }
    controleAnt = controle;
  }
}

void ledLoop() {
  piscaTraseira.loop();
  piscaFrente.loop();
  
  digitalWrite(pinFreio, luzFreio);
  digitalWrite(pinFarol, farol);
  digitalWrite(pinFarol2, farol);
  digitalWrite(pinLanterna, lanterna);
  digitalWrite(pinMilha, lanterna);
  digitalWrite(pinRe, luzRe);

  if (pisca && !piscaTraseira.estado() ) {
    piscaTraseira.play();
    piscaFrente.play();
  }
  else if (!pisca && piscaTraseira.estado() ) {
    piscaTraseira.stop();
    piscaFrente.stop();
  }
}

void motorLoop(int modo) {

  if (modo == 0) {
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, LOW);
  } else if (modo == 1) {
    analogWrite(pinA, velocidade);
    analogWrite(pinB, LOW);
  } else if (modo == -1) {
    analogWrite(pinB, velocidade);
    analogWrite(pinA, LOW);
  }

}

void volanteLoop(){
  
  if( millis() - controleTempo > intervaloDirecao){
    
    if (direcaoServo < maxDir && (controle == 'I' || controle == 'J' || controle == 'R') ) direcaoServo += 2;
    else if (direcaoServo > maxEsq && (controle == 'G' || controle == 'H' || controle == 'L') ) direcaoServo -= 2;
    else if (controle == 'D') direcaoServo = 95;
    
    volante.write(direcaoServo);
    controleTempo = millis();
  }
  
}
