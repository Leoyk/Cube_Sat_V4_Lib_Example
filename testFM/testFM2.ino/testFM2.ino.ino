#include "commFM.h"

void setup() {
FMinit(9600);
enAT(7);
}

void loop() { 
 testAt();
 delay(50);
 setBoud(9600);
 delay(50);
 setCh(40);
 delay(100);
}
