/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
uint32_t lastTickGreen = 0;
uint32_t lastTickRed = 0;
uint32_t greenInterval = 1000;
uint8_t buttonWasPressed = 0;
uint8_t seka = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */
  // 1. Įjungti GPIO portų laikrodžius (Clock) per RCC registrą
  // Pagal tavo kodą naudojami GPIOA (mygtukui) ir GPIOG (LEDams)
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; // Įjungiam Port A
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIOGEN; // Įjungiam Port G

  // 2. Nustatyti LED pinus kaip "Output" (GPIOG MODER registras)
  // Nustatome Green_LED_Pin ir Red_LED_Pin į "01" (General purpose output mode)
  // Priklausomai nuo plokštės, tai dažniausiai 13 ir 14 pinai.
  // Naudosime tavo kodo apibrėžtus Pin pavadinimus:
  GPIOG->MODER &= ~(3U << (13 * 2)); // Išvalom (Pin 13)
  GPIOG->MODER |=  (1U << (13 * 2)); // Nustatom Output (Pin 13)
  GPIOG->MODER &= ~(3U << (14 * 2)); // Išvalom (Pin 14)
  GPIOG->MODER |=  (1U << (14 * 2)); // Nustatom Output (Pin 14)

  // 3. Nustatyti Mygtuko piną kaip "Input" (GPIOA MODER registras)
  // Nustatome User_Input_Pin į "00" (Input mode) - dažniausiai Pin 0
  GPIOA->MODER &= ~(3U << (0 * 2));
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
    {
      uint32_t currentTick = HAL_GetTick(); // Laiko matavimui vis dar naudojame Tick

       //--- 1 UŽDUOTIS: Dvejetainė seka 0, 2, 3 (Privaloma dalis) ---
         /* if (currentTick - lastTickGreen >= 1000)
          {
              lastTickGreen = currentTick;
              seka++;
              if (seka > 2) seka = 0;

              if (seka == 0) { // 0: Abu OFF
                  GPIOG->ODR &= ~(1 << 13);
                  GPIOG->ODR &= ~(1 << 14);
              }
              else if (seka == 1) { // 2: Raudonas ON, Žalias OFF
                  GPIOG->ODR &= ~(1 << 13);
                  GPIOG->ODR |= (1 << 14);
              }
              else if (seka == 2) { // 3: Abu ON
                  GPIOG->ODR |= (1 << 13);
                  GPIOG->ODR |= (1 << 14);
              }
          }*/


          /* --- 2 UŽDUOTIS: Mygtukas ir skirtingas mirksėjimas (Papildoma dalis) --- */
          // Mygtuko nuskaitymas
          if (GPIOA->IDR & (1 << 0))
          {
              GPIOG->BSRR = (1 << 14); // Raudonas dega kol spaudi
              if (buttonWasPressed == 0) {
                  greenInterval += 2000;
                  buttonWasPressed = 1;
              }
          }
          else
          {
              buttonWasPressed = 0;
              // Raudonas mirksi kas 2s
              if (currentTick - lastTickRed >= 2000) {
                  GPIOG->ODR ^= (1 << 14);
                  lastTickRed = currentTick;
              }
          }

          // Žalias mirksi pagal intervalą
          if (currentTick - lastTickGreen >= greenInterval) {
              GPIOG->ODR ^= (1 << 13);
              lastTickGreen = currentTick;
          }
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 72;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 3;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  /* USER CODE BEGIN MX_GPIO_Init_1 */

  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOG, Green_LED_Pin|Red_LED_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : User_Input_Pin */
  GPIO_InitStruct.Pin = User_Input_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(User_Input_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : Green_LED_Pin Red_LED_Pin */
  GPIO_InitStruct.Pin = Green_LED_Pin|Red_LED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

  /* USER CODE BEGIN MX_GPIO_Init_2 */

  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}
#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
