#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#     %.i-Generate the preprocessed output of all c-program implementation file
#     
#     %.asm-Generate assembly output of c-program implementation files and the 
#     final output executable
#     
#     %.o -Generate the object file for all c-source files (but do not link) by 
#     specifying the object file you want to compile.
#
#     compile-all -Compile all object files, but DO NOT link.
#
#     build- Compile all object files and link into a final executable.
#
#     clean - This removes all compiled objects, preprocessed outputs,
#     assembly outputs, executable files and build output files
# 
# Platform Overrides:
#      PLATFORM=HOST - x86 processor
#      PLATFORM=MSP432 - msp432 board
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = HOST

# Architectures Specific Flags


# Compiler Flags and Defines
CFLAGS = -Wall \
	 -Werror \
	 -g \
	 -O0 \
	 -std=c99

ifeq ($(PLATFORM),HOST)
	CC = gcc
	PLAT = -DHOST
	LINKER =  
	SOURCES = $(HOSTSOURCES)
else
	CC = arm-none-eabi-gcc
	LINKER = -T msp432p401r.lds
	ARMFLAGS = -mcpu=cortex-m4 \
		   -mthumb \
		   -march=armv7e-m \
		   -mfloat-abi=hard \
		   -mfpu=fpv4-sp-d16 \
		   --specs=nosys.specs
	PLAT = -DMSP432
	SOURCES = $(MSPSOURCES)
endif

O = $(SOURCES:.c=.o)

%.o : %.c
	$(CC) -c $(ARMFLAGS) $(INCLUDES) $(CFLAGS) $(LINKER) $(opt) $(PLAT) -o $@ $^

%.asm: %.c
	$(CC) -c -S $(ARMFLAGS) $(INCLUDES) $(CFLAGS) $(LINKER) $(PLAT) -o $@ $^

%.i: %.c
	$(CC) -c -E $(ARMFLAGS) $(INCLUDES) $(CFLAGS) $(LINKER) $(PLAT) -o $@ $^

.PHONY: compile-all
compile-all: $(O)

.PHONY: clean
clean:	
	rm -f *.out src/*.o src/*.asm src/*.out src/*.map src/*.d

.PHONY: build
build: $(O)
	$(CC) $(ARMFLAGS) $(PLAT) $(INCLUDES) $(LINKER) $(CFLAGS) -o course1.out $^


