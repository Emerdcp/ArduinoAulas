//Luminosidade de um Led, mudar a intencidade


const byte Led = D1;       

void setup() {
  Serial.begin(9600);
}

void loop() {
    analogWrite(Led, analogRead(A0));  // de 0 a 255 o brilho máximo - Colcoado o analogread para fazer leitura do Pino.
}                                       // Usando o PINO da A0 que estava conectado o pino de Sensor de LDR luminosidade

