################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/kinetis_sysinit.c" \
"../Sources/main.c" \

C_SRCS += \
../Sources/kinetis_sysinit.c \
../Sources/main.c \

OBJS += \
./Sources/kinetis_sysinit.o \
./Sources/main.o \

C_DEPS += \
./Sources/kinetis_sysinit.d \
./Sources/main.d \

OBJS_QUOTED += \
"./Sources/kinetis_sysinit.o" \
"./Sources/main.o" \

C_DEPS_QUOTED += \
"./Sources/kinetis_sysinit.d" \
"./Sources/main.d" \

OBJS_OS_FORMAT += \
./Sources/kinetis_sysinit.o \
./Sources/main.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/kinetis_sysinit.o: ../Sources/kinetis_sysinit.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/kinetis_sysinit.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/kinetis_sysinit.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/main.o: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/main.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/main.o"
	@echo 'Finished building: $<'
	@echo ' '


