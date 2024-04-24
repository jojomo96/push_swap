# Project Name
NAME := push_swap

# Bonus Project Name
BONUS_NAME := checker

# Include Directory for headers
INCLUDE_DIR := src

# Compiler
CC := cc

# Compiler Flags
CFLAGS := -Wall -Wextra -Werror -MMD -MP

# Include Directory for libft
LIBFT_DIR := lib
LIBFT := $(LIBFT_DIR)/libft.a
LIBFT_INC := $(LIBFT_DIR)
LIBFT_FLAGS := -L$(LIBFT_DIR) -lft

# Source and Object Directories
SRC_DIR := src
OBJ_DIR := lib/obj

# Sources
SRCS := parsing/ft_parser.c \
        parsing/ft_atoi_with_error_handling.c \
        stacks/ft_global_stacks.c \
        stacks/operations/ft_swap.c \
        stacks/operations/ft_push.c \
        stacks/operations/ft_rotate.c \
        stacks/operations/ft_rotate_reverse.c \
        sorting/ft_sort.c \
        sorting/ft_sort_utils.c \
        sorting/ft_sort_utils_2.c \
        sorting/ft_cases_ab.c \
        sorting/ft_cases_apply.c \
        utils/ft_error_handler.c \
        utils/ft_compare.c
# Bonus Sources
BONUS_SRCS := $(SRCS) \
              checker/ft_checker.c
SRCS += main.c

# Object Files
OBJS := $(SRCS:%.c=$(OBJ_DIR)/%.o)
BONUS_OBJS := $(BONUS_SRCS:%.c=$(OBJ_DIR)/%.o)

# Dependency Files
DEPS := $(OBJS:.o=.d)
BONUS_DEPS := $(BONUS_OBJS:.o=.d)

# Colors
RED := \033[0;31m
GREEN := \033[0;32m
YELLOW := \033[1;33m
NC := \033[0m # No Color

logo:
	@echo "$(GREEN)"
	@echo "██████  ██    ██ ███████ ██   ██         ███████ ██     ██  █████  ██████"
	@echo "██   ██ ██    ██ ██      ██   ██         ██      ██     ██ ██   ██ ██   ██"
	@echo "██████  ██    ██ ███████ ███████         ███████ ██  █  ██ ███████ ██████"
	@echo "██      ██    ██      ██ ██   ██              ██ ██ ███ ██ ██   ██ ██"
	@echo "██       ██████  ███████ ██   ██ ███████ ███████  ███ ███  ██   ██ ██"
	@echo "$(NC)"


# Compilation Rule
all: logo directories libft $(NAME)

bonus: logo directories libft $(BONUS_NAME)

$(NAME): $(OBJS)
	$(ASCII_ART)
	@echo "$(GREEN)Linking...$(NC)"
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT_FLAGS)
	@echo "$(GREEN)Finished building $(NAME)$(NC)"

$(BONUS_NAME): $(BONUS_OBJS)
	@echo "$(GREEN)Linking...$(NC)"
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT_FLAGS)
	@echo "$(GREEN)Finished building $(BONUS_NAME)$(NC)"

# Rule for making object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "$(YELLOW)Compiling $<$(NC)"
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -I$(LIBFT_INC) -c $< -o $@
	@echo "$(GREEN)[OK]$(NC)"

# Include the dependency files
-include $(DEPS)
-include $(BONUS_DEPS)

# Rule for making the library
libft:
	@echo "$(YELLOW)Making libft$(NC)"
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

# Cleaning Rules
clean:
	@echo "$(RED)Cleaning up objects$(NC)"
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory

fclean: clean
	@echo "$(RED)Removing executables$(NC)"
	@rm -f $(NAME) $(BONUS_NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory

re: fclean all

.PHONY: all clean fclean re libft directories bonus
