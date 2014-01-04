# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glasset <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/06 10:39:11 by glasset           #+#    #+#              #
#    Updated: 2013/12/17 13:37:41 by glasset          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = ./main.c ./ft_line.c ./ft_getnbr.c ./get_next_line.c ./ft_iso.c \
	  ./ft_check.c ./ft_error.c

OBJ = $(SRC:.c=.o)

.PHONY: all
all:$(NAME)

$(NAME):$(SRC)
	make -C libft/
	gcc -Wall -Wextra -Werror -c $? -I libft/includes
	gcc -o $(NAME) $(OBJ) -L libft -lft -L/usr/x11/lib -lmlx -lxext -lx11

.PHONY: clean
clean:
	@rm -f $(OBJ)
	@make -C libft/ clean

.PHONY: fclean
fclean:clean
	@rm -f $(NAME)
	@make -C libft/ fclean
.PHONY: re
re:fclean all

