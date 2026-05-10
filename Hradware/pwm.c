#include "stm32f10x.h"                  // Device header
void PWM(void)
{
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA,ENABLE);//使能APB2上GPIOA时钟

	GPIO_InitTypeDef GPIO_instructure;
	GPIO_instructure.GPIO_Mode=GPIO_Mode_AF_PP;//设置输出模式，该模式为复用推挽输出
	GPIO_instructure.GPIO_Pin=GPIO_Pin_2;//设置详细GPIO口
	GPIO_instructure.GPIO_Speed=GPIO_Speed_50MHz;//设置端口速度
	GPIO_Init(GPIOA,&GPIO_instructure);//指定初始化GPIO口

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);//使能TIM2时钟
	TIM_InternalClockConfig(TIM2);//选择TIM2的时钟源作为内部时钟
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInstructure;
	TIM_TimeBaseInstructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInstructure.TIM_CounterMode = TIM_CounterMode_Up;//
	TIM_TimeBaseInstructure.TIM_Period = 100-1;//arr，自动重载寄存器，计数器记到该值产生更新事件，并使计数器复位
	TIM_TimeBaseInstructure.TIM_Prescaler = 72-1;//psc，预分配处理器，降低时钟频率
	TIM_TimeBaseInstructure.TIM_RepetitionCounter = 0;//重复计数器
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInstructure);//指定TIM2完成初始化
	
	TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);//使能TIM2更新中断

	TIM_Cmd(TIM2,ENABLE);//开启TIM2计数器

	TIM_OCInitTypeDef TIM_OCInitInsturcture;//用默认值初始化TIM_OCInitTypeDef成员
	TIM_OCStructInit(&TIM_OCInitInsturcture);
	TIM_OCInitInsturcture.TIM_OCMode = TIM_OCMode_PWM1;//选择pwm1模式
	TIM_OCInitInsturcture.TIM_OCPolarity = TIM_OCPolarity_High;//选择极性决定什么电平为有效电平
	TIM_OCInitInsturcture.TIM_OutputState = TIM_OutputState_Enable;//将pwm应用到对应引脚上的功能使能
	TIM_OCInitInsturcture.TIM_Pulse = 10;//ccr，设置占空比，调制脉冲宽度
	TIM_OC3Init(TIM2,&TIM_OCInitInsturcture);//指定初始化的
}
void PWM_Setcompare3(uint16_t compare)
{
	TIM_SetCompare3(TIM2,compare);//动态控制ccr的值
}
