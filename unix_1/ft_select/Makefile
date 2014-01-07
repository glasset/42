# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glasset <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/06 10:39:11 by glasset           #+#    #+#              #
#    Updated: 2014/01/07 21:08:08 by glasset          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

SRC = ./main.c ./lst.c ./ft_print.c ./keyword.c ./select.c ./use_key.c

OBJ = $(SRC:.c=.o)

.PHONY: all
all : $(NAME)

$(NAME) : $(SRC)
	make -C libft/
	gcc -Wall -Wextra -Werror -c $? -I libft/includes
	gcc -o $(NAME) $(OBJ) -L libft -lft -L /usr/lib -ltermcap

.PHONY: clean
clean:
	@rm -f $(OBJ)
	@make -C libft/ clean

.PHONY: fclean
fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean
.PHONY: re
re: fclean all

