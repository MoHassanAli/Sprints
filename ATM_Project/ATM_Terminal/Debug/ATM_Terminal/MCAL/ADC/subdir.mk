################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ATM_Terminal/MCAL/ADC/ADC_Program.c 

OBJS += \
./ATM_Terminal/MCAL/ADC/ADC_Program.o 

C_DEPS += \
./ATM_Terminal/MCAL/ADC/ADC_Program.d 


# Each subdirectory must supply rules for building sources it contributes
ATM_Terminal/MCAL/ADC/%.o: ../ATM_Terminal/MCAL/ADC/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\Al Badr\Dropbox\My PC (AlBadr-LapTop)\Downloads\ATM_Project-master\ATM_Project-master\ATM_Project\ATM_Terminal\ATM_Terminal" -I"C:\Users\Al Badr\Dropbox\My PC (AlBadr-LapTop)\Downloads\ATM_Project-master\ATM_Project-master\ATM_Project\ATM_Terminal\ATM_Terminal\APP" -I"C:\Users\Al Badr\Dropbox\My PC (AlBadr-LapTop)\Downloads\ATM_Project-master\ATM_Project-master\ATM_Project\ATM_Terminal\ATM_Terminal\HAL\EEPROM" -I"C:\Users\Al Badr\Dropbox\My PC (AlBadr-LapTop)\Downloads\ATM_Project-master\ATM_Project-master\ATM_Project\ATM_Terminal\ATM_Terminal\HAL\KeyPad" -I"C:\Users\Al Badr\Dropbox\My PC (AlBadr-LapTop)\Downloads\ATM_Project-master\ATM_Project-master\ATM_Project\ATM_Terminal\ATM_Terminal\HAL\LCD" -I"C:\Users\Al Badr\Dropbox\My PC (AlBadr-LapTop)\Downloads\ATM_Project-master\ATM_Project-master\ATM_Project\ATM_Terminal\ATM_Terminal\HAL\LM35" -I"C:\Users\Al Badr\Dropbox\My PC (AlBadr-LapTop)\Downloads\ATM_Project-master\ATM_Project-master\ATM_Project\ATM_Terminal\ATM_Terminal\HAL\MOTOR" -I"C:\Users\Al Badr\Dropbox\My PC (AlBadr-LapTop)\Downloads\ATM_Project-master\ATM_Project-master\ATM_Project\ATM_Terminal\ATM_Terminal\lib" -I"C:\Users\Al Badr\Dropbox\My PC (AlBadr-LapTop)\Downloads\ATM_Project-master\ATM_Project-master\ATM_Project\ATM_Terminal\ATM_Terminal\MCAL" -I"C:\Users\Al Badr\Dropbox\My PC (AlBadr-LapTop)\Downloads\ATM_Project-master\ATM_Project-master\ATM_Project\ATM_Terminal\ATM_Terminal\MCAL\ADC" -I"C:\Users\Al Badr\Dropbox\My PC (AlBadr-LapTop)\Downloads\ATM_Project-master\ATM_Project-master\ATM_Project\ATM_Terminal\ATM_Terminal\MCAL\DIO" -I"C:\Users\Al Badr\Dropbox\My PC (AlBadr-LapTop)\Downloads\ATM_Project-master\ATM_Project-master\ATM_Project\ATM_Terminal\ATM_Terminal\MCAL\EXTI" -I"C:\Users\Al Badr\Dropbox\My PC (AlBadr-LapTop)\Downloads\ATM_Project-master\ATM_Project-master\ATM_Project\ATM_Terminal\ATM_Terminal\MCAL\I2C" -I"C:\Users\Al Badr\Dropbox\My PC (AlBadr-LapTop)\Downloads\ATM_Project-master\ATM_Project-master\ATM_Project\ATM_Terminal\ATM_Terminal\MCAL\SPI" -I"C:\Users\Al Badr\Dropbox\My PC (AlBadr-LapTop)\Downloads\ATM_Project-master\ATM_Project-master\ATM_Project\ATM_Terminal\ATM_Terminal\MCAL\UART" -I"C:\Users\Al Badr\Dropbox\My PC (AlBadr-LapTop)\Downloads\ATM_Project-master\ATM_Project-master\ATM_Project\ATM_Terminal\ATM_Terminal\SERVICE\SER_UART" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


