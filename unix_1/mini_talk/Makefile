# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glasset <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/06 10:39:11 by glasset           #+#    #+#              #
#    Updated: 2014/02/03 13:42:36 by glasset          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Mini_talk

.PHONY: all
all: $(NAME)

$(NAME):
	@make -C printf/
	@make -C servers/
	@make -C users/
	@echo "$(NAME) compil down."

.PHONY: clean
clean:
	@make -C printf/ clean
	@make -C servers/ clean
	@make -C users/ clean

.PHONY: fclean
fclean: clean
	@make -C printf/ fclean
	@make -C servers/ fclean
	@make -C users/ fclean

.PHONY: re
re: fclean all
