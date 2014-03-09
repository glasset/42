# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glasset <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/06 10:39:11 by glasset           #+#    #+#              #
#    Updated: 2014/03/08 22:13:22 by gmarais          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = puissance4

SRC = main.c		\
	init_env.c		\
	print_board.c	\
	play.c			\
	victory.c		\
	evaluate.c		\
	easy_ia.c

OBJ = $(SRC:.c=.o)

.PHONY: all
all : $(NAME)

$(NAME) : $(SRC)
	@make -C libft/
	@gcc -g -Wall -Wextra -Werror -c $? -I libft/includes
	@gcc -o $(NAME) $(OBJ) -L libft -lft
	@echo "file $(NAME) created."

.PHONY: clean
clean:
	@rm -f $(OBJ)
	@make -C libft/ clean
	@echo "Objects removed."

.PHONY: fclean
fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean
	@echo "file $(NAME) removed."

.PHONY: re
re: fclean all

