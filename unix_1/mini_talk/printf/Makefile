# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glasset <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/06 10:39:11 by glasset           #+#    #+#              #
#    Updated: 2014/02/01 15:31:35 by glasset          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ./check_flag.c \
	  ./ft_putchar.c \
	  ./ft_putnbr.c \
	  ./ft_putstr.c \
	  ./ft_strlen.c \
	  ./printf.c \
	  ./use_flag.c \
	  ./use_flag2.c \
	  ./ft_function.c \
	  ./ft_strsub.c \
	  ./ft_atoi.c \
	  ./use_flag3.c \
	  ./check_space.c

OBJ = $(SRC:.c=.o)

.PHONY: all
all:$(NAME)

$(NAME):$(SRC)
	gcc -Wall -Wextra -Werror -c $? -I ./
	ar rc $(NAME) $(OBJ)

.PHONY: clean
clean:
	@rm -f $(OBJ)

.PHONY: fclean
fclean:clean
	@rm -f $(NAME)

.PHONY: re
re:fclean all

