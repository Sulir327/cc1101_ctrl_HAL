/**
  ******************************************************************************
  * @file    bsp_bsp_adc.c
  * @author  phoenix
  * @version V1.0
  * @date    10-November-2017
  * @brief   adc driver
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */ 
#include "./adc/bsp_adc.h"

uint16_t ADC_ConvertedValue[3];
DMA_HandleTypeDef DMA_Init_Handle;
ADC_HandleTypeDef ADC_Handle1;
ADC_HandleTypeDef ADC_Handle2;
ADC_HandleTypeDef ADC_Handle3;
ADC_ChannelConfTypeDef ADC_Config;

static void MMA7361L_ADC_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	// ʹ�� GPIO ʱ��
	MMA7361L_SL_GPIO_CLK_ENABLE();
	MMA7361L_GS_GPIO_CLK_ENABLE();
	MMA7361L_ADC1_GPIO_CLK_ENABLE();
	MMA7361L_ADC2_GPIO_CLK_ENABLE();
	MMA7361L_ADC3_GPIO_CLK_ENABLE();
		
	// ���� IO
	GPIO_InitStructure.Pin = MMA7361L_ADC1_GPIO_PIN;
	GPIO_InitStructure.Mode = GPIO_MODE_ANALOG;	    
  GPIO_InitStructure.Pull = GPIO_NOPULL ; //������������
	HAL_GPIO_Init(MMA7361L_ADC1_GPIO_PORT, &GPIO_InitStructure);

	// ���� IO
	GPIO_InitStructure.Pin = MMA7361L_ADC2_GPIO_PIN;
	GPIO_InitStructure.Mode = GPIO_MODE_ANALOG;	    
  GPIO_InitStructure.Pull = GPIO_NOPULL ; //������������
	HAL_GPIO_Init(MMA7361L_ADC2_GPIO_PORT, &GPIO_InitStructure);
	
	// ���� IO
	GPIO_InitStructure.Pin = MMA7361L_ADC3_GPIO_PIN;
	GPIO_InitStructure.Mode = GPIO_MODE_ANALOG;	    
  GPIO_InitStructure.Pull = GPIO_NOPULL ; //������������
	HAL_GPIO_Init(MMA7361L_ADC3_GPIO_PORT, &GPIO_InitStructure);

	// ���� IO
	GPIO_InitStructure.Pin = MMA7361L_SL_GPIO_PIN;
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStructure.Pull  = GPIO_NOPULL;
	GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;
	HAL_GPIO_Init(MMA7361L_SL_GPIO_PORT, &GPIO_InitStructure);
	
	// ���� IO
	GPIO_InitStructure.Pin = MMA7361L_GS_GPIO_PIN;
	HAL_GPIO_Init(MMA7361L_GS_GPIO_PORT, &GPIO_InitStructure);
}

