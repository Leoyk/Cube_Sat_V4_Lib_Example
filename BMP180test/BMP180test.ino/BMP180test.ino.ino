#include "commINC.h"

static float temperature;  
static double pressure;   
static double altitude;  

void setup(){
  Wire.begin();
  pressureInit();  
  Serial.begin(115200);
}

void loop(){
  
  orderTV();
  delay(5);
  
  temperature = tempVal();
  Serial.print(temperature);
  Serial.print("\t");

  
  orderPV();
  delay(30);
  
  pressure = pressureVal();
    Serial.print(pressure);
  Serial.print("\t"); 
  
   altitude = altitudeVal(pressure);
  Serial.println(altitude);
}


