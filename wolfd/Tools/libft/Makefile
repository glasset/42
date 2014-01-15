#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcorbel <fcorbel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 17:58:52 by fcorbel           #+#    #+#              #
#    Updated: 2013/12/16 19:03:35 by fcorbel          ###   ########.fr        #
#                                                                              #
#******************************************************************************#
.PHONY: all $(NAME) clean fclean re

NAME = libft.a
SRCS =	./ft_atoi.c \
		./ft_bzero.c \
		./ft_memchr.c \
		./ft_strlen.c \
		./ft_strdup.c \
		./ft_memdel.c \
		./ft_strclr.c \
		./ft_strjoin.c \
		./ft_strnew.c \
		./ft_strsub.c \
		./ft_strsplit.c \
		./ft_abs.c


OBJ  = $(SRCS:.c=.o)
HEAD = includes/

all: $(NAME)

$(NAME): $(SRCS)
	@gcc -Wall -Wextra -Werror -c $(SRCS) $? -I $(HEAD)
	@ar rc $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

