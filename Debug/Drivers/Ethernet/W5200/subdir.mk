################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Ethernet/W5200/w5200.c 

OBJS += \
./Drivers/Ethernet/W5200/w5200.o 

C_DEPS += \
./Drivers/Ethernet/W5200/w5200.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Ethernet/W5200/%.o Drivers/Ethernet/W5200/%.su Drivers/Ethernet/W5200/%.cyclo: ../Drivers/Ethernet/W5200/%.c Drivers/Ethernet/W5200/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I"C:/Users/yvogt/OneDrive/infopanels/Software/Infopanel_PoE/Drivers/Device" -I"C:/Users/yvogt/OneDrive/infopanels/Software/Infopanel_PoE/Drivers/Communication" -I"C:/Users/yvogt/OneDrive/infopanels/Software/Infopanel_PoE/Drivers/JSMN" -I"C:/Users/yvogt/OneDrive/infopanels/Software/Infopanel_PoE/Drivers/Display" -I"C:/Users/yvogt/OneDrive/infopanels/Software/Infopanel_PoE/Drivers/Ethernet/W5100" -I"C:/Users/yvogt/OneDrive/infopanels/Software/Infopanel_PoE/Drivers/Ethernet" -I"C:/Users/yvogt/OneDrive/infopanels/Software/Infopanel_PoE/Drivers/Ethernet/W5500" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Ethernet-2f-W5200

clean-Drivers-2f-Ethernet-2f-W5200:
	-$(RM) ./Drivers/Ethernet/W5200/w5200.cyclo ./Drivers/Ethernet/W5200/w5200.d ./Drivers/Ethernet/W5200/w5200.o ./Drivers/Ethernet/W5200/w5200.su

.PHONY: clean-Drivers-2f-Ethernet-2f-W5200

