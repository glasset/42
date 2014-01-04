# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmizzi <cmizzi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/13 18:19:17 by cmizzi            #+#    #+#              #
#    Updated: 2013/12/13 18:19:21 by cmizzi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_minishell1

FILES	= ft_builtins.c ft_cd.c ft_exec.c ft_getenv.c ft_minishell_loop.c \
	ft_putendl.c ft_putstr.c ft_setenv.c ft_str_split.c ft_strcat.c \
	ft_strcmp.c ft_strcpy.c ft_strjoin.c ft_strlen.c ft_unsetenv.c main.c \

CFLAG	= -c
LDFLAG	= -Werror -Wextra -Wall
CC	= gcc

OBJ	= $(FILES:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

.c.o:
	$(CC) -c $(LDFLAG) $< -o $@

clean:
	/bin/rm -f $(OBJ)

fclean:		clean
	/bin/rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
