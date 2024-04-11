# Project Name
NAME := push_swap

# Compiler
CC := cc

# Compiler Flags
CFLAGS := -Wall -Wextra -Werror

# Include Directory for libft
LIBFT_DIR := lib
LIBFT := $(LIBFT_DIR)/libft.a
LIBFT_INC := $(LIBFT_DIR)
LIBFT_FLAGS := -L$(LIBFT_DIR) -lft

# Source and Object Directories
SRC_DIR := src
OBJ_DIR := lib/obj

# Sources
SRCS := main.c
# Object Files
OBJS := $(SRCS:%.c=$(OBJ_DIR)/%.o)

# Compilation Rule
all: libft $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT_FLAGS)

# Rule for making object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(LIBFT_INC) -c $< -o $@

# Rule for making the library
libft:
	$(MAKE) -C $(LIBFT_DIR)

# Cleaning Rules
clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re libft

