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
  * @brief  ���ð����õ���I/O��
  * @param  ��
  * @retval ��
  */
void Key_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/*��������GPIO�ڵ�ʱ��*/
	USER_KEY_GPIO_CLK_ENABLE();
	
  /*ѡ�񰴼�������*/
	GPIO_InitStructure.Pin = USER_KEY_PIN; 
  
  /*��������Ϊ����ģʽ*/
	GPIO_InitStructure.Mode = GPIO_MODE_INPUT; 
  
  /*�������Ų�����Ҳ������*/
	GPIO_InitStructure.Pull = GPIO_NOPULL;
	
  /*ʹ������Ľṹ���ʼ������*/
	HAL_GPIO_Init(USER_KEY_GPIO_PORT, &GPIO_InitStructure);    

}

/**
  * @brief	����Ƿ��а�������     
  *	@param 	GPIOx:����Ķ˿�, x�����ǣ�A...K�� 
	*	@param 	GPIO_PIN:����Ķ˿�λ�� ������GPIO_PIN_x��x������0...15��
  * @retval  ������״̬
  *		@arg KEY_ON:��������
  *		@arg KEY_OFF:����û����
  */
uint8_t Key_Scan(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin)
{
	/*����Ƿ��а������� */
	if(HAL_GPIO_ReadPin(GPIOx,GPIO_Pin) == GPIO_PIN_SET )  
	{	 
		/*�ȴ������ͷ� */
		while(HAL_GPIO_ReadPin(GPIOx,GPIO_Pin) == GPIO_PIN_SET);   
		return KEY_ON;
	}
	else
		return KEY_OFF;
}
/*********************************************END OF FILE**********************/
