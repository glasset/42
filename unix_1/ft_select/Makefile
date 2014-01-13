# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glasset <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/06 10:39:11 by glasset           #+#    #+#              #
#    Updated: 2014/01/11 17:35:33 by glasset          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

SRC = ./main.c ./lst.c ./ft_print.c ./keyword.c ./select.c ./use_key.c\
	  ./ft_resize.c ./tputs_status.c

OBJ = $(SRC:.c=.o)

.PHONY: all
all : $(NAME)

$(NAME) : $(SRC)
	@make -C libft/
	@gcc -g -Wall -Wextra -Werror -c $? -I libft/includes
	@gcc -o $(NAME) $(OBJ) -L libft -lft -L /usr/lib -ltermcap
	@echo "ft_select compil down."

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

