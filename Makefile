# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

AS = nasm
ASFLAGS = -f elf64

# Output and source files
TARGET = Statistic_Functions
ASM_SRC = deviation_from_mean.asm
ASM_OBJ = deviation_from_mean.o
C_SRC = main.c
C_OBJ = main.o

# All object files
OBJ = $(C_OBJ) $(ASM_OBJ)

# Default target to build the executable
all: $(TARGET)

# Rule to link object files into the final executable
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)    # <- Ensure this line starts with a tab

# Rule to compile C files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@   # <- Ensure this line starts with a tab

%.o: %.asm
	$(AS) $(ASFLAGS) $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
