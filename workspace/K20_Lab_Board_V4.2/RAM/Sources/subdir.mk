################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/ADC.c" \
"../Sources/Beep.c" \
"../Sources/LED.c" \
"../Sources/MMA8451Q.c" \
"../Sources/PIT.c" \
"../Sources/System.c" \
"../Sources/UART0.c" \
"../Sources/main.c" \

C_SRCS += \
../Sources/ADC.c \
../Sources/Beep.c \
../Sources/LED.c \
../Sources/MMA8451Q.c \
../Sources/PIT.c \
../Sources/System.c \
../Sources/UART0.c \
../Sources/main.c \

OBJS += \
./Sources/ADC.o \
./Sources/Beep.o \
./Sources/LED.o \
./Sources/MMA8451Q.o \
./Sources/PIT.o \
./Sources/System.o \
./Sources/UART0.o \
./Sources/main.o \

C_DEPS += \
./Sources/ADC.d \
./Sources/Beep.d \
./Sources/LED.d \
./Sources/MMA8451Q.d \
./Sources/PIT.d \
./Sources/System.d \
./Sources/UART0.d \
./Sources/main.d \

OBJS_QUOTED += \
"./Sources/ADC.o" \
"./Sources/Beep.o" \
"./Sources/LED.o" \
"./Sources/MMA8451Q.o" \
"./Sources/PIT.o" \
"./Sources/System.o" \
"./Sources/UART0.o" \
"./Sources/main.o" \

C_DEPS_QUOTED += \
"./Sources/ADC.d" \
"./Sources/Beep.d" \
"./Sources/LED.d" \
"./Sources/MMA8451Q.d" \
"./Sources/PIT.d" \
"./Sources/System.d" \
"./Sources/UART0.d" \
"./Sources/main.d" \

OBJS_OS_FORMAT += \
./Sources/ADC.o \
./Sources/Beep.o \
./Sources/LED.o \
./Sources/MMA8451Q.o \
./Sources/PIT.o \
./Sources/System.o \
./Sources/UART0.o \
./Sources/main.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/ADC.o: ../Sources/ADC.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/ADC.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/ADC.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/Beep.o: ../Sources/Beep.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/Beep.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/Beep.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/LED.o: ../Sources/LED.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/LED.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/LED.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/MMA8451Q.o: ../Sources/MMA8451Q.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/MMA8451Q.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/MMA8451Q.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/PIT.o: ../Sources/PIT.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/PIT.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/PIT.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/System.o: ../Sources/System.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/System.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/System.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/UART0.o: ../Sources/UART0.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/UART0.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/UART0.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/main.o: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/main.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/main.o"
	@echo 'Finished building: $<'
	@echo ' '


