# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c99

# Directories
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = build

# Target executable name
TARGET = $(BIN_DIR)/linked_list

# Source files
SOURCES = $(SRC_DIR)/main.c $(SRC_DIR)/list.c

# Object files
OBJECTS = $(BUILD_DIR)/main.o $(BUILD_DIR)/list.o

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(OBJECTS) -o $(TARGET)
	@echo "Build complete! Executable created at: $(TARGET)"

# Compile source files to object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Run the program
run: $(TARGET)
	@echo "Running linked_list program..."
	$(TARGET)

# Clean build artifacts
clean:
	@echo "Cleaning build artifacts..."
	rm -rf $(BUILD_DIR)/*.o $(TARGET)
	@echo "Clean complete!"

# Rebuild the program
rebuild: clean all

# Declare phony targets
.PHONY: all run clean rebuild

# Format source code with clang-format
format:
	@echo "Formatting source code..."
	clang-format -i $(SRC_DIR)/*.c $(SRC_DIR)/*.h
	@echo "Format complete!"
