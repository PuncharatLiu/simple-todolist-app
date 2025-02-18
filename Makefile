CC = gcc
CFLAGS = -Wall -Wextra -g
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin

# List of source files
SRC = $(wildcard $(SRC_DIR)/*.c)

# Convert .c files to .o files in build/
OBJ = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC))

TARGET = $(BIN_DIR)/todo

all: $(TARGET)

# Rule to create the final executable
$(TARGET): $(OBJ)
	mkdir -p $(BIN_DIR)
	$(CC) -o $(TARGET) $(OBJ)

# Rule to compile each .c file into build/
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(BUILD_DIR)
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)
