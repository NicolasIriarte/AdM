/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
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
#include "ejemplo/ejemplo.h"
#include "practica1-1/practica1.h"
#include "practica1-2/practica2.h"
#include "practica1-3/practica3.h"
#include <assert.h>

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

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void) {
	/* USER CODE BEGIN 1 */

	/* USER CODE END 1 */

	/* MCU Configuration--------------------------------------------------------*/

	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	HAL_Init();

	/* USER CODE BEGIN Init */

	// Línea para activar el conteo de ciclos (se debe ejecutar una sola vez)
	DWT->CTRL |= 1 << DWT_CTRL_CYCCNTENA_Pos;


	/* USER CODE END Init */

	/* Configure the system clock */
	SystemClock_Config();

	/* USER CODE BEGIN SysInit */

	/* USER CODE END SysInit */

	/* Initialize all configured peripherals */
	/* USER CODE BEGIN 2 */

	// Ejemplo
	uint32_t asm_value = sum_asm(200, 200);
	uint32_t c_value = sum_c(200, 200);

	assert(asm_value == c_value);

	// Practica 1
	{
		uint32_t data1[5] = { 1, 2, 3, 4, 5 };
		uint32_t data2[5] = { 1, 2, 3, 4, 5 };

		DWT->CYCCNT = 0;
		zeros_c(data1, 5);
		// Obtiene cantidad de ciclos que demoró la función
		volatile uint32_t tincksOnC = DWT->CYCCNT;


		DWT->CYCCNT = 0;
		zeros_asm(data2, 5);
		// Obtiene cantidad de ciclos que demoró la función
		volatile uint32_t tincksOnASM = DWT->CYCCNT;

		for (int i = 0; i < 5; ++i) {
			assert(data1[i] == 0);
			assert(data2[i] == 0);
		}

		volatile int *stop = 0;
	}

	// Practica 2
	{
		uint32_t dataSet[5] = { 1, 2, 3, 4, 5 };
		uint32_t output1[5] = {};
		uint32_t output2[5] = {};
		uint32_t escalar = 2;
		uint32_t expected[5] = { 2, 4, 6, 8, 10 };

		DWT->CYCCNT = 0;
		productoEscalar32_c(dataSet, output1, 5, escalar);
		// Obtiene cantidad de ciclos que demoró la función
		volatile uint32_t tincksOnC = DWT->CYCCNT;


		DWT->CYCCNT = 0;
		productoEscalar32_asm(dataSet, output2, 5, escalar);
		// Obtiene cantidad de ciclos que demoró la función
		volatile uint32_t tincksOnASM = DWT->CYCCNT;


		for(int i = 0; i < 5; ++i){
			assert(output1[i] == expected[i]);
			assert(output2[i] == expected[i]);
		}

		volatile int *stop = 0;
	}

	// Practica 3
	{
		uint16_t dataSet[5] = { 1, 2, 3, 4, 5 };
		uint16_t output1[5] = {};
		uint16_t output2[5] = {};
		uint16_t escalar = 2;
		uint16_t expected[5] = { 2, 4, 6, 8, 10 };

		DWT->CYCCNT = 0;
		productoEscalar16_c(dataSet, output1, 5, escalar);
		// Obtiene cantidad de ciclos que demoró la función
		volatile uint32_t tincksOnC = DWT->CYCCNT;


		DWT->CYCCNT = 0;
		productoEscalar16_asm(dataSet, output2, 5, escalar);
		// Obtiene cantidad de ciclos que demoró la función
		volatile uint32_t tincksOnASM = DWT->CYCCNT;


		for(int i = 0; i < 5; ++i){
			assert(output1[i] == expected[i]);
			assert(output2[i] == expected[i]);
		}

		volatile int *stop = 0;
	}

	// Practica 4
	{
		uint16_t dataSet[5] = { 1, 2, 3, 4, 2050 }; // Last value will sature
		uint16_t output1[5] = {};
		uint16_t output2[5] = {};
		uint16_t escalar = 2;
		uint16_t expected[5] = { 2, 4, 6, 8, 4095 }; // last value is satured

		DWT->CYCCNT = 0;
		productoEscalar12_c(dataSet, output1, 5, escalar);
		// Obtiene cantidad de ciclos que demoró la función
		volatile uint32_t tincksOnC = DWT->CYCCNT;


		DWT->CYCCNT = 0;
		productoEscalar12_asm(dataSet, output2, 5, escalar);
		// Obtiene cantidad de ciclos que demoró la función
		volatile uint32_t tincksOnASM = DWT->CYCCNT;


		for(int i = 0; i < 5; ++i){
			assert(output1[i] == expected[i]);
			assert(output2[i] == expected[i]);
		}

		volatile int *stop = 0;
	}

	/* USER CODE END 2 */

	/* Infinite loop */
	/* USER CODE BEGIN WHILE */
	while (1) {
		/* USER CODE END WHILE */

		/* USER CODE BEGIN 3 */
	}
	/* USER CODE END 3 */
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void) {
	RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };

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
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}

	/** Initializes the CPU, AHB and APB buses clocks
	 */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK) {
		Error_Handler();
	}
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void) {
	/* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
	__disable_irq();
	while (1) {
	}
	/* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
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
