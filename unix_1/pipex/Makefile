# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glasset <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/06 10:39:11 by glasset           #+#    #+#              #
#    Updated: 2013/12/30 15:29:42 by glasset          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC = ./main.c ./ft_path.c

OBJ = $(SRC:.c=.o)

.PHONY: all
all : $(NAME)

$(NAME) : $(SRC)
	make -C libft/
	gcc -g -Wall -Wextra -Werror -c $? -I libft/includes
	gcc -o $(NAME) $(OBJ) -L libft -lft

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

