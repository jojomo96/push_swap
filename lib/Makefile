# Compiler
CC := cc

# Compiler flags
CFLAGS := -Wall -Wextra -Werror

# Directories
OBJDIR := obj

# Library name
NAME := libft.a

HEADERS := ft_libft/libft.h ft_printf/ft_printf.h ft_dlist/ft_dlist.h ft_get_next_line/ft_get_next_line.h

# Source files
SRCS := ft_libft/ft_atoi.c \
		ft_libft/ft_bzero.c \
		ft_libft/ft_calloc.c \
		ft_libft/ft_isalnum.c \
		ft_libft/ft_isalpha.c \
		ft_libft/ft_isascii.c \
		ft_libft/ft_isdigit.c \
		ft_libft/ft_isprint.c \
		ft_libft/ft_itoa.c \
		ft_libft/ft_memchr.c \
		ft_libft/ft_memcmp.c \
		ft_libft/ft_memcpy.c \
		ft_libft/ft_memmove.c \
		ft_libft/ft_memset.c \
		ft_libft/ft_putchar_fd.c \
		ft_libft/ft_putendl_fd.c \
		ft_libft/ft_putnbr_fd.c \
		ft_libft/ft_putstr_fd.c \
		ft_libft/ft_split.c \
		ft_libft/ft_strchr.c \
		ft_libft/ft_strdup.c \
		ft_libft/ft_strjoin.c \
		ft_libft/ft_strlcat.c \
		ft_libft/ft_strlcpy.c \
		ft_libft/ft_strlen.c \
		ft_libft/ft_strmapi.c \
		ft_libft/ft_strncmp.c \
		ft_libft/ft_strnstr.c \
		ft_libft/ft_strrchr.c \
		ft_libft/ft_strtrim.c \
		ft_libft/ft_substr.c \
		ft_libft/ft_tolower.c \
		ft_libft/ft_toupper.c \
		ft_libft/ft_striteri.c \
		ft_libft/ft_dtoa.c \
		ft_libft/ft_strcspn.c \
		ft_libft/ft_combine_numbers_fixed_width.c \
		ft_libft/ft_strtod.c \
		ft_libft/ft_isspace.c \
		ft_libft/ft_strcmp.c \
		ft_libft/ft_is_str_digit.c \
		ft_libft/ft_realloc.c \
		ft_libft/ft_isnumber.c \
		ft_printf/ft_printf.c \
		ft_printf/ft_bools.c \
		ft_printf/ft_handle_char.c \
		ft_printf/ft_getters.c \
		ft_printf/ft_dynamic_char_array.c \
		ft_printf/ft_estimate_size.c \
		ft_printf/ft_handle_format.c \
		ft_printf/ft_handle_string.c \
		ft_printf/ft_handle_int.c \
		ft_printf/ft_handle_pointer.c \
		ft_printf/ft_handle_hex.c \
		ft_printf/ft_hex_helper.c \
		ft_printf/ft_handle_percent.c \
		ft_printf/ft_int_helper.c \
		ft_dlist/ft_dlist_edit.c \
		ft_dlist/ft_dlist_find.c \
		ft_dlist/ft_dlist_rotate.c \
		ft_dlist/ft_dlist_utils.c \
		ft_dlist/ft_dlist.c \
		ft_dlist/ft_dlist_append_unique.c \
		ft_dlist/ft_dlist_sort.c \
		ft_dlist/ft_dlist_get.c \
		ft_get_next_line/ft_get_next_line.c \



# Object files (adjusted for obj directory)
OBJS := $(addprefix $(OBJDIR)/,$(SRCS:.c=.o))

# Create obj directory and compile the library
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

$(OBJDIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule (adjusted for obj directory)
clean:
	rm -rf $(OBJDIR)

# Clean and remove library rule
fclean: clean
	rm -f $(NAME)

# Rebuild rule
re: fclean all

.PHONY: all clean fclean re bonus
