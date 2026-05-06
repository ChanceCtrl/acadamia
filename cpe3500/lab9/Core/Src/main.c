#include "main.h"
#include "arm_math.h"
#include "stm32f4xx_hal_adc.h"
#include "stm32f4xx_hal_dac.h"
#include "stm32f4xx_hal_uart.h"
#include <stdio.h>

#define FFT_LENGTH 2048
#define BUFFER_SIZE 10000
#define BUFFER_HALFSIZE 5000
#define SAMPLING_RATE 20000
#define FREQ_WIGGLE 15

uint16_t adc_buffer[BUFFER_SIZE];
float32_t adc_float[FFT_LENGTH];
uint16_t dac_buffer[BUFFER_SIZE];

uint8_t beep_tone[] = {128, 176, 218, 245, 255, 245, 218, 176,
                       128, 80,  38,  11,  0,   11,  38,  80};
uint8_t password[] = {4, 5, 6, 2};
uint8_t input_buffer[sizeof(password)];
uint8_t input_buffer_index = 0;

float32_t output_fft[FFT_LENGTH];
float32_t input_fft_mag[FFT_LENGTH / 2];
float32_t output_freq[FFT_LENGTH / 2];
arm_rfft_fast_instance_f32 fft_handler;

ADC_HandleTypeDef hadc1;
DMA_HandleTypeDef hdma_adc1;

DAC_HandleTypeDef hdac;
DMA_HandleTypeDef hdma_dac1;

TIM_HandleTypeDef htim8;

UART_HandleTypeDef huart2;

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_ADC1_Init(void);
static void MX_DAC_Init(void);
static void MX_TIM8_Init(void);
static void MX_USART2_UART_Init(void);

void play_evil_sound() {
  for (int i = 0; i < (BUFFER_SIZE); i++)
    dac_buffer[i] = beep_tone[(i / 10) % sizeof(beep_tone)] * 200;

  HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t *)dac_buffer, BUFFER_SIZE,
                    DAC_ALIGN_12B_R);
}

void play_good_sound() {
  for (int i = 0; i < (BUFFER_SIZE); i++)
    dac_buffer[i] = beep_tone[i % sizeof(beep_tone)] * 150;

  HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t *)dac_buffer, BUFFER_SIZE,
                    DAC_ALIGN_12B_R);
}

void check_code() {
  input_buffer_index = 0;

  for (int i = 0; i < sizeof(password); i++) {
    if (input_buffer[i] != password[i]) {
      play_evil_sound();
      return;
    }
  }

  play_good_sound();
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc) {
  for (int i = 0; i < FFT_LENGTH; i++) {
    adc_float[i] = (float32_t)adc_buffer[i];
  }

  arm_rfft_fast_f32(&fft_handler, adc_float, output_fft, 0);
  arm_cmplx_mag_f32(output_fft, input_fft_mag, FFT_LENGTH / 2);

  float32_t highest_amp = 0.0f;
  int max_index = 0;
  int next_max_index = 0;

  // Find peak
  for (int i = 1; i < FFT_LENGTH / 2; i++) { // skip DC
    if (input_fft_mag[i] > highest_amp) {
      next_max_index = max_index;
      max_index = i;

      highest_amp = input_fft_mag[i];
    }
  }

  // Convert bin index to frequency
  float32_t f1 = ((float32_t)max_index * SAMPLING_RATE) / FFT_LENGTH;
  float32_t f2 = ((float32_t)next_max_index * SAMPLING_RATE) / FFT_LENGTH;

  if (highest_amp > 50000) {
    int has_697 =
        (fabsf(f1 - 697) < FREQ_WIGGLE) || (fabsf(f2 - 697) < FREQ_WIGGLE);
    int has_1209 =
        (fabsf(f1 - 1209) < FREQ_WIGGLE) || (fabsf(f2 - 1209) < FREQ_WIGGLE);
    int has_1336 =
        (fabsf(f1 - 1336) < FREQ_WIGGLE) || (fabsf(f2 - 1336) < FREQ_WIGGLE);
    int has_1477 =
        (fabsf(f1 - 1477) < FREQ_WIGGLE) || (fabsf(f2 - 1477) < FREQ_WIGGLE);
    int has_1633 =
        (fabsf(f1 - 1633) < FREQ_WIGGLE) || (fabsf(f2 - 1633) < FREQ_WIGGLE);

    char buff[64];
    int len = sprintf(buff, "Amp: %i\tFreq 1: %i\tFreq 2: %i\n",
                      (int)highest_amp, (int)f1, (int)f2);
    HAL_UART_Transmit(&huart2, (uint8_t *)buff, len, 10);

    if (has_697) {
      if (has_1209)
        HAL_UART_Transmit(&huart2, (uint8_t *)"Got a 1!\n", 9, 10);
      else if (has_1336)
        HAL_UART_Transmit(&huart2, (uint8_t *)"Got a 2!\n", 9, 10);
      else if (has_1477)
        HAL_UART_Transmit(&huart2, (uint8_t *)"Got a 3!\n", 9, 10);
      else if (has_1633)
        HAL_UART_Transmit(&huart2, (uint8_t *)"Got a A!\n", 9, 10);
    }
  }
}

