/* 
  Conexion wifi con ESP32
  Autor: Moreno Lucas Omar
  Año: 2020
*/

#include <WiFi.h>

// Credenciales WiFi
const char* ssid = "Moreno";
const char* password = "pringles772";

// Funcion: Conexion/Reconexion a red WiFi
void reconnect_wifi(){
  Serial.println("Conexion WiFi");
  Serial.print("Conectando a -> ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(250);
    digitalWrite(BUILTIN_LED, LOW);
  }
  Serial.println("");
  Serial.println("Conexion exitosa!");

  Serial.println("Mi IP es -> ");
  Serial.print(WiFi.localIP());
  digitalWrite(BUILTIN_LED, HIGH);
}

void setup() {
  Serial.begin(9600);
  pinMode(BUILTIN_LED, OUTPUT);
  digitalWrite(BUILTIN_LED, LOW);
}

void loop() {
  if(WiFi.status() != WL_CONNECTED) reconnect_wifi(); 
}
