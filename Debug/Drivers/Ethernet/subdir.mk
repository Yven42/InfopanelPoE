################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Ethernet/dhcp.c \
../Drivers/Ethernet/socket.c \
../Drivers/Ethernet/wizchip_conf.c 

OBJS += \
./Drivers/Ethernet/dhcp.o \
./Drivers/Ethernet/socket.o \
./Drivers/Ethernet/wizchip_conf.o 

C_DEPS += \
./Drivers/Ethernet/dhcp.d \
./Drivers/Ethernet/socket.d \
./Drivers/Ethernet/wizchip_conf.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Ethernet/%.o Drivers/Ethernet/%.su Drivers/Ethernet/%.cyclo: ../Drivers/Ethernet/%.c Drivers/Ethernet/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I"C:/Users/yvogt/OneDrive/infopanels/Software/Infopanel_PoE/Drivers/Device" -I"C:/Users/yvogt/OneDrive/infopanels/Software/Infopanel_PoE/Drivers/Communication" -I"C:/Users/yvogt/OneDrive/infopanels/Software/Infopanel_PoE/Drivers/JSMN" -I"C:/Users/yvogt/OneDrive/infopanels/Software/Infopanel_PoE/Drivers/Display" -I"C:/Users/yvogt/OneDrive/infopanels/Software/Infopanel_PoE/Drivers/Ethernet/W5100" -I"C:/Users/yvogt/OneDrive/infopanels/Software/Infopanel_PoE/Drivers/Ethernet" -I"C:/Users/yvogt/OneDrive/infopanels/Software/Infopanel_PoE/Drivers/Ethernet/W5500" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Ethernet

clean-Drivers-2f-Ethernet:
	-$(RM) ./Drivers/Ethernet/dhcp.cyclo ./Drivers/Ethernet/dhcp.d ./Drivers/Ethernet/dhcp.o ./Drivers/Ethernet/dhcp.su ./Drivers/Ethernet/socket.cyclo ./Drivers/Ethernet/socket.d ./Drivers/Ethernet/socket.o ./Drivers/Ethernet/socket.su ./Drivers/Ethernet/wizchip_conf.cyclo ./Drivers/Ethernet/wizchip_conf.d ./Drivers/Ethernet/wizchip_conf.o ./Drivers/Ethernet/wizchip_conf.su

.PHONY: clean-Drivers-2f-Ethernet

