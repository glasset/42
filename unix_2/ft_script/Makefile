# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glasset <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/06 10:39:11 by glasset           #+#    #+#              #
#    Updated: 2014/04/29 13:36:18 by glasset          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_script

SRC = ./ft_script.c

OBJ = $(SRC:.c=.o)

.PHONY: all
all : $(NAME)

$(NAME) : $(SRC)
	@gcc -g -Wall -Wextra -Werror -c $?
	@gcc -o $(NAME) $(OBJ) -L /usr/lib -ltermcap
	@echo "ft_script created."

.PHONY: clean
clean:
	@rm -f $(OBJ)
	@echo "file .o clean"

.PHONY: fclean
fclean: clean
	@rm -f $(NAME)
	@echo "file $(NAME) clean"

.PHONY: re
re: fclean all

