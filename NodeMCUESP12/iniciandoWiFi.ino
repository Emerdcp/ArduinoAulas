/*
* Workshop - Controle dispositivos remotamente com ESP8266
* Por: Fábio Souza
*
* Exemplo 2 - WIFI
* Conecta a placa a uma REDE WIFI
*/
#include <ESP8266WiFi.h>

//configurações da rede
const char* ssid = "ssid";
const char* senha = "senha";

void setup(){
    Serial.begin(115200); //configuar comunicação serial 9600.
    delay(10);

    //mensagem de debug serial
    Serial.print("Conectando para a rede ");
    serial.println(ssid);

    //iniciando a conexão WiFi
    WiFi.begin(ssid, senha);

    //aguardando a conexão WiFi
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    //mensagem de conectado
    Serial.println("");
    Serial.println("WiFi conectado");
    Serial.println("Endereço, IP: ");
    Serial.println(WiFi.localIP());   
}

void loop(){
    //não faz nada no loop
}

// testar a conexão para saber se deu certo
// Abrir o serial monitor para ver o que está aparecendo e ver se traz o IP.
// testar no CMD e testar o IP.