 #include "SoftwareSerial.h"

SoftwareSerial comm = SoftwareSerial(A10,A11);
// 10, 11, 12, 13, 50, 51, 52, 53, 62, 63, 64, 65, 66, 67, 68, 69


//保存串口0传入的字符串 
static String  inputString = "";
//串口0传输完成标志
static bool stringComplete = 0;

//保存串口3传入的字符串 
static String  inputString3 = "";
//串口3传输完成标志
static bool stringComplete3 = 0;


void setup() {
  Serial.begin(115200);
  comm.begin(38400);    

  Serial.println("OK");
    
  while(Serial.read()>= 0){}//clear serialbuffer
  while(comm.read()>= 0){}//clear serialbuffer

  comm.println("AT+RET");


  delay(100);
  
  while (comm.available()) {
      char inChar = (char)comm.read();
      if (inChar == '\n') {
        stringComplete3 = true;
      }
      else if(isDigit(inChar))
        inputString3 += inChar;
    }
  
  String vol = "";
  vol += inputString3[0];
  vol += inputString3[1];

  String freq = "";
  for(int i = 2;i < inputString3.length();i ++)
    freq += inputString3[i];
  
  Serial.println(vol.toInt());
  Serial.println(freq.toInt());
 
}

void loop() {


}

