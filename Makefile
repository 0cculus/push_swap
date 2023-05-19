# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 10:45:33 by brheaume          #+#    #+#              #
#    Updated: 2023/05/18 10:53:09 by brheaume         ###   ########.fr        #
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
	  error.c \
	  verify.c \
	  algo.c \
	  moves.c

OBJ = ${SRC:.c=.o}

CC = clang
CFLAGS = -Wextra -Wall -Werror

LIBERATE = rm -f

LIBFT = libft.a
LIBDIR = libft/

all: libft $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBDIR)$(LIBFT) -o $(NAME)

libft:
	$(MAKE) -C $(LIBDIR)

clean:
	$(LIBERATE) $(OBJ)
	$(LIBERATE) $(LIBDIR)*.o

fclean: clean
	$(LIBERATE) $(NAME)
	$(LIBERATE) $(LIBDIR)$(LIBFT)

re: fclean all

visu:
	./push_swap_visualizer/build/bin/visualizer

vis: visu

.PHONY: all libft
