/**
  ******************************************************************************
  * @file    bsp_spi.h
  * @author  phoenix
  * @version V1.0.0
  * @date    20-October-2017
  * @brief   This file provides set of firmware functions to manage Leds ,
  *          push-button and spi available on STM32F4-Discovery Kit from STMicroelectronics.
  ******************************************************************************
  * @attention
  *
  ******************************************************************************
  */ 

#ifndef _BSP_SPI_H_
#define _BSP_SPI_H_

#include "stm32f4xx.h"
#include "./cc1101/cc1101.h"
#include "./usart/bsp_debug_usart.h"
extern void Error_Handler(void);
/**
  * @brief  CC1101 SPI Interface pins
  */
#define CC1101_SPI                      SPI2
#define CC1101_SPI_CLK_ENABLE()  				__HAL_RCC_SPI2_CLK_ENABLE()

#define CC1101_SPI_SCK_PIN              GPIO_PIN_13                 /* PB.13 */
#define CC1101_SPI_SCK_GPIO_PORT        GPIOB                       /* GPIOB */
#define CC1101_SPI_SCK_GPIO_CLK_ENABLE()		__HAL_RCC_GPIOB_CLK_ENABLE()
#define CC1101_SPI_SCK_AF               GPIO_AF5_SPI2

#define CC1101_SPI_MISO_PIN             GPIO_PIN_14                 /* PB.14 */
#define CC1101_SPI_MISO_GPIO_PORT       GPIOB                       /* GPIOB */
#define CC1101_SPI_MISO_GPIO_CLK_ENABLE()  	__HAL_RCC_GPIOB_CLK_ENABLE()
#define CC1101_SPI_MISO_AF              GPIO_AF5_SPI2

#define CC1101_SPI_MOSI_PIN             GPIO_PIN_15                 /* PB.15 */
#define CC1101_SPI_MOSI_GPIO_PORT       GPIOB                       /* GPIOB */
#define CC1101_SPI_MOSI_GPIO_CLK_ENABLE()  	__HAL_RCC_GPIOB_CLK_ENABLE()
#define CC1101_SPI_MOSI_AF              GPIO_AF5_SPI2

/*===========================================================================
------------------------------Internal IMPORT functions----------------------
you must offer the following functions for this module
1. uint8_t SPI_ExchangeByte(uint8_t input); // SPI Send and Receive function
2. CC1101_CSN_LOW();                        // Pull down the CSN line
3. CC1101_CSN_HIGH();                       // Pull up the CSN Line
===========================================================================*/
// CC1101��ؿ������Ŷ��壬 CSN(PE2), IRQ(PE4), GDO2(PE6) 
#define CC1101_SPI_CSN_PIN              GPIO_PIN_2                  /* PE.02 */
#define CC1101_SPI_CSN_GPIO_PORT        GPIOE                       /* GPIOE */
#define CC1101_SPI_CSN_GPIO_CLK_ENABLE()		__HAL_RCC_GPIOE_CLK_ENABLE()

#define CC1101_IRQ_PIN                  GPIO_PIN_4                  /* PE.04 */
#define CC1101_IRQ_GPIO_PORT            GPIOE                       /* GPIOE */
#define CC1101_IRQ_GPIO_CLK_ENABLE() 		__HAL_RCC_GPIOE_CLK_ENABLE()

#define CC1101_GDO2_PIN                 GPIO_PIN_6                  /* PE.06 */
#define CC1101_GDO2_GPIO_PORT           GPIOE                       /* GPIOE */
#define CC1101_GDO2_GPIO_CLK_ENABLE()  	__HAL_RCC_GPIOE_CLK_ENABLE()
#define CC1101_GDO2_EXTI_IRQ          	EXTI9_5_IRQn
#define CC1101_GDO2_IRQHandler         	EXTI9_5_IRQHandler

#define CC1101_CSN_LOW()                HAL_GPIO_WritePin(CC1101_SPI_CSN_GPIO_PORT, CC1101_SPI_CSN_PIN, GPIO_PIN_RESET)

