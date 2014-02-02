# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glasset <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/06 10:39:11 by glasset           #+#    #+#              #
#    Updated: 2014/02/02 18:05:44 by glasset          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../server

SRC = ./server_m.c \
	  ./convert.c

OBJ = $(SRC:.c=.o)

.PHONY: all
all : $(NAME)

$(NAME) : $(SRC)
	@make -C ../printf/
	@gcc -Wall -Wextra -Werror -c $? -I ../printf/
	@gcc -o $(NAME) $(OBJ) -L ../printf -lftprintf
	@echo "$(NAME) compil down."

.PHONY: clean
clean:
	@rm -f $(OBJ)
	@make -C ../printf/ clean
	@echo "file .o clean"

.PHONY: fclean
fclean: clean
	@rm -f $(NAME)
	@make -C ../printf/ fclean
	@echo "file $(NAME) clean"

.PHONY: re
re: fclean all
