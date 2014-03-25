/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_light_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 14:14:45 by glasset           #+#    #+#             */
/*   Updated: 2014/03/25 14:34:50 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser.h"

l				*ft_inl(void)
{
	l			*ft;

	ft = malloc(sizeof(ft) * 3);
	ft[0] = &comment_l;
	ft[1] = &color_l;
	ft[2] = &pos_l;
	return (ft);
}

int				comment_l(t_env *e, char *str, int c)
{
	e = e;
	c = c;
	str = str;
	return (0);
}

int				color_l(t_env *e, char *str, int c)
{
	char		**tmp;

	tmp = ft_strsplit(str, BREAK);
	tmp[1] = ft_strsub(tmp[1], cut_space(tmp[1]), ft_strlen(tmp[1]));
	if (check_col(tmp[1]) == -1)
	{
		e->lights[c].color = get_color("0x555555");
		return (-1);
	}
	else
		e->lights[c].color = get_color(tmp[1]);
	return (0);
}

int				pos_l(t_env *e, char *str, int c)
{
	char		**tmp;

	tmp = ft_strsplit(str, BREAK);
	tmp = ft_strsplit(tmp[1], BREAK2);
	if (check_arg(tmp[0], 0) == -1)
			return (-2);
	if (check_arg(tmp[1], 0) == -1)
			return (-2);
	if (check_arg(tmp[2], 0) == -1)
			return (-2);
	e->lights[c].pos = init_vec(ft_atod(tmp[0]), ft_atod(tmp[1]),
			ft_atod(tmp[2]));
	return (0);
}

int				checkline_light(char *str)
{
	char		**tmp;

	if (str[0] == START_OBJ || str[0] == COMMENT)
		return (0);
	tmp = ft_strsplit(str, BREAK);
	tmp[0] = ft_strsub(tmp[0], cut_space(tmp[0]), ft_strlen(tmp[0]));
	if (!ft_strcmp(tmp[0], "color"))
		return (1);
	if (!ft_strcmp(tmp[0], "position"))
		return (2);
	return (-1);
}
