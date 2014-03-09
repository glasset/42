# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glasset <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/06 10:39:11 by glasset           #+#    #+#              #
#    Updated: 2014/03/09 16:06:47 by gmarais          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = puissance4

SRC = main.c		\
	init_env.c		\
	print_board.c	\
	play.c			\
	victory.c		\
	evaluate.c		\
	sum.c			\
	easy_ia.c

OBJ = $(SRC:.c=.o)

.PHONY: all
all : $(NAME)

$(NAME) : $(SRC)
	@make -C libft/
	@gcc -g -Wall -Wextra -Werror -c $? -I libft/includes
	@gcc -o $(NAME) $(OBJ) -L libft -lft
	@echo "\033[1;32mfile $(NAME) created.\033[0m"

.PHONY: clean
clean:
	@rm -f $(OBJ)
	@make -C libft/ clean
	@echo "\033[1;31mObjects removed.\033[0m"

.PHONY: fclean
fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean
	@echo "\033[1;31mfile $(NAME) removed.\033[0m"

.PHONY: re
re: fclean all

