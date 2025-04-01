# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -I/usr/local/include
LDFLAGS = -L/usr/local/lib -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

# Source files and Output
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
TARGET = game

# Default target
all: $(TARGET)

# Compile the game
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJ) $(TARGET)

# Run the game
run: $(TARGET)
	./$(TARGET)

# Phony targets (avoid conflicts with files of the same name)
.PHONY: all clean run