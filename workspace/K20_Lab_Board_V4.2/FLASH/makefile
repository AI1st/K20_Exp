################################################################################
# Automatically-generated file. Do not edit!
################################################################################

#Progress monitor hint: 11
first : all
-include ../makefile.init

# This file contains definitions of environment variables used in the makefiles and .args files if exist.
-include makefile.local

RM := "$(GNU_Make_Install_DirEnv)/rm" -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include Sources/subdir.mk
-include Project_Settings/Startup_Code/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(SX_DEPS)),)
-include $(SX_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
K20_Lab_Board_V4.2.elf \

EXECUTABLES_QUOTED += \
"K20_Lab_Board_V4.2.elf" \

EXECUTABLES_OS_FORMAT += \
K20_Lab_Board_V4.2.elf \

SECONDARY_FLASH += \
K20_Lab_Board_V4.2.hex \

SECONDARY_FLASH_QUOTED += \
"K20_Lab_Board_V4.2.hex" \

SECONDARY_FLASH_OS_FORMAT += \
K20_Lab_Board_V4.2.hex \


# All Target
all: warning-messages explicit-dependencies K20_Lab_Board_V4.2.elf secondary-outputs

# Tool invocations
K20_Lab_Board_V4.2.elf: $(OBJS) $(USER_OBJS) ../Project_Settings/Linker_Files/MK20DN512_flash.ld
	@echo 'Building target: $@'
	@echo 'Executing target #12 $@'
	@echo 'Invoking: ARM Ltd Windows GCC C Linker'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc"  $(USER_OBJS_QUOTED) $(LIBS_QUOTED) @"K20_Lab_Board_V4.args" -o"K20_Lab_Board_V4.2.elf"
	@echo 'Finished building target: $@'
	@echo ' '

K20_Lab_Board_V4.2.hex: K20_Lab_Board_V4.2.elf
	@echo 'Executing target #13 $@'
	@echo 'Invoking: ARM Ltd Windows GNU Create Flash Image'
	"$(ARMSourceryDirEnv)/arm-none-eabi-objcopy"  -O srec K20_Lab_Board_V4.2.elf "K20_Lab_Board_V4.2.hex"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(S_DEPS_QUOTED) $(SECONDARY_FLASH_QUOTED) "./*/*/*.o" "./*/*.o"  $(S_UPPER_DEPS_QUOTED) $(ASM_DEPS_QUOTED) $(ASM_UPPER_DEPS_QUOTED) $(SX_DEPS_QUOTED) $(EXECUTABLES_QUOTED) "./*/*/*.d" "./*/*.d"  $(ProjDirPath)/FLASH/K20_Lab_Board_V4.2.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH)

.PHONY: all clean dependents explicit-dependencies warning-messages
.SECONDARY:

-include ../makefile.targets

explicit-dependencies: ../Project_Settings/Linker_Files/MK20DN512_flash.ld K20_Lab_Board_V4.2.elf 

warning-messages: 

