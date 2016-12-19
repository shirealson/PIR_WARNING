#define  sensorPin  6
#define buzzer_pin 10
#define time_max 3000//等待时间
#define tem_max 35
float sensor_tem;

#include <Wire.h>//调用收发数据所使用的库函数
#include "I2Cdev.h"
 
#include <SHT2x.h>
int state;
long timer1;



void setup()
{
   Wire.begin(); 
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
  timer1=millis();
}
void loop()
{
  //Serial.print("timer1:  ");Serial.println(timer1);
  Serial.print("temp:   ");Serial.println(sensor_tem);
  state = digitalRead(sensorPin);
  sensor_tem = SHT2x.GetTemperature();
  Serial.print("waiting time:   ");Serial.println(millis()-timer1);
  if (!state == 1)
    {
 
    timer1=millis();
    Serial.println("RESET!");
    }

  if (millis()-timer1>time_max||sensor_tem>35)
  {
    
    buzzer();
    }
    else
    {
      noTone(buzzer_pin);
      }

  delay(100);
}

 void buzzer()
    {
     
    for(int i=200; i<2000;i++)
      {
        tone(buzzer_pin,i);
        }
     for(int i=2000;i>200;i--)
     {
      tone(buzzer_pin,i);
      
      }
    }
