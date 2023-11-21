################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/MMA8451Q.c" \
"../Sources/UART0.c" \
"../Sources/main.c" \

C_SRCS += \
../Sources/MMA8451Q.c \
../Sources/UART0.c \
../Sources/main.c \

OBJS += \
./Sources/MMA8451Q.o \
./Sources/UART0.o \
./Sources/main.o \

C_DEPS += \
./Sources/MMA8451Q.d \
./Sources/UART0.d \
./Sources/main.d \

OBJS_QUOTED += \
"./Sources/MMA8451Q.o" \
"./Sources/UART0.o" \
"./Sources/main.o" \

C_DEPS_QUOTED += \
"./Sources/MMA8451Q.d" \
"./Sources/UART0.d" \
"./Sources/main.d" \

OBJS_OS_FORMAT += \
./Sources/MMA8451Q.o \
./Sources/UART0.o \
./Sources/main.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/MMA8451Q.o: ../Sources/MMA8451Q.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/MMA8451Q.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/MMA8451Q.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/UART0.o: ../Sources/UART0.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/UART0.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/UART0.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/main.o: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/main.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/main.o"
	@echo 'Finished building: $<'
	@echo ' '


