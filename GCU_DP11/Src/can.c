/**
  ******************************************************************************
  * File Name          : CAN.c
  * Description        : This file provides code for the configuration
  *                      of the CAN instances.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "can.h"

/* USER CODE BEGIN 0 */


CAN_FilterTypeDef CAN_Filter_Config;

CAN_RxHeaderTypeDef CAN_Received_0_Message_Header;
CAN_RxHeaderTypeDef CAN_Received_1_Message_Header;
uint8_t CAN_Received_0_Message_Data[8];
uint8_t CAN_Received_1_Message_Data[8];

uint8_t GCU_Packet_Data[8];
CAN_TxHeaderTypeDef GCU_Packet_Header;

/* USER CODE END 0 */

CAN_HandleTypeDef hcan2;

/* CAN2 init function */
void MX_CAN2_Init(void)
{

  hcan2.Instance = CAN2;
  hcan2.Init.Prescaler = 3;
  hcan2.Init.Mode = CAN_MODE_NORMAL;
  hcan2.Init.SyncJumpWidth = CAN_SJW_1TQ;
  hcan2.Init.TimeSeg1 = CAN_BS1_15TQ;
  hcan2.Init.TimeSeg2 = CAN_BS2_2TQ;
  hcan2.Init.TimeTriggeredMode = DISABLE;
  hcan2.Init.AutoBusOff = DISABLE;
  hcan2.Init.AutoWakeUp = DISABLE;
  hcan2.Init.AutoRetransmission = DISABLE;
  hcan2.Init.ReceiveFifoLocked = DISABLE;
  hcan2.Init.TransmitFifoPriority = DISABLE;
  if (HAL_CAN_Init(&hcan2) != HAL_OK)
  {
    Error_Handler();
  }

}

void HAL_CAN_MspInit(CAN_HandleTypeDef* canHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(canHandle->Instance==CAN2)
  {
  /* USER CODE BEGIN CAN2_MspInit 0 */

  /* USER CODE END CAN2_MspInit 0 */
    /* CAN2 clock enable */
    __HAL_RCC_CAN3_CLK_ENABLE();
    __HAL_RCC_CAN2_CLK_ENABLE();
    __HAL_RCC_CAN1_CLK_ENABLE();
  
    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**CAN2 GPIO Configuration    
    PB12     ------> CAN2_RX
    PB13     ------> CAN2_TX 
    */
    GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_13;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF9_CAN2;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* CAN2 interrupt Init */
    HAL_NVIC_SetPriority(CAN2_TX_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(CAN2_TX_IRQn);
    HAL_NVIC_SetPriority(CAN2_RX0_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(CAN2_RX0_IRQn);
    HAL_NVIC_SetPriority(CAN2_RX1_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(CAN2_RX1_IRQn);
  /* USER CODE BEGIN CAN2_MspInit 1 */

  /* USER CODE END CAN2_MspInit 1 */
  }
}

void HAL_CAN_MspDeInit(CAN_HandleTypeDef* canHandle)
{

  if(canHandle->Instance==CAN2)
  {
  /* USER CODE BEGIN CAN2_MspDeInit 0 */

  /* USER CODE END CAN2_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_CAN3_CLK_DISABLE();
    __HAL_RCC_CAN2_CLK_DISABLE();
    __HAL_RCC_CAN1_CLK_DISABLE();
  
    /**CAN2 GPIO Configuration    
    PB12     ------> CAN2_RX
    PB13     ------> CAN2_TX 
    */
    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_12|GPIO_PIN_13);

    /* CAN2 interrupt Deinit */
    HAL_NVIC_DisableIRQ(CAN2_TX_IRQn);
    HAL_NVIC_DisableIRQ(CAN2_RX0_IRQn);
    HAL_NVIC_DisableIRQ(CAN2_RX1_IRQn);
  /* USER CODE BEGIN CAN2_MspDeInit 1 */

  /* USER CODE END CAN2_MspDeInit 1 */
  }
} 

/* USER CODE BEGIN 1 */
void CAN2_Filter_Setup(void)
{
	/*mittente: NUCLEOF4
	Id:     (0011111xxxx)
	Mask: 0x1DE0   (0111 1111 0000)
	Filter: 0x5E0  (0001 1111 0000)*/
	
	CAN_Filter_Config.FilterBank = 14;
  CAN_Filter_Config.FilterMode = CAN_FILTERMODE_IDMASK;
  CAN_Filter_Config.FilterScale = CAN_FILTERSCALE_32BIT;
	CAN_Filter_Config.FilterIdHigh = (0x1F0 << 5);
  CAN_Filter_Config.FilterIdLow = 0x0000;
  CAN_Filter_Config.FilterMaskIdHigh = 0x0000;//(0x7F0  << 5);
  CAN_Filter_Config.FilterMaskIdLow = 0x0000;
	CAN_Filter_Config.FilterFIFOAssignment = CAN_RX_FIFO0;
  CAN_Filter_Config.FilterActivation = ENABLE;	
  CAN_Filter_Config.SlaveStartFilterBank = 14;
		
	HAL_CAN_ConfigFilter(&hcan2, &CAN_Filter_Config);
}	


void CAN2_Start(void)
{
	CAN2_Filter_Setup();
	
	HAL_CAN_ActivateNotification(&hcan2, CAN_IT_TX_MAILBOX_EMPTY);
	HAL_CAN_ActivateNotification(&hcan2, CAN_IT_RX_FIFO0_MSG_PENDING);
	HAL_CAN_ActivateNotification(&hcan2, CAN_IT_RX_FIFO1_MSG_PENDING);
	HAL_CAN_Start(&hcan2);
	//HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin);
}	


void CAN2_Send_GCU_Packet(void)
{
	//HAL_GPIO_TogglePin(GreenPin_GPIO_Port,GreenPin_Pin);
	uint32_t GCU_Packet_Mailbox;
	GCU_Packet_Header.StdId = GCU_ID;
  GCU_Packet_Header.RTR = CAN_RTR_DATA;
  GCU_Packet_Header.IDE = CAN_ID_STD;
  GCU_Packet_Header.DLC = 8;
  GCU_Packet_Header.TransmitGlobalTime = DISABLE;
  GCU_Packet_Data[0] = 6;
  GCU_Packet_Data[1] = 0;
  GCU_Packet_Data[2] = 10;
  GCU_Packet_Data[3] = 0;
  GCU_Packet_Data[4] = 0;
  GCU_Packet_Data[5] = 6;
	GCU_Packet_Data[6] = 0;
  GCU_Packet_Data[7] = 5;
	
	HAL_CAN_AddTxMessage(&hcan2, &GCU_Packet_Header, GCU_Packet_Data, &GCU_Packet_Mailbox);
}


void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
	HAL_CAN_GetRxMessage(&hcan2, CAN_RX_FIFO0, &CAN_Received_0_Message_Header, CAN_Received_0_Message_Data);
	
	uint16_t id = (uint16_t) CAN_Received_0_Message_Header.StdId;

	rtU.CAN[0] =  id >> 8;
	rtU.CAN[1] = 0; rtU.CAN[1] |= id;
	for (int i=2; i<10; i++)
		rtU.CAN[i] = CAN_Received_0_Message_Data[i-2];
	
	if(rtU.SelectMode == CAN_READ_MODE)
	{
		GCU_Model_genCode_step2();
	}
	
	HAL_GPIO_TogglePin(GreenLed_GPIO_Port, GreenLed_Pin);

}
/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
