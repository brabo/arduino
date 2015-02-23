MAIN = main.c
LOCAL_SOURCE_DIR = ./src/
LOCAL_SOURCE = uart.c pwm.c

ROOT = .
SRC_DIR = ./src/


INC = ./inc/

CC=`which avr-gcc`

#CC=$(TOOLROOT)/arm-none-eabi-gcc
#LD=$(TOOLROOT)/arm-none-eabi-gcc
#GDB=$(TOOLROOT)/arm-none-eabi-gdb
#AR=$(TOOLROOT)/arm-none-eabi-ar
#AS=$(TOOLROOT)/arm-none-eabi-as
#OPENOCD=/usr/local/bin/openocd
OBJCOPY = `which avr-objcopy`
#OBJDUMP = arm-none-eabi-objdump
#SIZE = arm-none-eabi-size
AVRD=`which avrdude`

TARGET = $(strip $(basename $(MAIN)))
SRC = $(addprefix $(LOCAL_SOURCE_DIR), $(TARGET).c)

EXTRA_SOURCE =  $(addprefix $(LOCAL_SOURCE_DIR), $(LOCAL_SOURCE))

SRC += $(EXTRA_SOURCE)
OBJS = $(SRC:.c=.o)

CFLAGS=-g -Os -Wall -std=c99 -mmcu=atmega328p -I/usr/lib/avr/include -I/usr/lib/gcc/avr/4.7.2/include -I./inc -nostdinc
#CFLAGS = -mcpu=cortex-m4 -mthumb
#CFLAGS += -Wall -g -O3
#CFLAGS += -fno-tree-loop-distribute-patterns -fno-common
#CFLAGS += -I$(INC) -I$(NEWLIB_INCLUDE)
#CFLAGS += -L$(NEWLIB_LIB)
#CFLAGS += -MD
#CFLAGS += -lm -lc -lnosys
#LDFLAGS = --static -fno-tree-loop-distribute-patterns
#LDFLAGS += -T ld/ti-cc3200.ld -nostartfiles -Wl,--gc-sections -Wl,-Map=$(TARGET).map
#CFLAGS+=-Wall -g -fno-tree-loop-distribute-patterns -fno-common -mcpu=cortex-m3 -mthumb -MD -DSTM32F1 -I/usr/local/arm-none-eabi/include -DSTM32 -I./testpico/build/include/ -I./inc -L./testpico/build/lib/ -I./picotcp-modules/libhttp -L./picotcp-modules/libhttp -L/usr/local/arm-none-eabi/lib -I$(NETIF_SOURCE_DIR) -L$(NETIF_SOURCE_DIR) -I./inc -lopencm3_stm32f1
#CFLAGS +=-I./testpico/build/include/ -L./testpico/build/lib/ -DPRINTF_SUPPORT_LONG
#LDFLAGS=--static -lc -T ld/stm32_ram.ld -nostartfiles -Wl,--gc-sections -nostdlib -mcpu=cortex-m3 -mthumb -lm -Wl,-Map=tut.map


flash: all
	$(AVRD) -p atmega328p -c arduino -P /dev/ttyUSB0 -b 57600 -v -v -U flash:w:$(TARGET).hex

all: main.hex

main.hex: main.elf
	$(OBJCOPY) -R .eeprom -O ihex main.elf main.hex

main.elf: $(OBJS)
	$(CC) -o $(TARGET).elf $(OBJS) $(LDFLAGS) $(CFLAGS)

#$(OPENOCD) -f openocd.cfg -c "init" -c "reset init" -c "flash write_image erase main.hex 0x08000000" -c "reset run" -c "shutdown"

clean:
	rm -f *.elf *.bin *.list *.map *.o *.d *~ *.hex
	rm -f src/*.o

#test:
#	gcc -o test t/01_c.c src/pwm.c -I./inc -DSTM32 -DSTM32F1 -T ld/libopencm3_stm32f1.ld -I/usr/local/arm-none-eabi/include -L/usr/local/arm-none-eabi/lib -lopencm3_stm32f1
#	./test
