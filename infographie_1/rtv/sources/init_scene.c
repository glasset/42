/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 17:56:47 by glasset           #+#    #+#             */
/*   Updated: 2014/03/03 13:46:58 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ray_tracer.h"
#include "my.h"

int			init_s(t_env *e, char *str, int m)
{
	int		i;
	char	*s;
	char	**tmp;

	i = 0;
	while (str[i] < '0' && str[i] > '9')
		i++;
	s = ft_strsub(str, i, ft_strlen(str));
	tmp = ft_strsplit(s, '[');
	e->meshes[m].type = T_SPHERE;
	e->meshes[m].prim.sphere.radius = ft_atoi(tmp[4]);
	e->meshes[m].prim.sphere.pos = init_vec(ft_atoi(tmp[1]),
	ft_atoi(tmp[2]), ft_atoi(tmp[3]));
	e->meshes[m].color.r = 0.7;
	e->meshes[m].color.g = 0.7;
	e->meshes[m].color.b = 0.7;
	e->meshes[m].diff = 1.0;
	return (m + 1);
}

int			init_l(t_env *e, char *str, int m)
{
	int		i;
	char	*s;
	char	**tmp;

	i = 0;
	while (str[i] < '0' && str[i] > '9')
		i++;
	s = ft_strsub(str, i, ft_strlen(str));
	tmp = ft_strsplit(s, '[');
	e->lights[0].color.r = 0.7;
	e->lights[0].color.g = 0.7;
	e->lights[0].color.b = 0.7;
	e->lights[0].pos = init_vec(ft_atoi(tmp[0]),
	ft_atoi(tmp[1]), ft_atoi(tmp[2]));
	return (m);
}

void			init_scene(t_env *e, char *path)
{
	e->ambient = 0.1;
	parse(e, path);
}
