################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/APPCALCULATOR/APPCALCULATOR.c 

OBJS += \
./APP/APPCALCULATOR/APPCALCULATOR.o 

C_DEPS += \
./APP/APPCALCULATOR/APPCALCULATOR.d 


# Each subdirectory must supply rules for building sources it contributes
APP/APPCALCULATOR/%.o: ../APP/APPCALCULATOR/%.c APP/APPCALCULATOR/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"E:\AVR\First\LIB" -I"E:\AVR\First\MCAL\MTWI" -I"E:\AVR\First\APP\APPCALCULATOR" -I"E:\AVR\First\MCAL\MUART" -I"E:\AVR\First\MCAL\MTIMER0" -I"E:\AVR\First\MCAL\MEXTINT" -I"E:\AVR\First\MCAL\MADC" -I"E:\AVR\First\HAL\HBUTTON" -I"E:\AVR\First\HAL\HEEPROM" -I"E:\AVR\First\HAL\HKEYPAD" -I"E:\AVR\First\HAL\HLED" -I"E:\AVR\First\HAL\HLM35" -I"E:\AVR\First\HAL\HLCD" -I"E:\AVR\First\MCAL\MDIO" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

