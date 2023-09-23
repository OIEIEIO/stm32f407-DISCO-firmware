################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Inc/stm32f4_discovery.c \
../Core/Inc/stm32f4_discovery_audio_codec.c \
../Core/Inc/stm32f4_discovery_lis302dl.c 

OBJS += \
./Core/Inc/stm32f4_discovery.o \
./Core/Inc/stm32f4_discovery_audio_codec.o \
./Core/Inc/stm32f4_discovery_lis302dl.o 

C_DEPS += \
./Core/Inc/stm32f4_discovery.d \
./Core/Inc/stm32f4_discovery_audio_codec.d \
./Core/Inc/stm32f4_discovery_lis302dl.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/%.o Core/Inc/%.su Core/Inc/%.cyclo: ../Core/Inc/%.c Core/Inc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../USB_HOST/App -I../USB_HOST/Target -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Inc

clean-Core-2f-Inc:
	-$(RM) ./Core/Inc/stm32f4_discovery.cyclo ./Core/Inc/stm32f4_discovery.d ./Core/Inc/stm32f4_discovery.o ./Core/Inc/stm32f4_discovery.su ./Core/Inc/stm32f4_discovery_audio_codec.cyclo ./Core/Inc/stm32f4_discovery_audio_codec.d ./Core/Inc/stm32f4_discovery_audio_codec.o ./Core/Inc/stm32f4_discovery_audio_codec.su ./Core/Inc/stm32f4_discovery_lis302dl.cyclo ./Core/Inc/stm32f4_discovery_lis302dl.d ./Core/Inc/stm32f4_discovery_lis302dl.o ./Core/Inc/stm32f4_discovery_lis302dl.su

.PHONY: clean-Core-2f-Inc

