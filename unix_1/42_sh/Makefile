# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/23 12:28:41 by fkalb             #+#    #+#              #
#    Updated: 2014/03/27 12:48:53 by fkalb            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
NAME=42sh
LIBS_DIR=./lib/
FLAGS= -W -Wall -Wextra -Werror -O2

INCS = $(addprefix -I, $(addsuffix /includes/, $(INC_DIRS)))
INC_DIRS = . \
		./libft

#LIBS=$(addprefix ./lib/, $(LIB_LIST))
#LIB_LIST=libft.a

DEPEND=$(addprefix $(LIBS_DIR), $(addsuffix .a, $(DEPEND_LST)))
DEPEND_MAKE=$(addprefix ./, $(DEPEND_LST))
DEPEND_LST=libft

SRCS=$(addprefix ./src/, $(addsuffix .c, $(SRC_LIST)))
SRC_LIST=main\
		 read\
		 quotes\
		 error\
		 env\
		 env2\
		 env_search\
		 newenv\
		 builtins\
		 cd\
		 pipe\
		 exec_cmd\
		 create_args\
		 logic_operator

all : $(LIBS_DIR) $(NAME)

$(LIBS_DIR):
	echo "[ \033[0;33;mcreating lib folder\033[0m ]"
	mkdir $(LIBS_DIR)
	echo "[ \033[0;32;msuccessfuly\033[0m ]" $(LIBS_DIR) "was created"

%.a:
	@make -C $(DEPEND_MAKE)

$(NAME):
	echo "[ \033[0;33;mmake depend\033[0m ]"
	make $(DEPEND)
	echo "[ \033[0;33;mcompiling\033[0m ]"
	$(CC) $(FLAGS) $(DEPEND) $(INCS) $(SRCS) -o $(NAME)
	echo "[ \033[0;32;msuccessfuly\033[0m ]" $(NAME) "was created"

clean:
	echo "[ \033[0;33;mcleaning\033[0m ]"
	make clean -C./libft/
	rm -rf lib/

fclean: clean
	make fclean -C./libft/ && rm -f $(NAME)
	echo "[ \033[0;31;mdel\033[0m ]"$(NAME)

re: fclean all

.SILENT: all $(NAME) $(LIBS_DIR) clean fclean re

