#ifndef __DEBUG_USART_H
#define	__DEBUG_USART_H

#include "stm32f4xx.h"
#include <stdio.h>
extern void Error_Handler(void);
extern UART_HandleTypeDef UartHandle;

//Òý½Å¶¨Òå
/*******************************************************/
#define DEBUG_USART                             USART3
#define DEBUG_USART_CLK_ENABLE()       	        __USART3_CLK_ENABLE();
#define DEBUG_USART_BAUDRATE                    115200

#define RCC_PERIPHCLK_UARTx               			RCC_PERIPHCLK_USART3
#define RCC_UARTxCLKSOURCE_SYSCLK         			RCC_USART3CLKSOURCE_SYSCLK

#define DEBUG_USART_RX_GPIO_PORT                GPIOD
#define DEBUG_USART_RX_GPIO_CLK_ENABLE()				__HAL_RCC_GPIOD_CLK_ENABLE()
#define DEBUG_USART_RX_PIN                      GPIO_PIN_9
#define DEBUG_USART_RX_AF                       GPIO_AF7_USART3

#define DEBUG_USART_TX_GPIO_PORT                GPIOD
#define DEBUG_USART_TX_GPIO_CLK_ENABLE()    		__HAL_RCC_GPIOD_CLK_ENABLE()
#define DEBUG_USART_TX_PIN                      GPIO_PIN_8
#define DEBUG_USART_TX_AF                       GPIO_AF7_USART3

#define DEBUG_USART_IRQHandler                  USART3_IRQHandler
#define DEBUG_USART_IRQ                 	    	USART3_IRQn
/************************************************************/

void Debug_USART_Config(void);
void Usart_SendByte( UART_HandleTypeDef *huart, uint8_t ch);
void Usart_SendString( UART_HandleTypeDef *huart, uint8_t *str);
void Usart_SendHalfWord( UART_HandleTypeDef *huart, uint16_t ch);
void Scanf_Function(void);
#endif /* __USART1_H */
