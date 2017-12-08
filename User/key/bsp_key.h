#ifndef __KEY_H
#define	__KEY_H

#include "stm32f4xx.h"

//���Ŷ���
/*******************************************************/
#define USER_KEY_PIN                  GPIO_PIN_0                 
#define USER_KEY_GPIO_PORT            GPIOA                      
#define USER_KEY_GPIO_CLK_ENABLE()    __HAL_RCC_GPIOA_CLK_ENABLE()
/*******************************************************/

 /** �������±��ú�
	* ��������Ϊ�ߵ�ƽ������ KEY_ON=1�� KEY_OFF=0
	* ����������Ϊ�͵�ƽ���Ѻ����ó�KEY_ON=0 ��KEY_OFF=1 ����
	*/
#define KEY_ON	1
#define KEY_OFF	0

void Key_GPIO_Config(void);
uint8_t Key_Scan(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin);

#endif /* __LED_H */