void HAL_DAC_ConvCpltCallbackCh1(DAC_HandleTypeDef *hdac) {
  HAL_DAC_Stop_DMA(hdac, DAC_CHANNEL_1);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) { check_code(); }

int main(void) {
  HAL_Init();

  SystemClock_Config();

  // Initialize all configured peripherals
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_TIM8_Init();
  MX_ADC1_Init();
  MX_DAC_Init();
  MX_USART2_UART_Init();

  // Start the peripherals
  HAL_UART_Init(&huart2);

  HAL_TIM_Base_Start(&htim8);

  HAL_ADC_Start_DMA(&hadc1, (uint32_t *)adc_buffer, BUFFER_SIZE);

  arm_rfft_fast_init_f32(&fft_handler, FFT_LENGTH);

  while (1) {
  }
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void) {
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
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
   */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK |
                                RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK) {
    Error_Handler();
  }
}

/**
 * @brief ADC1 Initialization Function
 * @param None
 * @retval None
 */
static void MX_ADC1_Init(void) {

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */

  /** Configure the global features of the ADC (Clock, Resolution, Data
   * Alignment and number of conversion)
   */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;
  hadc1.Init.Resolution = ADC_RESOLUTION_12B;
  hadc1.Init.ScanConvMode = DISABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_RISING;
  hadc1.Init.ExternalTrigConv = ADC_EXTERNALTRIGCONV_T8_TRGO;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 1;
  hadc1.Init.DMAContinuousRequests = ENABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  if (HAL_ADC_Init(&hadc1) != HAL_OK) {
    Error_Handler();
  }

  /** Configure for the selected ADC regular channel its corresponding rank in
   * the sequencer and its sample time.
   */
  sConfig.Channel = ADC_CHANNEL_0;
  sConfig.Rank = 1;
  sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK) {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */
}

/**
 * @brief DAC Initialization Function
 * @param None
 * @retval None
 */
static void MX_DAC_Init(void) {

  /* USER CODE BEGIN DAC_Init 0 */

  /* USER CODE END DAC_Init 0 */

  DAC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN DAC_Init 1 */

  /* USER CODE END DAC_Init 1 */

  /** DAC Initialization
   */
  hdac.Instance = DAC;
  if (HAL_DAC_Init(&hdac) != HAL_OK) {
    Error_Handler();
  }

  /** DAC channel OUT1 config
   */
  sConfig.DAC_Trigger = DAC_TRIGGER_T8_TRGO;
  sConfig.DAC_OutputBuffer = DAC_OUTPUTBUFFER_ENABLE;
  if (HAL_DAC_ConfigChannel(&hdac, &sConfig, DAC_CHANNEL_1) != HAL_OK) {
    Error_Handler();
  }
  /* USER CODE BEGIN DAC_Init 2 */

  /* USER CODE END DAC_Init 2 */
}

/**
 * @brief TIM8 Initialization Function
 * @param None
 * @retval None
 */
static void MX_TIM8_Init(void) {

  /* USER CODE BEGIN TIM8_Init 0 */

  /* USER CODE END TIM8_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM8_Init 1 */

  /* USER CODE END TIM8_Init 1 */
  htim8.Instance = TIM8;
  htim8.Init.Prescaler = 83;
  htim8.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim8.Init.Period = 49;
  htim8.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim8.Init.RepetitionCounter = 0;
  htim8.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim8) != HAL_OK) {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim8, &sClockSourceConfig) != HAL_OK) {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_UPDATE;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim8, &sMasterConfig) != HAL_OK) {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM8_Init 2 */

  /* USER CODE END TIM8_Init 2 */
}

/**
 * @brief USART2 Initialization Function
 * @param None
 * @retval None
 */
static void MX_USART2_UART_Init(void) {

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 9600;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK) {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */
}

/**
 * Enable DMA controller clock
 */
static void MX_DMA_Init(void) {

  /* DMA controller clock enable */
  __HAL_RCC_DMA2_CLK_ENABLE();
  __HAL_RCC_DMA1_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA1_Stream5_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Stream5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Stream5_IRQn);
  /* DMA2_Stream0_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA2_Stream0_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA2_Stream0_IRQn);
}

/**
 * @brief GPIO Initialization Function
 * @param None
 * @retval None
 */
static void MX_GPIO_Init(void) {
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  /* USER CODE BEGIN MX_GPIO_Init_1 */

  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : LD2_Pin */
  GPIO_InitStruct.Pin = LD2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LD2_GPIO_Port, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

  /* USER CODE BEGIN MX_GPIO_Init_2 */

  /* USER CODE END MX_GPIO_Init_2 */
}

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
