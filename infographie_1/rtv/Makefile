# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/22 15:58:47 by jbalestr          #+#    #+#              #
#    Updated: 2014/03/04 11:58:01 by glasset          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME =	Ray_Tracer
CC =	gcc
LIB =	-L gnl/ -L /usr/X11/lib/ -L minilibx/ -lmlx -lXext -lX11 -lm -lftgnl
FLAGS =	-g -Wall -Wextra -Werror
SDIR =	sources/
ODIR =	objects/
IDIR =	-I includes/ -I /usr/X11/include/ -I gnl/includes
SRC =	main.c init.c events.c key_events.c helpers.c init_keys.c init_image.c \
		vector_op.c vector_fun.c draw.c init_tab.c intersect.c inter_mesh.c \
		diffuse.c normal.c rename.c parser.c init_scene.c ft_strsub.c \
		ft_atoi.c ft_strsplit.c ft_atod.c tool.c
OBJ =	$(SRC:.c=.o)
EXT =	includes/ray_tracer.h includes/objects.h
S =		$(addprefix $(SDIR), $(SRC))
O =		$(addprefix $(ODIR), $(OBJ))

all: lib $(NAME)

$(NAME): $(O) $(EXT)
	@echo "-> Creating $(NAME)..."
	@$(CC) $(FLAGS) -o $@ $^ $(IDIR) $(LIB)
	@echo "-> Done !"

$(ODIR)%.o: $(SDIR)%.c
	@echo "-> Compiling $<..."
	@$(CC) $(FLAGS) -c $< -o $@ $(IDIR)

lib:
	@make -C gnl/
	@make -C minilibx/

$(O): | ./objects
./objects:
	@mkdir $(ODIR)

clean:
	@echo "-> Cleaning object files..."
	@rm -rf $(ODIR)
	@make clean -C gnl/
	@make clean -C minilibx/

fclean: clean
	@echo "-> Cleaning $(NAME)..."
	@rm -f $(NAME)
	@make fclean -C gnl/

re: fclean all
