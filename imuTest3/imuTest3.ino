#include "commINC.h"

commIMU imu;

void setup() {
  Serial.begin(115200);
  Serial.println("begin");
  Wire.begin();
  imuInit();
}

void loop() {
  imu.getData();
//      m/s^2
  Serial.print(imu.AX);
  Serial.print("\t");
  Serial.print(imu.AY);
  Serial.print("\t");
  Serial.print(imu.AZ);
  Serial.print("\t");

//      deg/s
  Serial.print(imu.GX);
  Serial.print("\t");
  Serial.print(imu.GY);
  Serial.print("\t");
  Serial.print(imu.GZ);
  Serial.print("\t");


//       uT
  Serial.print(imu.MX);
  Serial.print("\t");
  Serial.print(imu.MY);
  Serial.print("\t");
  Serial.print(imu.MZ);
  Serial.println("\t");

}
