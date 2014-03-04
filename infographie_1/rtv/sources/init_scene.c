/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 17:56:47 by glasset           #+#    #+#             */
/*   Updated: 2014/03/04 12:20:51 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ray_tracer.h"
#include "my.h"

int				init_s(t_env *e, char *str, int m)
{
	char		**tmp;
	static int	c = 0;

	tmp = ft_strsplit(str, '[');
	if (e->nb_mesh == c)
		return (-1);
	if (e->nb_mesh == -1)
		return (-3);
	e->meshes[c].type = T_SPHERE;
	e->meshes[c].prim.sphere.radius = ft_atoi(tmp[4]);
	e->meshes[c].prim.sphere.pos = init_vec(ft_atoi(tmp[1]),
	ft_atoi(tmp[2]), ft_atoi(tmp[3]));
	e->meshes[c].color = get_color(tmp[5]);
	e->meshes[c++].diff = ft_atod(tmp[6]) ;
	return (m);
}

int				init_l(t_env *e, char *str, int m)
{
	char		**tmp;
	static int	c = 0;

	if (e->nb_light == c)
		return (-2);
	if (e->nb_light == -1)
		return (-3);
	tmp = ft_strsplit(str, '[');
	e->lights[c].color = get_color(tmp[4]);
	e->lights[c++].pos = init_vec(ft_atoi(tmp[1]),
	ft_atoi(tmp[2]), ft_atoi(tmp[3]));
	return (m);
}

int				ambiant(t_env *e, char *str, int m)
{
	int		i;
	char	*nb;

	i = 0;
	while (str[i] != ':')
		i++;
	nb = ft_strsub(str, (i + 1), ft_strlen(str));
	e->ambient = ft_atod(nb);
	return (m);
}

void			init_scene(t_env *e, char *path)
{
	e->nb_mesh = -1;
	e->nb_light = -1;
	parse(e, path);
}
