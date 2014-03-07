/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rename.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 19:38:49 by glasset           #+#    #+#             */
/*   Updated: 2014/03/07 13:51:14 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my.h"
#include <stdlib.h>

int			comment(t_env *e, char *str)
{
	str = str;
	e = e;
	return (-5);
}

int			nbmesh(t_env *e, char *str)
{
	int		i;
	char	*nb;

	i = 2;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	nb = ft_strsub(str, 2, (i - 2));
	e->nb_mesh = ft_atoi(nb);
	e->meshes = (t_mesh *)malloc(sizeof(t_mesh) * e->nb_mesh);
	return (0);
}

int			nblight(t_env *e, char *str)
{
	int		i;
	char	*nb;

	i = 2;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	nb = ft_strsub(str, 2, (i - 2));
	e->nb_light = ft_atoi(nb);
	e->lights = (t_light *)malloc(sizeof(t_light) * e->nb_light);
	return (0);
}

int			lookat(t_env *e, char *str)
{
	int		i;
	char	*nb;
	char	**tmp;

	i = 0;
	while (str[i] < '0' || str[i] > '9')
		i++;
	nb = ft_strsub(str, i, (ft_strlen(str) - i));
	tmp = ft_strsplit(nb, ' ');
	e->look_at_point = init_vec(ft_atoi(tmp[0]), ft_atoi(tmp[1]),
	ft_atoi(tmp[2]));
	return (0);
}

int			pov(t_env *e, char *str)
{
	int		i;
	char	*nb;
	char	**tmp;

	i = 0;
	while (str[i] < '0' || str[i] > '9')
		i++;
	nb = ft_strsub(str, i, (ft_strlen(str) - i));
	tmp = ft_strsplit(nb, ' ');
	e->cam.pos = init_vec(ft_atoi(tmp[0]), ft_atoi(tmp[1]), ft_atoi(tmp[2]));
	return (0);
}
