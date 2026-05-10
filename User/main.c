#include "stm32f10x.h"                  // Device header
#include "delay.h"
#include "OLED.h"
#include "Motor.h"
#include "Key.h"


uint8_t Key_Num;
int8_t speed;
  int main(void)
 {
	OLED_Init();
	Motor_Init();
	key_Init(); 
	 OLED_ShowString(1,1,"speed");
    while(1)
	 {
		 Key_Num=Key_GET_Num();
		 if(Key_Num==1)
			 {
			 speed += 20;
			 Motor_Setspeed(speed);	 
			 }
		 else if(Key_Num==2)
			 {
			 speed -= 20;
			 Motor_Setspeed(speed);
			 }
		OLED_ShowSignedNum(1,7,speed,3); 
	 }
	
 }
	
