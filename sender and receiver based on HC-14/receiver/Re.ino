String comdata = "";//字符串函数
#include <Servo.h>            //加载文件库
int pos = 0;
unsigned int myTime = 0;
Servo myservo1;
Servo myservo2;
Servo myServo3;
Servo myServo4;
String comStr1 = "";     
int comInt1=1500;
int comInt2=1500;
String comStr2 = "";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(38400);
  myServo3.attach(11); // attach myServo to GPIO_09
  myServo4.attach(6);
  myServo3.writeMicroseconds(1500); // set initial PWM to minimal
  myServo4.writeMicroseconds(1500);
  myservo1.attach(9, 500, 2500);
  myservo2.attach(10,500,2500);
}

void loop() {
  int pos1,pos2;
  if (Serial.available() > 0){
  if (Serial.available() > 0)//判读是否串口有数据
  {
    myTime = 0;
    String comdata = "";//缓存清零
    while (Serial.available() > 0)//循环串口是否有数据
    {
      comdata += char(Serial.read());//叠加数据到comdata
      delay(2);//延时等待响应
    }

    // listen the Serial port, run the code when something catched..
    delay(10);
    comStr1 = comdata.substring(8,12); // read out the string
    comInt1 = comStr1.toInt(); // convert the string to integer
    comInt1 = constrain(comInt1,1000, 2000); // limit the integer between to 1000  and 2000
    
    comStr2 = comdata.substring(12,16); // read out the string
    comInt2 = comStr2.toInt(); // convert the string to integer
    comInt2 = constrain(comInt2,1000, 2000); // limit the integer between to 1000  and 2000

    //Serial.println(comInt1); // show the integer number on Serial Monitor
    myServo3.writeMicroseconds(comInt1); // write the integer number to Servo in unit of micro-second
    myServo4.writeMicroseconds(comInt2);
    if (comdata.length() > 0)//如果comdata有数据
    {
      //Serial.println(comdata);//打印comdata数据
      pos1 = comdata.substring(0,4).toInt();
      pos2 = comdata.substring(4,8).toInt();
      //Serial.println(comInt2);
      //Serial.println();
      //Serial.println(comInt1);
      myservo1.write(pos1);
      myservo2.write(pos2);
    }
  }
  }
  else
  {
    delay(10);
    myTime=myTime+10;
    if(myTime>3000)
    {
      myservo1.write(1500);
      myservo2.write(1500);
      myServo3.write(1500);
      myServo4.write(1500);
    }

  }
  

  /*int pos1,pos2; 
  if (Serial.available() > 0)//判读是否串口有数据
  {
    String comdata = "";//缓存清零
    while (Serial.available() > 0)//循环串口是否有数据
    {
      comdata += char(Serial.read());//叠加数据到comdata
      delay(2);//延时等待响应
    }
    if (comdata.length() > 0)//如果comdata有数据
    {
      //Serial.println(comdata.substring(0,4));//打印comdata数据
      pos1 = comdata.substring(0,4).toInt();
      pos2 = comdata.substring(4,8).toInt();
      Serial.println(pos1);
      myservo1.write(pos1);
      myservo2.write(pos2);
    }
  }*/
}


