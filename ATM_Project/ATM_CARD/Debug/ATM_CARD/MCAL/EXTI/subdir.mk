################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ATM_CARD/MCAL/EXTI/EXTI.c 

OBJS += \
./ATM_CARD/MCAL/EXTI/EXTI.o 

C_DEPS += \
./ATM_CARD/MCAL/EXTI/EXTI.d 


# Each subdirectory must supply rules for building sources it contributes
ATM_CARD/MCAL/EXTI/%.o: ../ATM_CARD/MCAL/EXTI/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\Al Badr\Dropbox\My PC (AlBadr-LapTop)\Downloads\ATM_Project-master\ATM_Project-master\ATM_Project\ATM_CARD\ATM_CARD\APP" -I"C:\Users\Al Badr\Dropbox\My PC (AlBadr-LapTop)\Downloads\ATM_Project-master\ATM_Project-master\ATM_Project\ATM_CARD\ATM_CARD\HAL\EEPROM" -I"C:\Users\Al Badr\Dropbox\My PC (AlBadr-LapTop)\Downloads\ATM_Project-master\ATM_Project-master\ATM_Project\ATM_CARD\ATM_CARD\HAL\KeyPad" -I"C:\Users\Al Badr\Dropbox\My PC (AlBadr-LapTop)\Downloads\ATM_Project-master\ATM_Project-master\ATM_Project\ATM_CARD\ATM_CARD\HAL\LCD" -I"C:\Users\Al Badr\Dropbox\My PC (AlBadr-LapTop)\Downloads\ATM_Project-master\ATM_Project-master\ATM_Project\ATM_CARD\ATM_CARD\HAL\MOTOR" -I"C:\Users\Al Badr\Dropbox\My PC (AlBadr-LapTop)\Downloads\ATM_Project-master\ATM_Project-master\ATM_Project\ATM_CARD\ATM_CARD\lib" -I"C:\Users\Al Badr\Dropbox\My PC (AlBadr-LapTop)\Downloads\ATM_Project-master\ATM_Project-master\ATM_Project\ATM_CARD\ATM_CARD\MCAL\DIO" -I"C:\Users\Al Badr\Dropbox\My PC (AlBadr-LapTop)\Downloads\ATM_Project-master\ATM_Project-master\ATM_Project\ATM_CARD\ATM_CARD\MCAL\EXTI" -I"C:\Users\Al Badr\Dropbox\My PC (AlBadr-LapTop)\Downloads\ATM_Project-master\ATM_Project-master\ATM_Project\ATM_CARD\ATM_CARD\MCAL\I2C" -I"C:\Users\Al Badr\Dropbox\My PC (AlBadr-LapTop)\Downloads\ATM_Project-master\ATM_Project-master\ATM_Project\ATM_CARD\ATM_CARD\MCAL\SPI" -I"C:\Users\Al Badr\Dropbox\My PC (AlBadr-LapTop)\Downloads\ATM_Project-master\ATM_Project-master\ATM_Project\ATM_CARD\ATM_CARD\MCAL\UART" -I"C:\Users\Al Badr\Dropbox\My PC (AlBadr-LapTop)\Downloads\ATM_Project-master\ATM_Project-master\ATM_Project\ATM_CARD\ATM_CARD\SERVICE\SER_UART" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


