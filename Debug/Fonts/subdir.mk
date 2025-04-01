################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Fonts/font12.c \
../Fonts/font12CN.c \
../Fonts/font16.c \
../Fonts/font20.c \
../Fonts/font24.c \
../Fonts/font24CN.c \
../Fonts/font8.c \
../Fonts/font_lucida_12.c \
../Fonts/font_lucida_18.c \
../Fonts/font_lucida_18b.c \
../Fonts/font_lucida_24b.c \
../Fonts/font_lucida_30b.c \
../Fonts/font_lucida_80b.c 

OBJS += \
./Fonts/font12.o \
./Fonts/font12CN.o \
./Fonts/font16.o \
./Fonts/font20.o \
./Fonts/font24.o \
./Fonts/font24CN.o \
./Fonts/font8.o \
./Fonts/font_lucida_12.o \
./Fonts/font_lucida_18.o \
./Fonts/font_lucida_18b.o \
./Fonts/font_lucida_24b.o \
./Fonts/font_lucida_30b.o \
./Fonts/font_lucida_80b.o 

C_DEPS += \
./Fonts/font12.d \
./Fonts/font12CN.d \
./Fonts/font16.d \
./Fonts/font20.d \
./Fonts/font24.d \
./Fonts/font24CN.d \
./Fonts/font8.d \
./Fonts/font_lucida_12.d \
./Fonts/font_lucida_18.d \
./Fonts/font_lucida_18b.d \
./Fonts/font_lucida_24b.d \
./Fonts/font_lucida_30b.d \
./Fonts/font_lucida_80b.d 


# Each subdirectory must supply rules for building sources it contributes
Fonts/%.o Fonts/%.su Fonts/%.cyclo: ../Fonts/%.c Fonts/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I"C:/Users/yvogt/OneDrive/infopanels/Software/Infopanel_PoE/Drivers/Device" -I"C:/Users/yvogt/OneDrive/infopanels/Software/Infopanel_PoE/Drivers/Communication" -I"C:/Users/yvogt/OneDrive/infopanels/Software/Infopanel_PoE/Drivers/JSMN" -I"C:/Users/yvogt/OneDrive/infopanels/Software/Infopanel_PoE/Drivers/Display" -I"C:/Users/yvogt/OneDrive/infopanels/Software/Infopanel_PoE/Drivers/Ethernet/W5100" -I"C:/Users/yvogt/OneDrive/infopanels/Software/Infopanel_PoE/Drivers/Ethernet" -I"C:/Users/yvogt/OneDrive/infopanels/Software/Infopanel_PoE/Drivers/Ethernet/W5500" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Fonts

clean-Fonts:
	-$(RM) ./Fonts/font12.cyclo ./Fonts/font12.d ./Fonts/font12.o ./Fonts/font12.su ./Fonts/font12CN.cyclo ./Fonts/font12CN.d ./Fonts/font12CN.o ./Fonts/font12CN.su ./Fonts/font16.cyclo ./Fonts/font16.d ./Fonts/font16.o ./Fonts/font16.su ./Fonts/font20.cyclo ./Fonts/font20.d ./Fonts/font20.o ./Fonts/font20.su ./Fonts/font24.cyclo ./Fonts/font24.d ./Fonts/font24.o ./Fonts/font24.su ./Fonts/font24CN.cyclo ./Fonts/font24CN.d ./Fonts/font24CN.o ./Fonts/font24CN.su ./Fonts/font8.cyclo ./Fonts/font8.d ./Fonts/font8.o ./Fonts/font8.su ./Fonts/font_lucida_12.cyclo ./Fonts/font_lucida_12.d ./Fonts/font_lucida_12.o ./Fonts/font_lucida_12.su ./Fonts/font_lucida_18.cyclo ./Fonts/font_lucida_18.d ./Fonts/font_lucida_18.o ./Fonts/font_lucida_18.su ./Fonts/font_lucida_18b.cyclo ./Fonts/font_lucida_18b.d ./Fonts/font_lucida_18b.o ./Fonts/font_lucida_18b.su ./Fonts/font_lucida_24b.cyclo ./Fonts/font_lucida_24b.d ./Fonts/font_lucida_24b.o ./Fonts/font_lucida_24b.su ./Fonts/font_lucida_30b.cyclo ./Fonts/font_lucida_30b.d ./Fonts/font_lucida_30b.o ./Fonts/font_lucida_30b.su ./Fonts/font_lucida_80b.cyclo ./Fonts/font_lucida_80b.d ./Fonts/font_lucida_80b.o ./Fonts/font_lucida_80b.su

.PHONY: clean-Fonts

