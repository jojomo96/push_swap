# Makefile for Doubly Linked List Project

NAME = libdlist.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
HEADER = ft_dlist.h

SRCS = ft_dlist_edit.c \
       ft_dlist_find.c \
       ft_dlist_rotate.c \
       ft_dlist_utils.c \
       ft_dlist.c \
	   ft_dlist_test.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
