#include "main.h"
#include "arm_math.h"

UART_HandleTypeDef huart2;

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);

#define N 41
#define FILTER_TAP_NUM 15

static float filter_taps[FILTER_TAP_NUM] = {
    -0.009898010171524554, -0.027914315139733272, -0.032432578254938546,
    -0.010728297591680038, 0.05524117891696983,   0.14714346757690847,
    0.23125034643202272,   0.26429855734529445,   0.23125034643202272,
    0.14714346757690847,   0.05524117891696983,   -0.010728297591680038,
    -0.032432578254938546, -0.027914315139733272, -0.009898010171524554};

float a = 2.2;
float b = -1.1;
float c = 0.7;

float sine1[N], sineComposite[N], sineFiltered[N];

float f1 = 5;   // Sine Frequency 1
float f2 = 28;  // Sine Frequency 2
float f3 = 42;  // Sine Frequency 3
float f4 = 33;  // Sine Frequency 4
float fs = 100; // Sampling Frequency

void convolution(float x[], float h[], float y[], int sizeX, int sizeH) {
  int n, k;                  // variables for loops
  int p = 0;                 // index variable for output signal y
  float sum;                 // convolutions sum accumulator variable
  int Low_lim = sizeH / 2;   // Start of pick N elements of the output array
  int L = sizeX + sizeH - 1; // Original length of the convolution.

  for (n = 0; n < L; n++) {
    sum = 0;
    for (k = 0; k < sizeX; k++)
      if ((n - k) >= 0 && (n - k) < sizeH)
        sum = sum + x[k] * h[n - k]; // Main convolution sum calculation

    // Only pick center N elements of the output array!
    if (n >= Low_lim && n < (Low_lim + N)) {
      y[p] = sum;
      p++;
    }
  }
}

int main(void) {
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_USART2_UART_Init();

  for (int n = 0; n < N; n++) {
    sine1[n] = arm_sin_f32(2 * PI * f1 * n / fs);
    sineComposite[n] =
        arm_sin_f32(2 * PI * f1 * n / fs) + arm_sin_f32(2 * PI * f2 * n / fs) +
        arm_sin_f32(2 * PI * f3 * n / fs) + arm_sin_f32(2 * PI * f4 * n / fs);
  }

  convolution(sineComposite, filter_taps, sineFiltered, N, FILTER_TAP_NUM);

  while (1)
    ;
}

void SystemClock_Config(void) {
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);

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

static void MX_USART2_UART_Init(void) {
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
}

static void MX_GPIO_Init(void) {
  GPIO_InitTypeDef GPIO_InitStruct = {0};

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
}

void Error_Handler(void) {
  __disable_irq();
  while (1) {
  }
}
