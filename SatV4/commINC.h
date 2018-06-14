
//IIC
#include "Wire.h"
/*
 在初始化函数中调用
 Wire.begin();
*/

//姿态                     T
#include "commIMU.h"
/*

函数1：imuInit();
用法：初始化函数中调用，要求先开启 Wire.begin();
参数：无参数
返回值：无


函数2：imuData(float *AX,float *AY,float *AZ,float *GX,float *GY,float *GZ,float *MX,float *MY,float *MZ ,float *YAW ,float *PITCH ,float *ROLL);
用法：直接调用
参数：用于存储加速度、角速度、磁分量、姿态的数据，各参数均为浮点型变量；
返回值：无

*/


//温湿度sht31
#include "commSHT.h"
/*

函数1：shtInit(int add);
用法：初始化函数中调用，要求先开启 Wire.begin();
参数：传感器地址，SHT31默认地址0x44;
返回值：无


函数2：sht31dVal(float *tem,float *rh);
用法：直接调用
参数：tem存储温度，rh存储湿度；
返回值：无

*/

//UV
#include "commUV.h"
/*
函数1：s12sdValMv(int s12sdPin);
用法：直接调用
参数：模拟量读取口
返回值：返回浮点型电压值

函数2：uvLevel(int s12sdPin);
用法：直接调用
参数：模拟量读取口
返回值：返回整型紫外线指数

*/

//电压检测
#include "commCDC.h"
/*

函数1：dcVal(int voltagePin);
用法：直接调用
参数：模拟量读取口
返回值：返回浮点型电压值
*/

//光照强度检测              T
#include "commLight.h"
/*
函数1：TSL2561Init();
用法：初始化函数中调用，要求先开启 Wire.begin();
参数：无参数
返回值：无

函数2：lightVal();
用法：直接调用 
参数：无参数
返回值：浮点型光照流明值
*/

//UHF                  
#include "commUHF.h"
/*
函数1：void FMinit(long Boud);
用法：初始化函数中调用，要求设置串口3的波特率;
参数：串口3的波特率
返回值：无


函数2：void enAT(int pin);
用法：直接调用
参数：进入AT模式，pin连接set
返回值：无返回值

函数3：outAT(int pin);
用法：直接调用
参数：退出AT模式
返回值：无返回值

***测试用函数4：void testAt();
用法：在开启AT模式之后调用，且与必须在上一条指令50ms之后运行
参数：无
返回值：无返回值

函数5：void setBoud(long a);
用法：设置UHF波特率，在开启AT模式之后调用，且与必须在上一条指令50ms之后运行
参数：波特率数值 u long型
返回值：无返回值

函数6：void setCh(long a);
用法：设置UHF信道，在开启AT模式之后调用，且与必须在上一条指令50ms之后运行
参数：信道数值 int型
返回值：无返回值

*/



//FM                  
#include "commFM.h"
/*
函数1：FMinit();
用法：初始化函数中调用，要求设置软串口的对应引脚，在.c文件中;
参数：无参数
返回值：无


函数2：void setFre(int a);
用法：直接调用
参数：设置的频率，范围885~1080，无小数点
返回值：无返回值

函数3：void setVol(int a);
用法：直接调用
参数：设置的音量，范围0~30，无小数点
返回值：无返回值

*/

//RTC                  
#include <commRTC.h>
/*
函数1：RTCinit();
用法：初始化函数中调用，要求先开启 Wire.begin();
参数：无参数
返回值：无

函数2：adjTime(int y,int m,int d,int h,int mi,int s);
用法：直接调用
参数：年月日时分秒
返回值：无

函数3：getTime(int * year,int * mon ,int * day ,int * hour ,int * min ,int * sec);
用法：直接调用
参数：年月日时分秒
返回值：无

*/



//气压、温度、高度检测                  T
#include <commBMP180.h>
/*
函数1：pressureInit();
用法：初始化函数中调用，要求先开启 Wire.begin();
参数：无参数
返回值：无


函数2：pressureVal();
用法：直接调用
参数：无参数
返回值：浮点型气压值 hpa;

函数3：altitudeVal();
用法：直接调用
参数：无参数
返回值：浮点型自基准面起的高度 m;


函数4：tempVal();
用法：直接调用
参数：无参数
返回值：浮点型温度值 ℃;

*/




