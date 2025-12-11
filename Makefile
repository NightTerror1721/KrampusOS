CC = i686-elf-gcc
LD = i686-elf-ld
CFLAGS = -std=gnu99 -ffreestanding -O2 -Wall -Wextra -Iinclude
LDFLAGS = -T linker.ld -nostdlib

SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c,build/%.o,$(SRC))
HEADERS = $(wildcard include/*.h)

ASM_SRC = $(wildcard src/asm/*.s)
ASM_OBJ = $(patsubst src/asm/%.s,build/%.o,$(ASM_SRC))

BOOT_OBJ = build/boot.o

all: krampusos.bin

build:
	mkdir build 2>nul || true

build/%.o: src/%.c $(HEADERS) | build
	$(CC) $(CFLAGS) -c $< -o $@

build/%.o: src/asm/%.s | build
	$(CC) $(CFLAGS) -c $< -o $@

build/boot.o: boot.s | build
	$(CC) $(CFLAGS) -c $< -o $@

krampusos.bin: $(BOOT_OBJ) $(OBJ) $(ASM_OBJ)
	$(LD) $(LDFLAGS) -o $@ $^

clean:
	del /q build\*.o 2>nul || true
	del /q krampusos.bin 2>nul || true