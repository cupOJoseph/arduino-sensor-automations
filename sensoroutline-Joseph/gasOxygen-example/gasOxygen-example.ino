//get gas O2 from sensor
// http://wiki.seeedstudio.com/Grove-Gas_Sensor-O2/

const float VRefer = 3.3;// voltage of adc reference

const int OxygenSensorPin = A5;

void setup() {
  Serial.begin(9600);
}

//The O2 sensor writes votage directly, must be converted to a useful number
void loop() {
  float x = getOxygenInAir();
  delay(500);
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