static void MMA7361L_ADC_Mode_Config(void)
{
	ADC_MultiModeTypeDef   mode;
  // ------------------DMA Init �ṹ����� ��ʼ��--------------------------
  // ADC1ʹ��DMA2��������0��ͨ��0��������ֲ�̶�����
  // ����DMAʱ��
  MMA7361L_ADC_DMA_CLK_ENABLE(); 
	// ���ݴ���ͨ��
	DMA_Init_Handle.Instance = MMA7361L_ADC_DMA_STREAM;	
  // ���ݴ��䷽��Ϊ���赽�洢��
	DMA_Init_Handle.Init.Direction = DMA_PERIPH_TO_MEMORY;	
	// ����Ĵ���ֻ��һ������ַ���õ���
	DMA_Init_Handle.Init.PeriphInc = DMA_PINC_DISABLE;
  // �洢����ַ�̶�
	DMA_Init_Handle.Init.MemInc = DMA_MINC_ENABLE; 
  // �������ݴ�СΪ���֣��������ֽ�
	DMA_Init_Handle.Init.PeriphDataAlignment = DMA_PDATAALIGN_HALFWORD; 
  // �洢�����ݴ�СҲΪ���֣����������ݴ�С��ͬ
	DMA_Init_Handle.Init.MemDataAlignment = DMA_MDATAALIGN_HALFWORD;	
	// ѭ������ģʽ
	DMA_Init_Handle.Init.Mode = DMA_CIRCULAR;
  // DMA ����ͨ�����ȼ�Ϊ�ߣ���ʹ��һ��DMAͨ��ʱ�����ȼ����ò�Ӱ��
	DMA_Init_Handle.Init.Priority = DMA_PRIORITY_HIGH;
  // ��ֹDMA FIFO	��ʹ��ֱ��ģʽ
  DMA_Init_Handle.Init.FIFOMode = DMA_FIFOMODE_DISABLE;  
  // FIFO ��С��FIFOģʽ��ֹʱ�������������	
  DMA_Init_Handle.Init.FIFOThreshold = DMA_FIFO_THRESHOLD_HALFFULL;
  DMA_Init_Handle.Init.MemBurst = DMA_MBURST_SINGLE;
  DMA_Init_Handle.Init.PeriphBurst = DMA_PBURST_SINGLE;  
	// ѡ�� DMA ͨ����ͨ������������
  DMA_Init_Handle.Init.Channel = MMA7361L_ADC_DMA_CHANNEL;
  // ��ʼ��DMA�������൱��һ����Ĺܵ����ܵ������кܶ�ͨ��
	HAL_DMA_Init(&DMA_Init_Handle);
	
	
	// ����ADCʱ��
	MMA7361L_ADC1_CLK_ENABLE();
  MMA7361L_ADC2_CLK_ENABLE();
	MMA7361L_ADC3_CLK_ENABLE();
	
  // -------------------ADC1 Init �ṹ�� ���� ��ʼ��--------------------------
	ADC_Handle1.Instance = MMA7361L_ADC1;
	// ʱ��Ϊfpclk 4��Ƶ
  ADC_Handle1.Init.ClockPrescaler = ADC_CLOCKPRESCALER_PCLK_DIV4;
  // ADC �ֱ���
  ADC_Handle1.Init.Resolution = ADC_RESOLUTION_12B;
  // ��ֹɨ��ģʽ����ͨ���ɼ�����Ҫ	
  ADC_Handle1.Init.ScanConvMode = DISABLE; 
  // ����ת��	
  ADC_Handle1.Init.ContinuousConvMode = ENABLE;
	// ������ת��
	ADC_Handle1.Init.DiscontinuousConvMode = DISABLE;
	// ������ת������
	ADC_Handle1.Init.NbrOfDiscConversion = 0;	
  // ��ֹ�ⲿ���ش���
  ADC_Handle1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  // �ⲿ����ͨ����������ʹ�������������ֵ��㸳ֵ����
  //ADC_Handle1.Init.ExternalTrigConv = ADC_EXTERNALTRIGCONV_T1_CC1;
  // �����Ҷ���	
  ADC_Handle1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  // ת��ͨ�� 1��
  ADC_Handle1.Init.NbrOfConversion = 1;
	//ʹ������ת������
	ADC_Handle1.Init.DMAContinuousRequests = ENABLE;
	//ת����ɱ�־
	ADC_Handle1.Init.EOCSelection = DISABLE;    
	// ��ʼ��ADC	                          
	HAL_ADC_Init(&ADC_Handle1);
	
  //---------------------------------------------------------------------------	
	// ���� ADC1 ͨ��13ת��˳��Ϊ1����һ��ת��������ʱ��Ϊ3��ʱ������
	ADC_Config.Channel      = MMA7361L_ADC1_CHANNEL;
	ADC_Config.Rank         = 1;    
	ADC_Config.SamplingTime = ADC_SAMPLETIME_3CYCLES;// ����ʱ����	
	ADC_Config.Offset       = 0;
	HAL_ADC_ConfigChannel(&ADC_Handle1, &ADC_Config);
  //---------------------------------------------------------------------------

  // -------------------ADC2 Init �ṹ�� ���� ��ʼ��--------------------------
	ADC_Handle2.Instance = MMA7361L_ADC2;
	// ʱ��Ϊfpclk 4��Ƶ
  ADC_Handle2.Init.ClockPrescaler = ADC_CLOCKPRESCALER_PCLK_DIV4;
  // ADC �ֱ���
  ADC_Handle2.Init.Resolution = ADC_RESOLUTION_12B;
  // ��ֹɨ��ģʽ����ͨ���ɼ�����Ҫ	
  ADC_Handle2.Init.ScanConvMode = DISABLE; 
  // ����ת��	
  ADC_Handle2.Init.ContinuousConvMode = ENABLE;
	// ������ת��
	ADC_Handle2.Init.DiscontinuousConvMode = DISABLE;
	// ������ת������
	ADC_Handle2.Init.NbrOfDiscConversion = 0;	
  // ��ֹ�ⲿ���ش���
  ADC_Handle2.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  // �ⲿ����ͨ����������ʹ�������������ֵ��㸳ֵ����
  //ADC_Handle2.Init.ExternalTrigConv = ADC_EXTERNALTRIGCONV_T1_CC1;
  // �����Ҷ���	
  ADC_Handle2.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  // ת��ͨ�� 1��
  ADC_Handle2.Init.NbrOfConversion = 1;
	//ʹ������ת������
	ADC_Handle2.Init.DMAContinuousRequests = ENABLE;
	//ת����ɱ�־
	ADC_Handle2.Init.EOCSelection = DISABLE;    
	// ��ʼ��ADC	                          
	HAL_ADC_Init(&ADC_Handle2);
	
  //---------------------------------------------------------------------------	
	// ���� ADC1 ͨ��13ת��˳��Ϊ1����һ��ת��������ʱ��Ϊ3��ʱ������
	ADC_Config.Channel      = MMA7361L_ADC2_CHANNEL;
	ADC_Config.Rank         = 1;    
	ADC_Config.SamplingTime = ADC_SAMPLETIME_3CYCLES;// ����ʱ����	
	ADC_Config.Offset       = 0;
	HAL_ADC_ConfigChannel(&ADC_Handle2, &ADC_Config);
  //---------------------------------------------------------------------------

  // -------------------ADC3 Init �ṹ�� ���� ��ʼ��--------------------------
	ADC_Handle3.Instance = MMA7361L_ADC3;
	// ʱ��Ϊfpclk 4��Ƶ
  ADC_Handle3.Init.ClockPrescaler = ADC_CLOCKPRESCALER_PCLK_DIV4;
  // ADC �ֱ���
  ADC_Handle3.Init.Resolution = ADC_RESOLUTION_12B;
  // ��ֹɨ��ģʽ����ͨ���ɼ�����Ҫ	
  ADC_Handle3.Init.ScanConvMode = DISABLE; 
  // ����ת��	
  ADC_Handle3.Init.ContinuousConvMode = ENABLE;
	// ������ת��
	ADC_Handle3.Init.DiscontinuousConvMode = DISABLE;
	// ������ת������
	ADC_Handle3.Init.NbrOfDiscConversion = 0;	
  // ��ֹ�ⲿ���ش���
  ADC_Handle3.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  // �ⲿ����ͨ����������ʹ�������������ֵ��㸳ֵ����
  //ADC_Handle3.Init.ExternalTrigConv = ADC_EXTERNALTRIGCONV_T1_CC1;
  // �����Ҷ���	
  ADC_Handle3.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  // ת��ͨ�� 1��
  ADC_Handle3.Init.NbrOfConversion = 1;
	//ʹ������ת������
	ADC_Handle3.Init.DMAContinuousRequests = ENABLE;
	//ת����ɱ�־
	ADC_Handle3.Init.EOCSelection = DISABLE;    
	// ��ʼ��ADC	                          
	HAL_ADC_Init(&ADC_Handle3);
	
  //---------------------------------------------------------------------------	
	// ���� ADC1 ͨ��13ת��˳��Ϊ1����һ��ת��������ʱ��Ϊ3��ʱ������
	ADC_Config.Channel      = MMA7361L_ADC3_CHANNEL;
	ADC_Config.Rank         = 1;    
	ADC_Config.SamplingTime = ADC_SAMPLETIME_3CYCLES;// ����ʱ����	
	ADC_Config.Offset       = 0;
	HAL_ADC_ConfigChannel(&ADC_Handle3, &ADC_Config);
  //---------------------------------------------------------------------------

	/*��������AD����*/
	mode.Mode = ADC_TRIPLEMODE_REGSIMULT;
	mode.DMAAccessMode = ADC_DMAACCESSMODE_1;
	mode.TwoSamplingDelay = ADC_TWOSAMPLINGDELAY_5CYCLES;
    
	HAL_ADCEx_MultiModeConfigChannel(&ADC_Handle1, &mode);
    
	HAL_ADC_Start(&ADC_Handle2);
	HAL_ADC_Start(&ADC_Handle3);	
    
	__HAL_LINKDMA(&ADC_Handle1, DMA_Handle, DMA_Init_Handle);   
	__HAL_LINKDMA(&ADC_Handle2, DMA_Handle, DMA_Init_Handle);
	__HAL_LINKDMA(&ADC_Handle3, DMA_Handle, DMA_Init_Handle);  
	HAL_ADCEx_MultiModeStart_DMA(&ADC_Handle1, (uint32_t *)ADC_ConvertedValue, 3);
}


void MMA7361L_Config(void)
{
	MMA7361L_ADC_GPIO_Config();
	MMA7361L_ADC_Mode_Config();
}



