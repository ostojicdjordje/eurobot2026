################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/void_moduli/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Moj_projekat_robot.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Moj_projekat_robot.list \

OBJCOPY_BIN += \
Moj_projekat_robot.bin \


# All Target
all: Moj_projekat_robot.elf secondary-outputs

# Tool invocations
Moj_projekat_robot.elf: $(OBJS) $(USER_OBJS) C:\Users\djoke\OneDrive\Dokumenti\GitHub\eurobot2026\Moj_projekat_robot\STM32F401RETX_FLASH.ld
	arm-none-eabi-gcc -o "Moj_projekat_robot.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\djoke\OneDrive\Dokumenti\GitHub\eurobot2026\Moj_projekat_robot\STM32F401RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Moj_projekat_robot.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Moj_projekat_robot.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Moj_projekat_robot.list"
	@echo 'Finished building: $@'
	@echo ' '

Moj_projekat_robot.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Moj_projekat_robot.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
