################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Display/DEV_Config.c \
../Drivers/Display/EPD_7in5_V2.c \
../Drivers/Display/GUI_Paint.c \
../Drivers/Display/skins.c 

OBJS += \
./Drivers/Display/DEV_Config.o \
./Drivers/Display/EPD_7in5_V2.o \
./Drivers/Display/GUI_Paint.o \
./Drivers/Display/skins.o 

C_DEPS += \
./Drivers/Display/DEV_Config.d \
./Drivers/Display/EPD_7in5_V2.d \
./Drivers/Display/GUI_Paint.d \
./Drivers/Display/skins.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Display/%.o Drivers/Display/%.su Drivers/Display/%.cyclo: ../Drivers/Display/%.c Drivers/Display/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I"C:/Users/yvogt/OneDrive/infopanels/Software/Infopanel_PoE/Drivers/Device" -I"C:/Users/yvogt/OneDrive/infopanels/Software/Infopanel_PoE/Drivers/Communication" -I"C:/Users/yvogt/OneDrive/infopanels/Software/Infopanel_PoE/Drivers/JSMN" -I"C:/Users/yvogt/OneDrive/infopanels/Software/Infopanel_PoE/Drivers/Display" -I"C:/Users/yvogt/OneDrive/infopanels/Software/Infopanel_PoE/Drivers/Ethernet/W5100" -I"C:/Users/yvogt/OneDrive/infopanels/Software/Infopanel_PoE/Drivers/Ethernet" -I"C:/Users/yvogt/OneDrive/infopanels/Software/Infopanel_PoE/Drivers/Ethernet/W5500" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Display

clean-Drivers-2f-Display:
	-$(RM) ./Drivers/Display/DEV_Config.cyclo ./Drivers/Display/DEV_Config.d ./Drivers/Display/DEV_Config.o ./Drivers/Display/DEV_Config.su ./Drivers/Display/EPD_7in5_V2.cyclo ./Drivers/Display/EPD_7in5_V2.d ./Drivers/Display/EPD_7in5_V2.o ./Drivers/Display/EPD_7in5_V2.su ./Drivers/Display/GUI_Paint.cyclo ./Drivers/Display/GUI_Paint.d ./Drivers/Display/GUI_Paint.o ./Drivers/Display/GUI_Paint.su ./Drivers/Display/skins.cyclo ./Drivers/Display/skins.d ./Drivers/Display/skins.o ./Drivers/Display/skins.su

.PHONY: clean-Drivers-2f-Display

