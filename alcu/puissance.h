/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 11:17:22 by glasset           #+#    #+#             */
/*   Updated: 2014/03/08 18:56:59 by gmarais          ###   ########.fr       */
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
	int					line;
	int					col;
	char				**board;
	char				*name;
	int					curr_line;
}						t_env;

int				put_error(char *str, int ernum);
int				only_nb(char *str, int min);
int				init_board(t_env *e);
int				check_victory(char p, t_env *e, int	curr_col);
void			print_board(t_env *e);
int				init_env(t_env *e, char **av, char **env);
int				play_round(t_env *e, int	player);

#endif /* !PUISSANCE_H */
