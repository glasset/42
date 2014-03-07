/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 17:56:47 by glasset           #+#    #+#             */
/*   Updated: 2014/03/07 13:57:14 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my.h"
#include <stdlib.h>

/*
**	add pointer sur fonction pour init_mesh
*/
int				init_mesh(t_env *e, char *str)
{
	static int	c = 0;
	int			tmp;

	if (e->nb_mesh == c)
		return (-1);
	if (e->nb_mesh == -1)
		return (-3);
	if (str[0] == 'S')
		tmp = init_s(e, str, c);
	if (str[0] == 'c')
		tmp =  init_cyl(e, str, c);
	if (str[0] == 'C')
		tmp  = init_cone(e, str, c);
	if (str[0] == 'P')
		tmp = init_p(e, str, c);
	if (tmp == 0)
		c++;
	return (tmp);
}

int				init_l(t_env *e, char *str)
{
	char		**tmp;
	static int	c = 0;

	if (e->nb_light == c)
		return (-2);
	if (e->nb_light == -1)
		return (-3);
	tmp = ft_strsplit(str, '[');
	if (no_name(tmp, 5) == -4)
		return (-4);
	e->lights[c].color = get_color(tmp[4]);
	e->lights[c++].pos = init_vec(ft_atoi(tmp[1]),
	ft_atoi(tmp[2]), ft_atoi(tmp[3]));
	return (0);
}

int				badcoeff(char **tmp, int start)
{
	int			j;

	while (tmp[start + 1] != NULL)
	{
		j = 0;
		if (ft_atod(tmp[start]) >= 0.0 && ft_atod(tmp[start]) <= 1.0)
			j++;
		if (j == 0)
			return (0);
		start++;
	}
	return (1);
}

int				ambient(t_env *e, char *str)
{
	int		i;
	char	*nb;

	i = 0;
	while (str[i] != ':')
		i++;
	nb = ft_strsub(str, (i + 1), ft_strlen(str));
	if (ft_atod(nb) >= 0.0 && ft_atod(nb) <= 1.0)
		e->ambient = ft_atod(nb);
	else
		return (-6);
	return (0);
}

void			init_scene(t_env *e, char *path)
{
	e->nb_mesh = -1;
	e->nb_light = -1;
	e->ambient = 0.1;
	e->look_at_point = init_vec(0, 0, 0);
	e->cam.pos = init_vec(0, 0, 0);
	parse(e, path);
}
