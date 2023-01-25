#define DWT_CONTROL *(volatile unsigned long *)0xE0001000
#define SCB_DEMCR   *(volatile unsigned long *)0xE000EDFC


__STATIC_INLINE void DWT_Init(void)
{
	CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
	DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;
}


__STATIC_INLINE void delay_us(uint32_t us)
{
	DWT->CYCCNT = 0U;
    uint32_t us_count_tic =  us * (SystemCoreClock / 1000000U);
	while(DWT->CYCCNT < us_count_tic);
}

int main(void)
{
  while (1)
  {
	HAL_GPIO_TogglePin(TEST_GPIO_Port, TEST_Pin);
	delay_us(25);
  }
}