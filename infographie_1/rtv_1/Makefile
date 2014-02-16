# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glasset <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/06 10:39:11 by glasset           #+#    #+#              #
#    Updated: 2014/02/16 14:59:03 by glasset          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Rtv_1

SRC = ./main.c ./ft_display.c ./vector.c ./init.c ./init_2.c ./obj.c ./tools.c \
	  ./light.c \

OBJ = $(SRC:.c=.o)

.PHONY: all
all : $(NAME)

$(NAME) : $(SRC)
	@make -C libft/
	@gcc -g -Wall -Wextra -Werror -c $? -I libft/includes 
	@gcc -o $(NAME) $(OBJ) -L libft -lft -L/usr/X11/lib -lmlx -lXext -lX11
	@echo "$(NAME) compil down."

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

