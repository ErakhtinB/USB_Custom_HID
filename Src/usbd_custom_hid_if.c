/**
  ******************************************************************************
  * @file           : usbd_custom_hid_if.c
  * @version        : v1.0_Cube
  * @brief          : USB Device Custom HID interface file.
  ******************************************************************************
  * This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * Copyright (c) 2019 STMicroelectronics International N.V. 
  * All rights reserved.
  *
  * Redistribution and use in source and binary forms, with or without 
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice, 
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other 
  *    contributors to this software may be used to endorse or promote products 
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this 
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under 
  *    this license is void and will automatically terminate your rights under 
  *    this license. 
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS" 
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT 
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT 
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "usbd_custom_hid_if.h"

/* USER CODE BEGIN INCLUDE */

/* USER CODE END INCLUDE */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

/* USER CODE END PV */

/** @addtogroup STM32_USB_OTG_DEVICE_LIBRARY
  * @brief Usb device.
  * @{
  */

/** @addtogroup USBD_CUSTOM_HID
  * @{
  */

/** @defgroup USBD_CUSTOM_HID_Private_TypesDefinitions USBD_CUSTOM_HID_Private_TypesDefinitions
  * @brief Private types.
  * @{
  */

/* USER CODE BEGIN PRIVATE_TYPES */
enum led_msg
{
	GREEN_LED_ID = 1,
	ORANGE_LED_ID,
	RED_LED_ID,
	BLUE_LED_ID,
	LED_OFF = 0,
	LED_ON = 1
};
/* USER CODE END PRIVATE_TYPES */

