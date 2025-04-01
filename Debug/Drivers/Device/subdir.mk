################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Device/device.c 

OBJS += \
./Drivers/Device/device.o 

C_DEPS += \
./Drivers/Device/device.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Device/%.o Drivers/Device/%.su Drivers/Device/%.cyclo: ../Drivers/Device/%.c Drivers/Device/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I"C:/Users/yvogt/OneDrive/infopanels/Software/Infopanel_PoE/Drivers/Device" -I"C:/Users/yvogt/OneDrive/infopanels/Software/Infopanel_PoE/Drivers/Communication" -I"C:/Users/yvogt/OneDrive/infopanels/Software/Infopanel_PoE/Drivers/JSMN" -I"C:/Users/yvogt/OneDrive/infopanels/Software/Infopanel_PoE/Drivers/Display" -I"C:/Users/yvogt/OneDrive/infopanels/Software/Infopanel_PoE/Drivers/Ethernet/W5100" -I"C:/Users/yvogt/OneDrive/infopanels/Software/Infopanel_PoE/Drivers/Ethernet" -I"C:/Users/yvogt/OneDrive/infopanels/Software/Infopanel_PoE/Drivers/Ethernet/W5500" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Device

clean-Drivers-2f-Device:
	-$(RM) ./Drivers/Device/device.cyclo ./Drivers/Device/device.d ./Drivers/Device/device.o ./Drivers/Device/device.su

.PHONY: clean-Drivers-2f-Device

