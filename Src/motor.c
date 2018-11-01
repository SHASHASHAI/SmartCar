#include "motor.h"

#include "gpio.h"

void PWM_Init(u16 arr,u16 psc)
{		 		
	 		
	 GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
   DIR_Init();
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);//	ʹ��TIM1��TIM3
	
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA |RCC_APB2Periph_GPIOB, ENABLE);  //ʹ��GPIO����ʱ��ʹ��
   //���ø�����Ϊ�����������,���TIM1 CH1 CH4��PWM���岨��
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_6|GPIO_Pin_7; //TIM_CH3 //TIM_CH4
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //�����������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	TIM_TimeBaseStructure.TIM_Period = arr; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ	 
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ  ����Ƶ
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure); //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
 
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ1
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_Pulse = 0;                            //���ô�װ�벶��ȽϼĴ���������ֵ
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;     //�������:TIM����Ƚϼ��Ը�
	TIM_OC3Init(TIM1, &TIM_OCInitStructure);  //����TIM_OCInitStruct��ָ���Ĳ�����ʼ������TIMx
	TIM_OC4Init(TIM1, &TIM_OCInitStructure);  //����TIM_OCInitStruct��ָ���Ĳ�����ʼ������TIMx
	TIM_OC1Init(TIM1, &TIM_OCInitStructure);  //����TIM_OCInitStruct��ָ���Ĳ�����ʼ������TIMx
	TIM_OC2Init(TIM1, &TIM_OCInitStructure);  //����TIM_OCInitStruct��ָ���Ĳ�����ʼ������TIMx
	TIM_OC3Init(TIM3, &TIM_OCInitStructure);  //����TIM_OCInitStruct��ָ���Ĳ�����ʼ������TIMx
	TIM_OC4Init(TIM3, &TIM_OCInitStructure);  //����TIM_OCInitStruct��ָ���Ĳ�����ʼ������TIMx
	TIM_OC1Init(TIM3, &TIM_OCInitStructure);  //����TIM_OCInitStruct��ָ���Ĳ�����ʼ������TIMx
	TIM_OC2Init(TIM3, &TIM_OCInitStructure);  //����TIM_OCInitStruct��ָ���Ĳ�����ʼ������TIMx

  TIM_CtrlPWMOutputs(TIM1,ENABLE);	//MOE �����ʹ��	

	TIM_OC3PreloadConfig(TIM1, TIM_OCPreload_Enable);  //CH1Ԥװ��ʹ��	 
	TIM_OC4PreloadConfig(TIM1, TIM_OCPreload_Enable);  //CH4Ԥװ��ʹ��
	TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable);  //CH1Ԥװ��ʹ��	 
	TIM_OC2PreloadConfig(TIM1, TIM_OCPreload_Enable);  //CH4Ԥװ��ʹ��	 
	TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);  //CH1Ԥװ��ʹ��	 
	TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable);  //CH4Ԥװ��ʹ��
	TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);  //CH1Ԥװ��ʹ��	 
	TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);  //CH4Ԥװ��ʹ��	 
	
	TIM_ARRPreloadConfig(TIM1, ENABLE); //ʹ��TIMx��ARR�ϵ�Ԥװ�ؼĴ���
	TIM_ARRPreloadConfig(TIM3, ENABLE); //ʹ��TIMx��ARR�ϵ�Ԥװ�ؼĴ���
	
	TIM_Cmd(TIM1, ENABLE);  //ʹ��TIM1
  TIM_Cmd(TIM3, ENABLE);  //ʹ��TIM1
  
 
} 







void Motor_GPIO_Init(){
	GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
//  __HAL_RCC_GPIOD_CLK_ENABLE();
//  __HAL_RCC_GPIOA_CLK_ENABLE();
//  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */

  /*Configure GPIO pins : PBPin PBPin */
  GPIO_InitStruct.Pin = MOTORA_F_Pin | MOTORA_R_Pin | MOTORB_F_Pin | MOTORB_R_Pin|MOTORD_F_Pin|MOTORD_R_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PBPin PBPin PBPin PBPin */
  GPIO_InitStruct.Pin = MOTORC_F_Pin | MOTORC_R_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
	
	Motor_AllFoff();
	Motor_AllRoff();
}

void Motor_AllFon(){
	HAL_GPIO_WritePin(GPIOA, MOTORA_F_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, MOTORB_F_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, MOTORC_F_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, MOTORD_F_Pin, GPIO_PIN_SET);
}

void Motor_AllFoff(){
	HAL_GPIO_WritePin(GPIOA, MOTORA_F_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, MOTORB_F_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, MOTORC_F_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, MOTORD_F_Pin, GPIO_PIN_RESET);
}

void Motor_AllRon(){
	HAL_GPIO_WritePin(GPIOA, MOTORA_R_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, MOTORB_R_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, MOTORC_R_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, MOTORD_R_Pin, GPIO_PIN_SET);
}

void Motor_AllRoff(){
	HAL_GPIO_WritePin(GPIOA, MOTORA_R_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, MOTORB_R_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, MOTORC_R_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, MOTORD_R_Pin, GPIO_PIN_RESET);
}