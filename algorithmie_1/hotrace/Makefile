#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcorbel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/10 17:38:17 by fcorbel           #+#    #+#              #
#    Updated: 2014/01/04 14:14:42 by glasset          ###   ########.fr        #
#                                                                              #
#******************************************************************************#
.PHONY: all $(NAME) clean fclean re

NAME = hotrace
SRCS =  ./main.c \
		./make_data.c \
		./get_line.c \
		./get_info.c \
		./ft_lst.c \
		./ft_putstr.c \
		./ft_strclr.c \
		./ft_strlen.c \
		./ft_strnew.c \
		./ft_strsub.c \
		./ft_memdel.c \
		./ft_strjoin.c \
		./ft_strdup.c \
		./result_data.c \
		./ft_strcmp.c \
		./ft_putendl.c \
		./ft_error.c \
		./ft_memchr.c

OBJ  = $(SRCS:.c=.o)
HEAD = hotrace.h

all: $(NAME)

$(NAME): $(SRCS)
	gcc -Wall -Wextra -Werror -I -c $(SRCS) $?
	gcc -o $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

