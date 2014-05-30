# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/23 12:13:17 by fkalb             #+#    #+#              #
#    Updated: 2014/03/27 02:57:11 by fkalb            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
NAME=libft.a
LIB_DIR=../lib/
FLAGS= -W -Wall -Werror -Wextra -O1 -pedantic
OBJ=$(SRC:.c=.o)
SRC=ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
	ft_isprint.c ft_memalloc.c ft_memccpy.c ft_strtrim.c ft_itoa.c \
	ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c \
	ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c \
	ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c \
	ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c \
	ft_striter.c ft_striteri.c ft_strlcat.c ft_strlen.c ft_strncat.c \
	ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c \
	ft_strrchr.c ft_strstr.c ft_tolower.c ft_toupper.c ft_strsub.c \
	ft_strjoin.c ft_strsplit.c ft_strmap.c ft_strmapi.c ft_lstadd.c \
	ft_lstadd_toend.c ft_lstdelone.c ft_lstiter.c ft_lstnew.c \
	ft_strstartwith.c ft_strendwith.c ft_strjoin_free.c ft_strrepl.c \
	ft_strnlen.c ft_strjoin_key.c ft_getline.c ft_strtabdel.c \
	ft_strssplit.c

.SILENT: all $(NAME) clean fclean compil

all : $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(LIB_DIR)$(NAME) $(OBJ)
	echo "[ \033[0;32;msuccessfuly\033[0m ]" $(NAME) "was created"

%.o: %.c
	@$(CC) -c $(FLAGS) -I./includes/ -o $@ $<

clean:
	rm -f $(OBJ)
	echo "[ \033[0;31;mdel\033[0m ]all obj"

fclean: clean
	rm -f $(LIB_DIR)$(NAME)
	echo "[ \033[0;31;mdel\033[0m ]"$(NAME)

re: fclean all
