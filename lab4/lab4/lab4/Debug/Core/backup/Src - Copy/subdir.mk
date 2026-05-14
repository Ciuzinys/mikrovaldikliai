################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/backup/Src\ -\ Copy/main.c \
../Core/backup/Src\ -\ Copy/stm32f4xx_hal_msp.c \
../Core/backup/Src\ -\ Copy/stm32f4xx_it.c \
../Core/backup/Src\ -\ Copy/syscalls.c \
../Core/backup/Src\ -\ Copy/sysmem.c \
../Core/backup/Src\ -\ Copy/system_stm32f4xx.c 

OBJS += \
./Core/backup/Src\ -\ Copy/main.o \
./Core/backup/Src\ -\ Copy/stm32f4xx_hal_msp.o \
./Core/backup/Src\ -\ Copy/stm32f4xx_it.o \
./Core/backup/Src\ -\ Copy/syscalls.o \
./Core/backup/Src\ -\ Copy/sysmem.o \
./Core/backup/Src\ -\ Copy/system_stm32f4xx.o 

C_DEPS += \
./Core/backup/Src\ -\ Copy/main.d \
./Core/backup/Src\ -\ Copy/stm32f4xx_hal_msp.d \
./Core/backup/Src\ -\ Copy/stm32f4xx_it.d \
./Core/backup/Src\ -\ Copy/syscalls.d \
./Core/backup/Src\ -\ Copy/sysmem.d \
./Core/backup/Src\ -\ Copy/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/backup/Src\ -\ Copy/main.o: ../Core/backup/Src\ -\ Copy/main.c Core/backup/Src\ -\ Copy/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Core/backup/Src - Copy/main.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/backup/Src\ -\ Copy/stm32f4xx_hal_msp.o: ../Core/backup/Src\ -\ Copy/stm32f4xx_hal_msp.c Core/backup/Src\ -\ Copy/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Core/backup/Src - Copy/stm32f4xx_hal_msp.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/backup/Src\ -\ Copy/stm32f4xx_it.o: ../Core/backup/Src\ -\ Copy/stm32f4xx_it.c Core/backup/Src\ -\ Copy/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Core/backup/Src - Copy/stm32f4xx_it.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/backup/Src\ -\ Copy/syscalls.o: ../Core/backup/Src\ -\ Copy/syscalls.c Core/backup/Src\ -\ Copy/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Core/backup/Src - Copy/syscalls.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/backup/Src\ -\ Copy/sysmem.o: ../Core/backup/Src\ -\ Copy/sysmem.c Core/backup/Src\ -\ Copy/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Core/backup/Src - Copy/sysmem.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/backup/Src\ -\ Copy/system_stm32f4xx.o: ../Core/backup/Src\ -\ Copy/system_stm32f4xx.c Core/backup/Src\ -\ Copy/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Core/backup/Src - Copy/system_stm32f4xx.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-backup-2f-Src-20--2d--20-Copy

clean-Core-2f-backup-2f-Src-20--2d--20-Copy:
	-$(RM) ./Core/backup/Src\ -\ Copy/main.cyclo ./Core/backup/Src\ -\ Copy/main.d ./Core/backup/Src\ -\ Copy/main.o ./Core/backup/Src\ -\ Copy/main.su ./Core/backup/Src\ -\ Copy/stm32f4xx_hal_msp.cyclo ./Core/backup/Src\ -\ Copy/stm32f4xx_hal_msp.d ./Core/backup/Src\ -\ Copy/stm32f4xx_hal_msp.o ./Core/backup/Src\ -\ Copy/stm32f4xx_hal_msp.su ./Core/backup/Src\ -\ Copy/stm32f4xx_it.cyclo ./Core/backup/Src\ -\ Copy/stm32f4xx_it.d ./Core/backup/Src\ -\ Copy/stm32f4xx_it.o ./Core/backup/Src\ -\ Copy/stm32f4xx_it.su ./Core/backup/Src\ -\ Copy/syscalls.cyclo ./Core/backup/Src\ -\ Copy/syscalls.d ./Core/backup/Src\ -\ Copy/syscalls.o ./Core/backup/Src\ -\ Copy/syscalls.su ./Core/backup/Src\ -\ Copy/sysmem.cyclo ./Core/backup/Src\ -\ Copy/sysmem.d ./Core/backup/Src\ -\ Copy/sysmem.o ./Core/backup/Src\ -\ Copy/sysmem.su ./Core/backup/Src\ -\ Copy/system_stm32f4xx.cyclo ./Core/backup/Src\ -\ Copy/system_stm32f4xx.d ./Core/backup/Src\ -\ Copy/system_stm32f4xx.o ./Core/backup/Src\ -\ Copy/system_stm32f4xx.su

.PHONY: clean-Core-2f-backup-2f-Src-20--2d--20-Copy

