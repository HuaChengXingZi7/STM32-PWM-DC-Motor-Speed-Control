#include "stm32f10x.h"                  // Device header
#include "pwm.h"
void Motor_Init()
{
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitTypeDef GPIO_instructure;
	GPIO_instructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_instructure.GPIO_Pin=GPIO_Pin_4 | GPIO_Pin_5;
	GPIO_instructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_instructure);
	PWM();
}
void Motor_Setspeed(int8_t speed)	
{
if(speed>0)//电流由pin4流向pin5时正转，speed取值大于0
	{
		GPIO_SetBits(GPIOA,GPIO_Pin_4);
		GPIO_ResetBits(GPIOA,GPIO_Pin_5);
		PWM_Setcompare3(speed);
	}
else//电流由pin5流向pin4时正转，speed取值小于0，经由-speed变为正数传给PWM_Setcompare3
    {
		GPIO_ResetBits(GPIOA,GPIO_Pin_4);
		GPIO_SetBits(GPIOA,GPIO_Pin_5);
		PWM_Setcompare3(-speed);
   }


}

