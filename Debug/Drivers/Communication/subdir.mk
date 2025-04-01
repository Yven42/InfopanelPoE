################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Communication/communication.c 

OBJS += \
./Drivers/Communication/communication.o 

C_DEPS += \
./Drivers/Communication/communication.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Communication/%.o Drivers/Communication/%.su Drivers/Communication/%.cyclo: ../Drivers/Communication/%.c Drivers/Communication/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I"C:/Users/yvogt/OneDrive/infopanels/Software/Infopanel_PoE/Drivers/Device" -I"C:/Users/yvogt/OneDrive/infopanels/Software/Infopanel_PoE/Drivers/Communication" -I"C:/Users/yvogt/OneDrive/infopanels/Software/Infopanel_PoE/Drivers/JSMN" -I"C:/Users/yvogt/OneDrive/infopanels/Software/Infopanel_PoE/Drivers/Display" -I"C:/Users/yvogt/OneDrive/infopanels/Software/Infopanel_PoE/Drivers/Ethernet/W5100" -I"C:/Users/yvogt/OneDrive/infopanels/Software/Infopanel_PoE/Drivers/Ethernet" -I"C:/Users/yvogt/OneDrive/infopanels/Software/Infopanel_PoE/Drivers/Ethernet/W5500" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Communication

clean-Drivers-2f-Communication:
	-$(RM) ./Drivers/Communication/communication.cyclo ./Drivers/Communication/communication.d ./Drivers/Communication/communication.o ./Drivers/Communication/communication.su

.PHONY: clean-Drivers-2f-Communication

