################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/Src/stm32f401xx_gpio_drivers.c 

OBJS += \
./drivers/Src/stm32f401xx_gpio_drivers.o 

C_DEPS += \
./drivers/Src/stm32f401xx_gpio_drivers.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/Src/%.o drivers/Src/%.su drivers/Src/%.cyclo: ../drivers/Src/%.c drivers/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../Inc -I"C:/Users/Emi/STM32CubeIDE/workspace_1.16.0/stm32f4xx_drivers/drivers/Inc" -I"C:/Users/Emi/STM32CubeIDE/workspace_1.16.0/stm32f4xx_drivers/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-drivers-2f-Src

clean-drivers-2f-Src:
	-$(RM) ./drivers/Src/stm32f401xx_gpio_drivers.cyclo ./drivers/Src/stm32f401xx_gpio_drivers.d ./drivers/Src/stm32f401xx_gpio_drivers.o ./drivers/Src/stm32f401xx_gpio_drivers.su

.PHONY: clean-drivers-2f-Src

