# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glasset <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/06 10:39:11 by glasset           #+#    #+#              #
#    Updated: 2014/03/12 16:06:58 by glasset          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC = ./lst.c ./main.c ./parser.c ./print.c\

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
	@echo "file .o clean"

.PHONY: fclean
fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean
	@echo "file $(NAME) clean"

.PHONY: re
re: fclean all

