/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 13:03:55 by glasset           #+#    #+#             */
/*   Updated: 2014/03/11 16:46:33 by glasset          ###   ########.fr       */
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

t_lst			*lst_new(void);
t_lst			*lst_add_end(t_lst *l_xm, char *name, int *xy, int pos);
void			parser(t_env *e);
void			error(void);

#endif /* !LEMIN_H */
