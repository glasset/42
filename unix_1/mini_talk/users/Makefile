# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glasset <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/06 10:39:11 by glasset           #+#    #+#              #
#    Updated: 2014/02/03 13:41:53 by glasset          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../client

SRC = ./user_data.c \
	  ./user_m.c \
	  ./ft_atoi.c

OBJ = $(SRC:.c=.o)

.PHONY: all
all : $(NAME)

$(NAME) : $(SRC)
	@make -C ../printf/
	@gcc -Wall -Wextra -Werror -c $? -I ../printf/
	@gcc -o $(NAME) $(OBJ) -L ../printf -lftprintf
	@echo "client compil down."

.PHONY: clean
clean:
	@rm -f $(OBJ)
	@make -C ../printf/ clean
	@echo "file .o clean"

.PHONY: fclean
fclean: clean
	@rm -f $(NAME)
	@make -C ../printf/ fclean
	@echo "file client clean"

.PHONY: re
re: fclean all
