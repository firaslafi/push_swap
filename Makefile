# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Source files
SRC_FILES = push_swap.c ft_atol.c swap.c push.c rotate.c rev_rotate.c ft_sqrt.c utils.c k_sort.c cpy_match_sort.c multi_arg_parse.c one_arg_parse.c free_split.c ft_error.c
SRC_PATH = ./
SRCS = $(addprefix $(SRC_PATH), $(SRC_FILES))

# Libraries
LIBFT_PATH = ./libft/
LIBFT = $(LIBFT_PATH)libft.a
PRINTF_PATH = ./printf/
LIBFTPRINTF = $(PRINTF_PATH)libftprintf.a

# Output executable
TARGET = push_swap

# Build directory
BUILD_DIR = build/

# Object files
OBJ_DIR = $(BUILD_DIR)obj/
OBJS = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

# Include directories
INCLUDES = -I$(LIBFT_PATH) -I$(PRINTF_PATH)

# Phony targets
.PHONY: all clean fclean re

# Default target
all: $(TARGET)

# Compile source files and create the executable
$(TARGET): $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) $^ $(LIBFT) $(LIBFTPRINTF) -o $@
	@echo "Executable '$(TARGET)' created successfully."

# Compile source files into object files
$(OBJ_DIR)%.o: $(SRC_PATH)%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Create build directories
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

# Clean up object files
clean:
	@$(RM) -r $(OBJ_DIR)

# Clean up object files and the executable
fclean: clean
	@$(RM) $(TARGET)

# Rebuild the project
re: fclean all
