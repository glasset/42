/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 14:18:05 by glasset           #+#    #+#             */
/*   Updated: 2014/03/25 14:52:25 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser.h"

int			ambient(t_env *e, char *str)
{
	char	**tmp;

	tmp = ft_strsplit(str, BREAK);
	if (tmp[1] == NULL || check_arg(tmp[1], 1) == -1)
		return (-1);
	e->ambient = ft_atod(tmp[1]);
	return (0);
}

int			nb_mesh(t_env *e, char *str)
{
	char	**tmp;

	tmp = ft_strsplit(str, BREAK);
	if (tmp[1] == NULL || check_arg(tmp[1], 0) == -1)
		return (-1);
	e->nb_mesh_malloc = ft_atoi(tmp[1]);
	e->meshes = (t_mesh *)malloc(sizeof(t_mesh) * e->nb_mesh_malloc);
	return (0);
}

int			nb_light(t_env *e, char *str)
{
	char	**tmp;

	tmp = ft_strsplit(str, BREAK);
	if (tmp[1] == NULL || check_arg(tmp[1], 0) == -1)
		return (-1);
	e->nb_light_malloc = ft_atoi(tmp[1]);
	e->lights = (t_light *)malloc(sizeof(t_light) * e->nb_light_malloc);
	return (0);
}

int			look(t_env *e, char *str)
{
	char	**tmp;

	tmp = ft_strsplit(str, BREAK);
	if (tmp[1] == NULL)
		return (-1);
	tmp = ft_strsplit(tmp[1], BREAK2);
	if (check_arg(tmp[0], 0) == -1)
		return (-1);
	if (check_arg(tmp[1], 0) == -1)
		return (-1);
	if (check_arg(tmp[2], 0) == -1)
		return (-1);
	e->look_at_point = init_vec(ft_atod(tmp[0]), ft_atod(tmp[1]),
			ft_atod(tmp[2]));
	return (0);
}

int			pov(t_env *e, char *str)
{
	char	**tmp;

	tmp = ft_strsplit(str, BREAK);
	if (tmp[1] == NULL)
		return (-1);
	tmp = ft_strsplit(tmp[1], BREAK2);
	if (check_arg(tmp[0], 0) == -1)
		return (-1);
	if (check_arg(tmp[1], 0) == -1)
		return (-1);
	if (check_arg(tmp[2], 0) == -1)
		return (-1);
	e->cam.pos = init_vec(ft_atod(tmp[0]), ft_atod(tmp[1]),
			ft_atod(tmp[2]));
	return (0);
}
