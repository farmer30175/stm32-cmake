PROJECT(bldc_cntrl)

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
ENABLE_LANGUAGE(ASM)

FIND_PACKAGE(STM32F4_CMSIS REQUIRED)
FIND_PACKAGE(STM32F4_StdPeriphLib REQUIRED)
#FIND_PACKAGE(ST-LINK REQUIRED)

SET(CMAKE_EXE_LINKER_FLAGS "-T${STM32F4_CMSIS_LINKER_SCRIPT} ${CMAKE_EXE_LINKER_FLAGS}")

INCLUDE_DIRECTORIES(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${STM32F4_CMSIS_INCLUDE_DIR}
    ${STM32F4_StdPeriphLib_INCLUDE_DIR}
)

set(STM32F4_StdPeriphLib_LIBRARIES
      ${STM32F4_StdPeriphLib_misc_lib}
#      ${STM32F4_StdPeriphLib_adc_lib}
#      ${STM32F4_StdPeriphLib_can_lib}
#      ${STM32F4_StdPeriphLib_crc_lib}
#      ${STM32F4_StdPeriphLib_cryp_lib}
#      ${STM32F4_StdPeriphLib_dac_lib}
#      ${STM32F4_StdPeriphLib_dbgmcu_lib}
#      ${STM32F4_StdPeriphLib_dcmi_lib}
#      ${STM32F4_StdPeriphLib_dma_lib}
#      ${STM32F4_StdPeriphLib_exti_lib}
#      ${STM32F4_StdPeriphLib_flash_lib}
#      ${STM32F4_StdPeriphLib_fsmc_lib}
      ${STM32F4_StdPeriphLib_gpio_lib}
#      ${STM32F4_StdPeriphLib_hash_lib}
#      ${STM32F4_StdPeriphLib_i2c_lib}
#      ${STM32F4_StdPeriphLib_iwdg_lib}
#      ${STM32F4_StdPeriphLib_pwr_lib}
      ${STM32F4_StdPeriphLib_rcc_lib}
#      ${STM32F4_StdPeriphLib_rng_lib}
#      ${STM32F4_StdPeriphLib_rtc_lib}
#      ${STM32F4_StdPeriphLib_sdio_lib}
#      ${STM32F4_StdPeriphLib_spi_lib}
#      ${STM32F4_StdPeriphLib_syscfg_lib}
      ${STM32F4_StdPeriphLib_tim_lib}
#      ${STM32F4_StdPeriphLib_usart_lib}
#      ${STM32F4_StdPeriphLib_wwdg_lib}
)

SET(PROJECT_SOURCES 
    timer.cpp
    main.cpp
    control.cpp
    hall.cpp
    motor.cpp
    states.cpp
    stm32f4xx_it.cpp
)

ADD_EXECUTABLE(${CMAKE_PROJECT_NAME}.elf ${PROJECT_SOURCES} ${STM32F4_CMSIS_STARTUP_SOURCE})
TARGET_LINK_LIBRARIES(${CMAKE_PROJECT_NAME}.elf ${STM32F4_CMSIS_LIBRARIES} ${STM32F4_StdPeriphLib_LIBRARIES})

ADD_CUSTOM_TARGET(${CMAKE_PROJECT_NAME}.hex ALL DEPENDS ${CMAKE_PROJECT_NAME}.elf COMMAND ${CMAKE_OBJCOPY} -Oihex ${CMAKE_PROJECT_NAME}.elf ${CMAKE_PROJECT_NAME}.hex)
ADD_CUSTOM_TARGET(${CMAKE_PROJECT_NAME}.bin ALL DEPENDS ${CMAKE_PROJECT_NAME}.elf COMMAND ${CMAKE_OBJCOPY} -Obinary ${CMAKE_PROJECT_NAME}.elf ${CMAKE_PROJECT_NAME}.bin)


#ADD_CUSTOM_TARGET(to_flash DEPENDS ${CMAKE_PROJECT_NAME}.elf COMMAND ${CMAKE_OBJCOPY} -Obinary ${CMAKE_PROJECT_NAME}.elf ${CMAKE_PROJECT_NAME}.bin)
