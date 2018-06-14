#include "commWS2812.h"



/*
1.各灯板信号引脚定义
  #define PINRIGHT  2
  #define PINLEFT   3  
  #define PINMIDDLE 4
  
2.亮度默认为40

*/
 
void setup() {
  wsInit();//初始化
}

void loop() {

//左面板滚动Abc
  while(showStrLeft("Abc",0,0,200) == 0)//左面板显示，Abc，颜色R:0,G:0,B:200
   {
      delay(80); 
    }

//左面板第0行显示亮点    
  setPixels("left",0,0x01,0,0,150);//左面板，0行，横坐标：B00000001，R:0，G:0，B:150
  showPixels("left");

//右面板滚动123
  while(showStrRight("123",0,0,200) == 0)//右面板显示，123，颜色R:0,G:0,B:200
   {
      delay(80); 
    }
    
//右面板第7行显示亮点 
  setPixels("right",7,0x1,0,0,150);//右面板，7行，横坐标：B00000001，R:0，G:0，B:150
  showPixels("right");

}
