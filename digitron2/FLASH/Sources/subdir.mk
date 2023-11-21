################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/INKEY.c" \
"../Sources/LED_CODE.c" \
"../Sources/main.c" \

C_SRCS += \
../Sources/INKEY.c \
../Sources/LED_CODE.c \
../Sources/main.c \

OBJS += \
./Sources/INKEY.o \
./Sources/LED_CODE.o \
./Sources/main.o \

C_DEPS += \
./Sources/INKEY.d \
./Sources/LED_CODE.d \
./Sources/main.d \

OBJS_QUOTED += \
"./Sources/INKEY.o" \
"./Sources/LED_CODE.o" \
"./Sources/main.o" \

C_DEPS_QUOTED += \
"./Sources/INKEY.d" \
"./Sources/LED_CODE.d" \
"./Sources/main.d" \

OBJS_OS_FORMAT += \
./Sources/INKEY.o \
./Sources/LED_CODE.o \
./Sources/main.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/INKEY.o: ../Sources/INKEY.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/INKEY.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/INKEY.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/LED_CODE.o: ../Sources/LED_CODE.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/LED_CODE.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/LED_CODE.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/main.o: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/main.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/main.o"
	@echo 'Finished building: $<'
	@echo ' '


