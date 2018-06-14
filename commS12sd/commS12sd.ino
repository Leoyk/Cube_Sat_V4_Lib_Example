#define s12sdPin A0
#define fliterNumber 20


void setup() {
  Serial.begin(9600);
  s12sdInit();
}

void loop() {
  Serial.print(s12sdValMv());//电压（mV） * 10为UV值
  Serial.print("|");
  Serial.print(analogRead(s12sdPin) * 4.89);//电压(mV)
  Serial.print("|");
  Serial.println(s12sdLevel());
}


/*================================================================ 
* 函 数 名：
* s12sdInit 
* 
* 参 数：
* 无 
*
* 功 能 描 述: 
* 初始化S12SD的信号引脚
* 
* 返 回 值：
* 无
* 
* 作 者：赫文 2018年5月18日15:26:28

================================================================*/ 
void s12sdInit(){
  pinMode(s12sdPin,INPUT);
}

/*================================================================ 
* 函 数 名：
* s12sdValMv 
* 
* 参 数：
* 无 
*
* 功 能 描 述: 
* 获取紫外线传感器的电压值（mv）,通过窗口滤波后输出。
* 
* 返 回 值：
* 获取的紫外线传感器电压值（mv）
* 
* 作 者：赫文 2018年5月18日15:26:28

================================================================*/ 
float s12sdValMv(){
 return  smoothFliter(analogRead(s12sdPin) * 4.89 , 100);
}


/*================================================================ 
* 函 数 名：
* smoothFliter 
* 
* 参 数：
* newVal 新的需要滤波的数据
* Time Time时间内的平均值
*
* 功 能 描 述: 
* 在Time时间内获取紫外线传感器的电压值（mv）,通过窗口滤波后输出。
* 
* 返 回 值：
* 滤波后的紫外线传感器电压值（mv）
* 
* 作 者：赫文 2018年5月18日15:26:28

================================================================*/ 
float smoothFliter(int newVal,int Time){
//创建滑动窗口数组并启用更新

  static float arr[fliterNumber];//窗口数组
  static float sum;//N个数值的总和
  float outVal;//滤波后的输出值
 
  sum = sum - arr[fliterNumber - 1];//去除最后一位的总和
  
  for(int i = fliterNumber - 1;i > 0;i --){
        arr[i]=arr[i - 1];//从最后一位开始向右滑动一次，最后一位被丢弃；
        delay(Time/20);
  }
  
  arr[0] = newVal;//首位存入新的数据
  
  sum = sum + arr[0];//新的总和
  
  outVal = sum / fliterNumber;//求算数平均值

 return outVal;
 }



/*================================================================ 
* 函 数 名：
* s12sdLevel 
* 
* 参 数：
* 无 
* 
* 功 能 描 述: 
* 获取紫外线传感器的电压值（mv）后判断当前的紫外线水平
* 
* 返 回 值：
* 当前的紫外线水平 0~12
* 
* 作 者：赫文 2018年5月18日15:26:28

================================================================*/ 
int s12sdLevel(){
  int uv = 0;
  float vout = 0;
  vout = s12sdValMv();
  
if(vout < 50){  //查表，把得到的光电流值转换成紫外线等级
    uv = 0;
  }
  else if(vout < 227){
    uv = 1;
  }
  else if(vout < 318){
    uv = 2;
  }
  else if(vout < 408){
    uv = 3;
  }
  else if(vout < 503){
    uv = 4;
  }
  else if(vout < 606){
    uv = 5;
  }
  else if(vout < 696){
    uv = 6;
  }
  else if(vout < 795){
    uv = 7;
  }
  else if(vout < 881){
    uv = 8;
  }
  else if(vout < 976){
    uv = 9;
  }
  else if(vout < 1079){
    uv = 10;
  }
  else{
    uv = 11;
  }
  return uv;
  
  }
