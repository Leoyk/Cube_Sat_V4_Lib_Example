#include "commINC.h"

void setup() {
pressureInit();
Serial.begin(115200);
}

void loop() {

Serial.print(pressureVal());
Serial.print("\t");
Serial.print(altitudeVal());
Serial.print("\t");
Serial.println(tempVal());
}
