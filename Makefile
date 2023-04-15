GCC=arm-none-eabi-gcc
GCC_FLAG=-c -mcpu=cortex-m3 -mthumb
AS=arm-none-eabi-as
AS_FLAG=-mcpu=cortex-m3 -mthumb 
LD=arm-none-eabi-ld
LD_FLAG=-T startup/flash_link.ld
COPY=arm-none-eabi-objcopy
COPY_FLAG=-O ihex
DUMP=arm-none-eabi-objdump
float= no
ARM_NONE_EABI_PATH= /home/Re.ME/tools/arm-none-gcc/lib/gcc/arm-none-eabi
FLOAT_FLAG=-mfloat-abi=softfp
FLOAT_PATH= $(ARM_NONE_EABI_PATH)/10.3.1//thumb/v7-m/nofp/libgcc.a
ifeq ($(float),yes)
GCC_FLAG += $(FLOAT_FLAG)
endif
TARGET=test
BUILD_DIR= build/
debug= no
STARTUP_DIR= startup/*.s
STARTUP_SRC= $(wildcard $(STARTUP_DIR))
STARTUP_OBJ= $(patsubst %.s,$(BUILD_DIR)%.o,$(notdir $(STARTUP_SRC)))
C_DIR= main/*.c system/*.c hardware/*.c
C_SRC= $(wildcard $(C_DIR))
C_OBJ= $(patsubst %.c,$(BUILD_DIR)%.o,$(notdir $(C_SRC)))
INCLUDE= -I main/ -I system/ -I hardware/

Default: clean $(TARGET)

$(TARGET):$(STARTUP_OBJ) $(C_OBJ)
ifeq ($=$(float),yes)
	$(LD) $(LD_FLAG) $^ $(FLOAT_PATH) -o $(BUILD_DIR)$(TARGET).elf
else
	$(LD) $(LD_FLAG) $^ -o $(BUILD_DIR)$(TARGET).elf
endif
	$(COPY) $(COPY_FLAG) $(BUILD_DIR)$(TARGET).elf $(BUILD_DIR)$(TARGET).hex
	$(DUMP) -D $(BUILD_DIR)$(TARGET).elf > $(BUILD_DIR)$(TARGET).map

$(STARTUP_OBJ):$(STARTUP_SRC)
ifeq ($(debug),yes)
	$(AS) -g $(AS_FLAG) $(patsubst %.o,%.s,$@) -o $@
else
	$(AS) $(AS_FLAG) $(patsubst %.o,%.s,$@) -o $@
endif

$(C_OBJ):$(C_SRC)
ifeq ($(debug),yes)
	$(GCC) -g $(GCC_FLAG) $(INCLUDE) $(patsubst %.o,%.c,$@) -o $@
else	
	$(GCC) $(GCC_FLAG) $(INCLUDE) $(patsubst %.o,%.c,$@) -o $@
endif

clean:
	rm -rf $(BUILD_DIR)
	mkdir $(BUILD_DIR)
	cp $(C_SRC) $(STARTUP_DIR) $(BUILD_DIR)

flash:
	st-flash --format ihex write $(BUILD_DIR)$(TARGET).hex

gdb:
	arm-none-eabi-gdb $(BUILD_DIR)$(TARGET).elf