/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID_Private_Defines USBD_CUSTOM_HID_Private_Defines
  * @brief Private defines.
  * @{
  */

/* USER CODE BEGIN PRIVATE_DEFINES */

/* USER CODE END PRIVATE_DEFINES */

/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID_Private_Macros USBD_CUSTOM_HID_Private_Macros
  * @brief Private macros.
  * @{
  */

/* USER CODE BEGIN PRIVATE_MACRO */

/* USER CODE END PRIVATE_MACRO */

/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID_Private_Variables USBD_CUSTOM_HID_Private_Variables
  * @brief Private variables.
  * @{
  */

/** Usb HID report descriptor. */
__ALIGN_BEGIN static uint8_t CUSTOM_HID_ReportDesc_FS[USBD_CUSTOM_HID_REPORT_DESC_SIZE] __ALIGN_END =
{
  /* USER CODE BEGIN 0 */
		0x06, 0x00, 0xff,              // USAGE_PAGE (Generic Desktop)

    0x09, 0x01,                    // USAGE (Vendor Usage 1)

    0xa1, 0x01,                    // COLLECTION (Application)


	
    0x85, 0x01,                    //   REPORT_ID (1)

    0x09, 0x01,                    //   USAGE (Vendor Usage 1)

    0x15, 0x00,                    //   LOGICAL_MINIMUM (0)

    0x25, 0x01,                    //   LOGICAL_MAXIMUM (1)

    0x75, 0x08,                    //   REPORT_SIZE (8)

    0x95, 0x01,                    //   REPORT_COUNT (1)

    0xB1, 0x82,                    //   FEATURE (Data,Var,Abs,Vol)

    0x85, 0x01,                    //   REPORT_ID (1)

    0x09, 0x01,                    //   USAGE (Vendor Usage 1)

    0x91, 0x82,                    //   OUTPUT (Data,Var,Abs,Vol)


    0x85, 0x02,                    //   REPORT_ID (2)

    0x09, 0x02,                    //   USAGE (Vendor Usage 2)

    0x15, 0x00,                    //   LOGICAL_MINIMUM (0)

    0x25, 0x01,                    //   LOGICAL_MAXIMUM (1)

    0x75, 0x08,                    //   REPORT_SIZE (8)

    0x95, 0x01,                    //   REPORT_COUNT (1)

    0xB1, 0x82,                    //   FEATURE (Data,Var,Abs,Vol)

    0x85, 0x02,                    //   REPORT_ID (2)

    0x09, 0x02,                    //   USAGE (Vendor Usage 2)

    0x91, 0x82,                    //   OUTPUT (Data,Var,Abs,Vol)

 

    0x85, 0x03,                    //   REPORT_ID (3)

    0x09, 0x03,                    //   USAGE (Vendor Usage 3)

    0x15, 0x00,                    //   LOGICAL_MINIMUM (0)

    0x25, 0x01,                    //   LOGICAL_MAXIMUM (255)

    0x75, 0x08,                    //   REPORT_SIZE (8)

    0x95, 0x01,                    //   REPORT_COUNT (1)

    0xB1, 0x82,                    //   FEATURE (Data,Var,Abs,Vol)

    0x85, 0x03,                    //   REPORT_ID (3)

    0x09, 0x03,                    //   USAGE (Vendor Usage 3)

    0x91, 0x82,                    //   OUTPUT (Data,Var,Abs,Vol)

 

    0x85, 0x04,                    //   REPORT_ID (4)

    0x09, 0x04,                    //   USAGE (Vendor Usage 4)

    0x15, 0x00,                    //   LOGICAL_MINIMUM (0)

    0x25, 0x01,                    //   LOGICAL_MAXIMUM (255)

    0x75, 0x08,                    //   REPORT_SIZE (8)

    0x95, 0x01,                    //   REPORT_COUNT (1)

    0xB1, 0x82,                    //   FEATURE (Data,Var,Abs,Vol)

    0x85, 0x04,                    //   REPORT_ID (4)

    0x09, 0x04,                    //   USAGE (Vendor Usage 4)

    0x91, 0x82,                    //   OUTPUT (Data,Var,Abs,Vol)

 

    0x85, 0x05,                    //   REPORT_ID (5)

    0x09, 0x05,                    //   USAGE (Vendor Usage 5)

    0x75, 0x08,                    //   REPORT_SIZE (8)

    0x95, 0x04,                    //   REPORT_COUNT (4)

    0x81, 0x82,                    //   INPUT (Data,Var,Abs,Vol)

 

    0x85, 0x06,                    //   REPORT_ID (6)

    0x09, 0x06,                    //   USAGE (Vendor Usage 6)

    0x75, 0x08,                    //   REPORT_SIZE (8)

    0x95, 0x04,                    //   REPORT_COUNT (4)

    0x81, 0x82,                    //   INPUT (Data,Var,Abs,Vol)
  /* USER CODE END 0 */
  0xC0    /*     END_COLLECTION	             */
};

/* USER CODE BEGIN PRIVATE_VARIABLES */

/* USER CODE END PRIVATE_VARIABLES */

/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID_Exported_Variables USBD_CUSTOM_HID_Exported_Variables
  * @brief Public variables.
  * @{
  */
extern USBD_HandleTypeDef hUsbDeviceFS;

/* USER CODE BEGIN EXPORTED_VARIABLES */

/* USER CODE END EXPORTED_VARIABLES */
/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID_Private_FunctionPrototypes USBD_CUSTOM_HID_Private_FunctionPrototypes
  * @brief Private functions declaration.
  * @{
  */

static int8_t CUSTOM_HID_Init_FS(void);
static int8_t CUSTOM_HID_DeInit_FS(void);
static int8_t CUSTOM_HID_OutEvent_FS(uint8_t event_idx, uint8_t state);

/**
  * @}
  */

USBD_CUSTOM_HID_ItfTypeDef USBD_CustomHID_fops_FS =
{
  CUSTOM_HID_ReportDesc_FS,
  CUSTOM_HID_Init_FS,
  CUSTOM_HID_DeInit_FS,
  CUSTOM_HID_OutEvent_FS
};

/** @defgroup USBD_CUSTOM_HID_Private_Functions USBD_CUSTOM_HID_Private_Functions
  * @brief Private functions.
  * @{
  */

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Initializes the CUSTOM HID media low layer
  * @retval USBD_OK if all operations are OK else USBD_FAIL
  */
static int8_t CUSTOM_HID_Init_FS(void)
{
  /* USER CODE BEGIN 4 */
  return (USBD_OK);
  /* USER CODE END 4 */
}

/**
  * @brief  DeInitializes the CUSTOM HID media low layer
  * @retval USBD_OK if all operations are OK else USBD_FAIL
  */
static int8_t CUSTOM_HID_DeInit_FS(void)
{
  /* USER CODE BEGIN 5 */
  return (USBD_OK);
  /* USER CODE END 5 */
}

/**
  * @brief  Manage the CUSTOM HID class events
  * @param  event_idx: Event index
  * @param  state: Event state
  * @retval USBD_OK if all operations are OK else USBD_FAIL
  */
static int8_t CUSTOM_HID_OutEvent_FS(uint8_t event_idx, uint8_t state)
{
  /* USER CODE BEGIN 6 */
	static uint8_t data_to_receive[2];
  USBD_CUSTOM_HID_HandleTypeDef *hhid = (USBD_CUSTOM_HID_HandleTypeDef*) hUsbDeviceFS.pClassData;
  for (uint8_t i = 0; i < sizeof(data_to_receive); i++)
  {
    data_to_receive[i] = hhid->Report_buf[i];
  }        
  if ((data_to_receive[0] == GREEN_LED_ID) && (data_to_receive[1] == LED_ON))
  {
    HAL_GPIO_WritePin(LD_GREEN_GPIO_Port, LD_GREEN_Pin, GPIO_PIN_SET);
  }
  if ((data_to_receive[0]== GREEN_LED_ID) && (data_to_receive[1] == LED_OFF))
  {
    HAL_GPIO_WritePin(LD_GREEN_GPIO_Port, LD_GREEN_Pin, GPIO_PIN_RESET);
  }
  if ((data_to_receive[0] == ORANGE_LED_ID) && (data_to_receive[1] == LED_ON))
  {
    HAL_GPIO_WritePin(LD_ORANGE_GPIO_Port, LD_ORANGE_Pin, GPIO_PIN_SET);
  }
  if ((data_to_receive[0] == ORANGE_LED_ID) && (data_to_receive[1] == LED_OFF))
  {
    HAL_GPIO_WritePin(LD_ORANGE_GPIO_Port, LD_ORANGE_Pin, GPIO_PIN_RESET);
  }
  if ((data_to_receive[0] == RED_LED_ID) && (data_to_receive[1] == LED_ON))
  {
    HAL_GPIO_WritePin(LD_RED_GPIO_Port, LD_RED_Pin, GPIO_PIN_SET);
  }
  if ((data_to_receive[0] == RED_LED_ID) && (data_to_receive[1] == LED_OFF))
  {
    HAL_GPIO_WritePin(LD_RED_GPIO_Port, LD_RED_Pin, GPIO_PIN_RESET);
  }
  if ((data_to_receive[0] == BLUE_LED_ID) && (data_to_receive[1] == LED_ON))
  {
    HAL_GPIO_WritePin(LD_BLUE_GPIO_Port, LD_BLUE_Pin, GPIO_PIN_SET);
  }
  if ((data_to_receive[0] == BLUE_LED_ID)&&(data_to_receive[1] == LED_OFF))
  {
    HAL_GPIO_WritePin(LD_BLUE_GPIO_Port, LD_BLUE_Pin, GPIO_PIN_RESET);
  }
  return (USBD_OK);
  /* USER CODE END 6 */
}

/* USER CODE BEGIN 7 */
/**
  * @brief  Send the report to the Host
  * @param  report: The report to be sent
  * @param  len: The report length
  * @retval USBD_OK if all operations are OK else USBD_FAIL
  */
/*
static int8_t USBD_CUSTOM_HID_SendReport_FS(uint8_t *report, uint16_t len)
{
  return USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, report, len);
}
*/
/* USER CODE END 7 */

/* USER CODE BEGIN PRIVATE_FUNCTIONS_IMPLEMENTATION */

/* USER CODE END PRIVATE_FUNCTIONS_IMPLEMENTATION */
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

