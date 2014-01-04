# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glasset <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/29 16:03:59 by glasset           #+#    #+#              #
#    Updated: 2013/12/29 18:39:56 by glasset          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
.PHONY: all $(NAME) clean fclean re

NAME= push_swap

SRCS= ./lst.c ./l_sort.c ./main.c ./p_swap.c ./r_swap.c ./s_swap.c \
	  ./ft_atoi.c

OBJ= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(SRCS)
	gcc -Wall -Wextra -Werror -c $? -I ./
	gcc -o $(NAME) $(OBJ)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
