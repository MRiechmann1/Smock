################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.3.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./drivers/buttons.obj" \
"./src/energia/HardwareSerial.obj" \
"./src/energia/Print.obj" \
"./src/energia/SPI.obj" \
"./src/energia/Stream.obj" \
"./src/energia/WString.obj" \
"./src/energia/Wire.obj" \
"./src/energia/itoa.obj" \
"./src/energia/avr/dtostrf.obj" \
"./src/main.obj" \
"./src/tm4c123gh6pm_startup_ccs.obj" \
"./src/rfid/MFRC522.obj" \
"./src/usb/USBCompDevice.obj" \
"./src/usb/USBKeyboardDevice.obj" \
"./src/usb/USBSerialDevice.obj" \
"./src/usb/usb_structs.obj" \
"./utils/uartstdio.obj" \
"../src/tm4c123gh6pm.cmd" \
$(GEN_CMDS__FLAG) \
-llibc.a \
-l"C:/ti/tivaware_c_series_2_1_4_178/driverlib/ccs/Debug/driverlib.lib" \
-l"C:/ti/tivaware_c_series_2_1_4_178/usblib/ccs/Debug/usblib.lib" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include drivers/subdir_vars.mk
-include src/energia/subdir_vars.mk
-include src/energia/avr/subdir_vars.mk
-include src/subdir_vars.mk
-include src/rfid/subdir_vars.mk
-include src/usb/subdir_vars.mk
-include utils/subdir_vars.mk
-include drivers/subdir_rules.mk
-include src/energia/subdir_rules.mk
-include src/energia/avr/subdir_rules.mk
-include src/subdir_rules.mk
-include src/rfid/subdir_rules.mk
-include src/usb/subdir_rules.mk
-include utils/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
usb_keyb_dev.out \

EXE_OUTPUTS__QUOTED += \
"usb_keyb_dev.out" \

BIN_OUTPUTS += \
usb_keyb_dev.bin \

BIN_OUTPUTS__QUOTED += \
"usb_keyb_dev.bin" \


# All Target
all: usb_keyb_dev.out

# Tool invocations
usb_keyb_dev.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: ARM Linker'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me -O2 --advice:power=all --define=ccs="ccs" --define=PART_TM4C123GH6PM --define=TARGET_IS_TM4C123_RA1 --define=UART_BUFFERED -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --ual -z -m"usb_dev_gamepad_ccs.map" --heap_size=0 --stack_size=1024 -i"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.3.LTS/lib" -i"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.3.LTS/include" --reread_libs --diag_wrap=off --display_error_number --warn_sections --xml_link_info="usb_keyb_dev_linkInfo.xml" --rom_model -o "usb_keyb_dev.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '
	@$(MAKE) --no-print-directory post-build

usb_keyb_dev.bin: $(EXE_OUTPUTS)
	@echo 'Building files: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo 'Invoking: ARM Hex Utility'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.3.LTS/bin/armhex"  -o "usb_keyb_dev.bin" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo ' '
	@$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "drivers\buttons.obj" "src\energia\HardwareSerial.obj" "src\energia\Print.obj" "src\energia\SPI.obj" "src\energia\Stream.obj" "src\energia\WString.obj" "src\energia\Wire.obj" "src\energia\itoa.obj" "src\energia\avr\dtostrf.obj" "src\main.obj" "src\tm4c123gh6pm_startup_ccs.obj" "src\rfid\MFRC522.obj" "src\usb\USBCompDevice.obj" "src\usb\USBKeyboardDevice.obj" "src\usb\USBSerialDevice.obj" "src\usb\usb_structs.obj" "utils\uartstdio.obj" 
	-$(RM) "drivers\buttons.d" "src\energia\itoa.d" "src\energia\avr\dtostrf.d" "src\tm4c123gh6pm_startup_ccs.d" "utils\uartstdio.d" 
	-$(RM) "src\energia\HardwareSerial.d" "src\energia\Print.d" "src\energia\SPI.d" "src\energia\Stream.d" "src\energia\WString.d" "src\energia\Wire.d" "src\main.d" "src\rfid\MFRC522.d" "src\usb\USBCompDevice.d" "src\usb\USBKeyboardDevice.d" "src\usb\USBSerialDevice.d" "src\usb\usb_structs.d" 
	-@echo 'Finished clean'
	-@echo ' '

post-build:
	-"C:/ti/ccsv8/utils/tiobj2bin/tiobj2bin" "usb_keyb_dev.out" "usb_keyb_dev.bin" "C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.3.LTS/bin/armofd" "C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.3.LTS/bin/armhex" "C:/ti/ccsv8/utils/tiobj2bin/mkhex4bin"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

