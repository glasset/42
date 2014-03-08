/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 11:17:22 by glasset           #+#    #+#             */
/*   Updated: 2014/03/08 17:21:35 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUISSANCE_H
# define PUISSANCE_H
# include "libft.h"
# define MIN_L 6
# define MIN_C 7
# define PLAYER_IA 'O'
# define PLAYER_HUM 'X'

typedef enum			e_players
{
	IA,
	PLAYER
}						t_players;

typedef struct			s_env
{
	int					line;
	int					col;
	int					value;
	char				**board;
	char				*name;
}						t_env;

int				put_error(char *str, int ernum);
int				only_nb(char *str, int min);
int				init_board(t_env *e);
int				init_value(t_env *e);
//void			resolve(t_env *e);
void			print_board(t_env *e);
int				init_env(t_env *e, char **av, char **env);

#endif /* !PUISSANCE_H */
