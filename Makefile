# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 10:45:33 by brheaume          #+#    #+#              #
#    Updated: 2023/05/05 16:31:08 by brheaume         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  push_swap

SRC = main.c \
	  swap.c \
	  rotate.c \
	  reverse.c \
	  push.c \
	  list.c \
	  utils.c \
	  error.c

OBJ = ${SRC:.c=.o}

CC = clang
CFLAGS = -Wextra -Wall -Werror

LIBERATE = rm -f

LIBFT = libft.a
LIBDIR = libft/

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBDIR)$(LIBFT) -o $(NAME)

all: libft $(NAME)

clean:
	$(LIBERATE) $(OBJ)

fclean: clean
	$(LIBERATE) $(NAME)

libft:
	$(MAKE) -C $(LIBDIR)

re: fclean all

.PHONY: all libft
