//define other files to load.
//depending on file location you may need to use "<dht.h>" instead of ""dht.h"" Use ""dht.h"" for local files, an other for files in default library location.

#include "dht.h"


#define TemperatureAndHumidity_pin 7 // set pin for temp and humidity. this (and all pins) can be changed here.

//define global scope variables here
dht DHT; //temp and humidity global object - DO NOT RENAME THIS VARIABLE

void setup(){
  Serial.begin(9600); //begin the serial to print to.
  Serial.println("Starting your farm.");
  // put your setup code here, to run once when the program is sent:
  //
  //
}

void loop() {
  // put your main code here, to run repeatedly:

  double temp = getTemperature();
  double humi = getHumidity();
  Serial.println("temp = %d", temp);
  Serial.println("humidity = %d", humi);
  
  delay(1000);
}

/* This function will record the temperature using the
 *  sensor assigned to pin TemperatureAndHumidity_pin.
 * Then it will return the current temp as a double in celcius.
 * Sometimes this will return -999. Please check this.
 */
double getTemperature(){
  int check = DHT.read11(TemperatureAndHumidity_pin);
  return DHT.temperature;
}

double getHumidity(){
   int check = DHT.read11(TemperatureAndHumidity_pin);
  return DHT.humidity;
}

