/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 14:39:01 by glasset           #+#    #+#             */
/*   Updated: 2014/01/26 22:42:20 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# define P_1 'O'
# define P_2 'X'
# include "libft.h"

typedef struct			s_dot
{
	int					x;
	int					y;
}						t_dot;

typedef struct			s_env
{
	t_dot				piece_first;
	char				player;
	char				opponent;
	char				**board;
	char				**piece;
	int					board_size;
	int					board_size_len;
	t_dot				piece_size;
	t_dot				*piece_pst;
	t_dot				*board_pst;
	int					nbr_board;
	int					nbr_piece;
}						t_env;

void					read_board_size(t_env *e);
void					read_board(t_env *e);
void					read_piece(t_env *e);
void					ft_read(t_env *e);

int						use_piece(t_env *e);
void					check_piece(t_env *e);
void					check_board(t_env *e);
int						print(t_env *e, int x, int y, int tmp);
void					resize(t_env *e);
t_dot					ajust(t_env *e, int x, int y, int x2, int y2);
int						ft_abs(t_dot xy, t_dot p2, int y1, int x2);
void					freedom(char **tab);
#endif /* !FILLER_H */
