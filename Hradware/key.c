#include "stm32f10x.h"                  // Device header
#include "delay.h"
void key_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitTypeDef GPIO_Initinsturcture;
	GPIO_Initinsturcture.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_Initinsturcture.GPIO_Pin=GPIO_Pin_1 |GPIO_Pin_11;
	GPIO_Initinsturcture.GPIO_Speed= GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_Initinsturcture);
}
uint8_t Key_GET_Num(void)
{
	uint8_t Key_Num = 0;
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1)==0)
		{
			Delay_ms(20);
			while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1)==0)
			Delay_ms(20);	
			Key_Num = 1;	
		}	
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11)==0)
		{
			Delay_ms(20);
			while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11)==0)
			Delay_ms(20);	
			Key_Num = 2;	
		}	
return Key_Num;
}