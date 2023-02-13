const byte Led = D1;       //D1 - GPIO05 - usar uma saído GND
const byte BT = D2;

void setup() {
  pinMode(Led, OUTPUT);
  pinMode(BT, INPUT_PULLUP);// PARA DEFINIR QUANDO O BOTÃO ESTA SOLDO, E NÃO APERTADO
}

void loop() {
    if(digitalWrite(BT) == LOW){
         digitaWrite(Led, HIGH); //sempre que tiver solto liga o APAGADO.
    }
    else{
        digitalWrite(Led, LOW); // sempre que apertar o botão led ACENDE.
    }       
}

