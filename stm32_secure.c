FLASH_OBProgramInitTypeDef obConfig;
HAL_FLASHEx_OBGetConfig(&obConfig);

// если защита от чтения не включена,
// тогда включаем ее
if (obConfig.RDPLevel == OB_RDP_LEVEL_0)
{
  obConfig.RDPLevel = OB_RDP_LEVEL_1;
  HAL_FLASH_Unlock();
  HAL_FLASH_OB_Unlock();
  HAL_FLASHEx_OBProgram(&obConfig);
  HAL_FLASH_OB_Launch();
}

// отключаем SWD и JTAG
__HAL_AFIO_REMAP_SWJ_DISABLE();
