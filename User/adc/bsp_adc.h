#ifndef __BSP_ADC_H
#define	__BSP_ADC_H

#include "stm32f4xx.h"

/*=====================sleep IO======================*/
// sleep IO�궨��
#define MMA7361L_SL_GPIO_PORT				GPIOE
#define MMA7361L_SL_GPIO_PIN				GPIO_PIN_7
#define MMA7361L_SL_GPIO_CLK_ENABLE()		__HAL_RCC_GPIOE_CLK_ENABLE()

#define MMA7361L_SL_ON()       			HAL_GPIO_WritePin(MMA7361L_SL_GPIO_PORT, MMA7361L_SL_GPIO_PIN, GPIO_PIN_RESET)
#define MMA7361L_SL_OFF()        		HAL_GPIO_WritePin(MMA7361L_SL_GPIO_PORT, MMA7361L_SL_GPIO_PIN, GPIO_PIN_SET)

/*=====================g-select IO======================*/
// g-select IO�궨��
#define MMA7361L_GS_GPIO_PORT				GPIOC
#define MMA7361L_GS_GPIO_PIN				GPIO_PIN_13
#define MMA7361L_GS_GPIO_CLK_ENABLE()		__HAL_RCC_GPIOC_CLK_ENABLE()

#define MMA7361L_GS_1G5()       		HAL_GPIO_WritePin(MMA7361L_GS_GPIO_PORT, MMA7361L_GS_GPIO_PIN, GPIO_PIN_RESET)
#define MMA7361L_GS_6G()        		HAL_GPIO_WritePin(MMA7361L_GS_GPIO_PORT, MMA7361L_GS_GPIO_PIN, GPIO_PIN_SET)

/*=====================ͨ��1 IO======================*/
// ADC IO�궨��
#define MMA7361L_ADC1_GPIO_PORT			GPIOC
#define MMA7361L_ADC1_GPIO_PIN			GPIO_PIN_5
#define MMA7361L_ADC1_GPIO_CLK_ENABLE()		__HAL_RCC_GPIOC_CLK_ENABLE()

// ADC ��ź궨��
#define MMA7361L_ADC1             	ADC1
#define MMA7361L_ADC1_CLK_ENABLE()	__HAL_RCC_ADC1_CLK_ENABLE()
#define MMA7361L_ADC1_CHANNEL     	ADC_CHANNEL_15
/*=====================ͨ��2 IO ======================*/
// ADC IO�궨��
#define MMA7361L_ADC2_GPIO_PORT    	GPIOC
#define MMA7361L_ADC2_GPIO_PIN     	GPIO_PIN_1
#define MMA7361L_ADC2_GPIO_CLK_ENABLE()		__HAL_RCC_GPIOC_CLK_ENABLE()

// ADC ��ź궨��
#define MMA7361L_ADC2             	ADC2
#define MMA7361L_ADC2_CLK_ENABLE()	__HAL_RCC_ADC2_CLK_ENABLE()
#define MMA7361L_ADC2_CHANNEL     	ADC_CHANNEL_11
/*=====================ͨ��3 IO ======================*/
// ADC IO�궨��
#define MMA7361L_ADC3_GPIO_PORT    	GPIOC
#define MMA7361L_ADC3_GPIO_PIN     	GPIO_PIN_2
#define MMA7361L_ADC3_GPIO_CLK_ENABLE()		__HAL_RCC_GPIOC_CLK_ENABLE()

// ADC ��ź궨��
#define MMA7361L_ADC3            		ADC3
#define MMA7361L_ADC3_CLK_ENABLE()	__HAL_RCC_ADC3_CLK_ENABLE()
#define MMA7361L_ADC3_CHANNEL		   	ADC_CHANNEL_12

// ADC CDR�Ĵ����궨�壬ADCת���������ֵ����������
#define MMA7361L_ADC_CDR_ADDR    		((uint32_t)0x40012308)

// ADC DMA ͨ���궨�壬��������ʹ��DMA����
#define MMA7361L_ADC_DMA_CLK_ENABLE()		__HAL_RCC_DMA2_CLK_ENABLE()
#define MMA7361L_ADC_DMA_CHANNEL  	DMA_CHANNEL_0
#define MMA7361L_ADC_DMA_STREAM   	DMA2_Stream0


void MMA7361L_Config(void);

#endif /* __BSP_ADC_H */



