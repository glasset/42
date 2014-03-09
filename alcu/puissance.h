/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 11:17:22 by glasset           #+#    #+#             */
/*   Updated: 2014/03/09 15:55:31 by gmarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUISSANCE_H
# define PUISSANCE_H
# include "libft.h"
# define MIN_L 6
# define MIN_C 7
# define PAWNS_IA 'O'
# define PAWNS_HUM 'X'

typedef enum			e_players
{
	IA,
	HUMAN
}						t_players;

typedef struct			s_env
{
	int					(*f_player)(struct s_env *);
	int					line;
	int					col;
	char				**board;
	char				*name;
	int					curr_line;
}						t_env;

/*
** Generic game functions:
*/
int				put_error(char *str, int ernum);
int				only_nb(char *str, int min);
int				init_board(t_env *e);
int				check_victory(char p, t_env *e, int	curr_col);
int				init_env(t_env *e, char **av, char **env);
int				play_round(t_env *e, int	player);
int				check_value(t_env *e, int choice);
void			print_board(t_env *e);
int				ft_sum(int n);
void			put_charcolor(char c, char *color);
/*
** Easy IA functions:
*/
int				human(t_env *e);
int				easy_ia(t_env *e);
int				evaluate_p(t_env *e, int col, char p);

#endif /* !PUISSANCE_H */
