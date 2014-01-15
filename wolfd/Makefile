#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcorbel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/10 17:38:17 by fcorbel           #+#    #+#              #
#    Updated: 2014/01/07 13:46:28 by fcorbel          ###   ########.fr        #
#                                                                              #
#******************************************************************************#
.PHONY: all $(NAME) clean fclean re

NAME = wolf3d
SRCS = main_wolf3d.c \
	   functions.c \
	   draw.c \
	   init_e.c \
	   get_next_line.c

OBJ  = $(SRCS:.c=.o)
HEAD = header_wolf3d.h

FLAGS = -Wall -Wextra -Werror
FLAGS_MLX = -L/usr/X11/lib/ -lmlx -lXext -lX11

all: $(NAME)

$(NAME): $(OBJ)
	@gcc $(FLAGS) -g -o $@ $^ -I /usr/X11/include/ $(FLAGS_MLX)
	@echo "$(NAME) : done."

%.o:%.c
	@gcc $(FLAGS) -c -o $@ $< -I /usr/X11/include/

clean:
	@rm -f $(OBJ)
	@echo ".o     : deleted."

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) : deleted."

re: fclean all

