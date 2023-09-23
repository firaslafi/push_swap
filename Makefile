# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Source files
SRC_FILES = push_swap.c ft_atol.c swap.c push.c rotate.c rev_rotate.c ft_sqrt.c utils.c k_sort.c \
			 cpy_match_sort.c multi_arg_parse.c one_arg_parse.c free_split.c ft_error.c sorting_four.c
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

# Bonus target for building checker
BONUS_TARGET = checker

# Source files for checker
BONUS_SRC_FILES = checker.c one_arg_parse.c free_split.c ft_atol.c utils.c ft_error.c multi_arg_parse.c get_next_line.c \
			get_next_line_utils.c push.c rotate.c swap.c rev_rotate.c parse_checker_ver.c bonus_utils.c
BONUS_SRCS = $(addprefix $(SRC_PATH), $(BONUS_SRC_FILES))

# Object files for checker
BONUS_OBJS = $(addprefix $(OBJ_DIR), $(BONUS_SRC_FILES:.c=.o))

# Compile source files and create the checker executable
$(BONUS_TARGET): $(BONUS_OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) $^ $(LIBFT) $(LIBFTPRINTF) -o $@
	@echo "Executable '$(BONUS_TARGET)' created successfully."

# Compile source files into object files for checker
$(OBJ_DIR)%.o: $(SRC_PATH)%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Phony target for building both the main target and the bonus target
bonus: $(BONUS_TARGET)


# Clean up object files
clean:
	@$(RM) -r $(OBJ_DIR)

fclean:
	@$(RM) -r $(OBJ_DIR)
	@$(RM) $(TARGET)
	@$(RM) $(BONUS_TARGET)

# Rebuild the project
re: fclean all