#define CC1101_CSN_HIGH()               HAL_GPIO_WritePin(CC1101_SPI_CSN_GPIO_PORT, CC1101_SPI_CSN_PIN, GPIO_PIN_SET)

#define CC1101_IRQ_READ()               HAL_GPIO_ReadPin(CC1101_IRQ_GPIO_PORT, CC1101_IRQ_PIN)

#define CC1101_GDO2_READ()             	HAL_GPIO_ReadPin(CC1101_GDO2_GPIO_PORT, CC1101_GDO2_PIN)

/**
  * @brief  LED Interface pins
  */
#define LED3_Orange_PIN     						GPIO_PIN_13
#define LED4_Green_PIN      						GPIO_PIN_12
#define LED5_Red_PIN        						GPIO_PIN_14
#define	LED6_Blue_PIN       						GPIO_PIN_15
#define	LED_GPIO_PORT      	 						GPIOD
#define	LED_GPIO_CLK_ENABLE()        		__HAL_RCC_GPIOD_CLK_ENABLE()

/* ֱ�Ӳ����Ĵ����ķ�������IO */
#define	digitalHi(p,i)									{p->BSRR=i;}			  						//����Ϊ�ߵ�ƽ		
#define digitalLo(p,i)									{p->BSRR=(uint32_t)i << 16;}		//����͵�ƽ
#define digitalToggle(p,i)							{p->ODR ^=i;}										//�����ת״̬

// LED����������(ON)��, (OFF)�رգ�(TOG)��ת
#define LED3_Orange_OFF()   						HAL_GPIO_WritePin(LED_GPIO_PORT, LED3_Orange_PIN, GPIO_PIN_RESET)        
#define LED3_Orange_ON()    						HAL_GPIO_WritePin(LED_GPIO_PORT, LED3_Orange_PIN, GPIO_PIN_SET)
#define LED3_Orange_TOG()   						digitalToggle(LED_GPIO_PORT,LED3_Orange_PIN)

#define LED4_Green_OFF()    						HAL_GPIO_WritePin(LED_GPIO_PORT, LED4_Green_PIN, GPIO_PIN_RESET)        
#define LED4_Green_ON()     						HAL_GPIO_WritePin(LED_GPIO_PORT, LED4_Green_PIN, GPIO_PIN_SET)
#define LED4_Green_TOG()    						digitalToggle(LED_GPIO_PORT,LED4_Green_PIN)

#define LED5_Red_OFF()      						HAL_GPIO_WritePin(LED_GPIO_PORT, LED5_Red_PIN, GPIO_PIN_RESET)        
#define LED5_Red_ON()       						HAL_GPIO_WritePin(LED_GPIO_PORT, LED5_Red_PIN, GPIO_PIN_SET)
#define LED5_Red_TOG()      						digitalToggle(LED_GPIO_PORT,LED5_Red_PIN)

#define LED6_Blue_OFF()     						HAL_GPIO_WritePin(LED_GPIO_PORT, LED6_Blue_PIN, GPIO_PIN_RESET)        
#define LED6_Blue_ON()      						HAL_GPIO_WritePin(LED_GPIO_PORT, LED6_Blue_PIN, GPIO_PIN_SET)
#define LED6_Blue_TOG()     						digitalToggle(LED_GPIO_PORT,LED6_Blue_PIN)

void GPIO_Config(void);                // ��ʼ��ͨ��IO�˿�
void SPI_Config(void);                 // ��ʼ��SPI

uint8_t SPI_ExchangeByte(uint8_t input);  // ͨ��SPI�������ݽ���
void SPI_SendData(SPI_HandleTypeDef *hspi, uint16_t Data);
uint16_t SPI_ReceiveData(SPI_HandleTypeDef *hspi);
FlagStatus SPI_GetFlagStatus(SPI_HandleTypeDef *hspi, uint16_t SPI_FLAG);

#endif //_BSP_SPI_H_

/******************* END OF FILE ******************/
