//define other files to load.
//depending on file location you may need to use "<dht.h>" instead of ""dht.h""
#include "dht.h"
#define DHT11_PIN 7

//define global scope variables here
dht DHT;

void setup(){
  Serial.begin(9600);
  // put your setup code here, to run once when the program is sent:
  Serial.println("start");
}

void loop() {
  // put your main code here, to run repeatedly:
  int check = DHT.read11(DHT11_PIN);
  //temp in C
  double temp = DHT.temperature;
  double hum = DHT.humidity;
  if(temp > -900){
      Serial.print("temp = ");
      Serial.println(DHT.temperature);
  }
  delay(1000);
}
