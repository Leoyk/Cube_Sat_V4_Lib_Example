#include "commINC.h"
#include <Wire.h>

IMU imu;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  
  imuInit();
  Serial.println("init ok");
}

void loop() {
 
getData();
Serial.print(imu.AX);
Serial.print("\t");
Serial.print(imu.AY);
Serial.print("\t");
Serial.print(imu.AZ);
Serial.print("\t");
Serial.print(imu.GX);
Serial.print("\t");
Serial.print(imu.GY);
Serial.print("\t");
Serial.print(imu.GZ);
Serial.print("\t");
Serial.print(imu.MX);
Serial.print("\t");
Serial.print(imu.MY);
Serial.print("\t");
Serial.print(imu.MZ);
Serial.println();
}
