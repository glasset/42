/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 13:03:55 by glasset           #+#    #+#             */
/*   Updated: 2014/03/22 13:00:17 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# define START 1
# define END 2
# define ROOM 3
# define TUBE 0
# define COMMENT -1
# define NBR_ANTS -2
# include "libft.h"

typedef struct			s_ch
{
	char				*name;
	int					pos;
	int					weight;
	char				*back;
	int					*xy;
	struct s_lst		*tube;
	struct s_ch			*next;
	struct s_ch			*prev;
}						t_ch;

typedef struct			s_lst
{
	size_t				len;
	struct s_ch			*start;
	struct s_ch			*end;
}						t_lst;

typedef struct			s_env
{
	struct s_lst		*room;
	int					ants;
	char				**tube;
}						t_env;

void			make(char **cord, int status, t_env *e);
int				check_ants(char *line, t_env *e);
char			char_split(int status);
t_lst			*lst_new(void);
t_lst			*lst_add_end(t_lst *l_xm, char *name, int *xy, int pos);
void			init(t_env *e);
void			parser(t_env *e);
void			print(t_env *e);
void			error(void);
void			shoort(t_env *e);
void			seek_room(t_env *e, int pos, char *name);
void			make_tube(char **cord, t_env *e, int status);

#endif /* !LEMIN_H */
