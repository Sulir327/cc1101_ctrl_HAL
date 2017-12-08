/**
  ******************************************************************************
  * @file    bsp_key.c
  * @author  phoenix
  * @version V1.0
  * @date    28-November-2017
  * @brief   
  ******************************************************************************
  * @attention
  *
  ******************************************************************************
  */ 
  
#include "./key/bsp_key.h" 

/**
  * @brief  配置按键用到的I/O口
  * @param  无
  * @retval 无
  */
void Key_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/*开启按键GPIO口的时钟*/
	USER_KEY_GPIO_CLK_ENABLE();
	
  /*选择按键的引脚*/
	GPIO_InitStructure.Pin = USER_KEY_PIN; 
  
  /*设置引脚为输入模式*/
	GPIO_InitStructure.Mode = GPIO_MODE_INPUT; 
  
  /*设置引脚不上拉也不下拉*/
	GPIO_InitStructure.Pull = GPIO_NOPULL;
	
  /*使用上面的结构体初始化按键*/
	HAL_GPIO_Init(USER_KEY_GPIO_PORT, &GPIO_InitStructure);    

}

/**
  * @brief	检测是否有按键按下     
  *	@param 	GPIOx:具体的端口, x可以是（A...K） 
	*	@param 	GPIO_PIN:具体的端口位， 可以是GPIO_PIN_x（x可以是0...15）
  * @retval  按键的状态
  *		@arg KEY_ON:按键按下
  *		@arg KEY_OFF:按键没按下
  */
uint8_t Key_Scan(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin)
{
	/*检测是否有按键按下 */
	if(HAL_GPIO_ReadPin(GPIOx,GPIO_Pin) == GPIO_PIN_SET )  
	{	 
		/*等待按键释放 */
		while(HAL_GPIO_ReadPin(GPIOx,GPIO_Pin) == GPIO_PIN_SET);   
		return KEY_ON;
	}
	else
		return KEY_OFF;
}
/*********************************************END OF FILE**********************/
