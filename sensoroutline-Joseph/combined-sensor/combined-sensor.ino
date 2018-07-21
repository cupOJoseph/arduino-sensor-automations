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
  String status_string = ""; //a string to build a status with and print out at the end.

  //example using get temperature function
  double temp = getTemperature();
  status_string += "temp = ";
  status_string += temp;

  //example using get humidity function
  double humi = getHumidity();
  status_string += "; humidity = ";
  status_string += humi;

  //example using get oxygen
  
  
  Serial.println(status_string);
  
  delay(1000);
}

// ============================================================= 
// |                      HELPER FUNCTIONS                     |
// |                                                           |
// =============================================================
//This area below for Joseph's custom functions.

/* This function will record the temperature using the
 *  sensor assigned to pin TemperatureAndHumidity_pin.
 * Then it will return the current temp as a double in celcius.
 * Sometimes this will return -999. Please check this.
 */
double getTemperature(){
  int check = DHT.read11(TemperatureAndHumidity_pin);
  return DHT.temperature;
}

/* This function will record the Humidity using the
 * sensor assigned to pin TemperatureAndHumidity_pin.
 * Then it will return the current humidity as a double in celcius.
 * Sometimes this will return -999. Please check this.
 */
double getHumidity(){
   int check = DHT.read11(TemperatureAndHumidity_pin);
  return DHT.humidity;
}


/**get the oxygen level of the air.
 * I think this sensor is just for air.
 * 
 */
 float getOxygenInAir(){
    float Vout =0;
    Vout = readO2VoutAir();
    return readConcentrationAir();

 }


//================ O2 sensor helper functions ===================/
// THIS SECTION SECTION UN TESTED!
//
float readO2VoutAir()
{
    long sum = 0;
    for(int i=0; i<32; i++)
    {
        sum += analogRead(OxygenSensorPin);
    }
    sum >>= 5;
    float MeasuredVout = sum * (VRefer / 1023.0);
    return MeasuredVout;
}

float readConcentrationAir()
{
    // Vout samples are with reference to 3.3V
    float MeasuredVout = readO2VoutAir();

    //float Concentration = FmultiMap(MeasuredVout, VoutArray,O2ConArray, 6);
    //when its output voltage is 2.0V,
    float Concentration = MeasuredVout * 0.21 / 2.0;
    float Concentration_Percentage=Concentration*100;
    return Concentration_Percentage;
}
// ================================================== ^End O2 helpers =================================== //

