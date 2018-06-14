void setup() {
  Serial3.begin(9600);
  enAT();

 delay(50);
 testAt();
 delay(50);
 setBoud(9600);
 delay(50);
 setCh(40);
 delay(100);
}

void loop() {

}

void testAt(){
   Serial3.println("AT");
  }
  
void setBoud(unsigned long a){
   Serial3.println("AT+B"+(String)a);
  }  
void setCh(int a){
  String Sa = "";
  
  if(a < 10){
   Serial3.println("AT+C00"+(String)a);
   }
  else if(a < 100){
   Serial3.println("AT+C0"+(String)a);
   }
  else {
   Serial3.println("AT+C"+(String)a);
   }
  }



