/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rename.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 19:38:49 by glasset           #+#    #+#             */
/*   Updated: 2014/03/03 13:46:41 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_tracer.h"
#include <stdlib.h>
#include "my.h"
#include <stdio.h>
int			comment(t_env *e, char *str, int m)
{
	str =str;
	e =e;
	return (m);
}

int			nbmesch(t_env *e, char *str, int m)
{
	int		i;
	char	*nb;

	i = 2;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	nb = ft_strsub(str, 2, (i - 2));
	e->nb_mesh = ft_atoi(nb);
	e->meshes = (t_mesh *)malloc(sizeof(t_mesh) * e->nb_mesh);
	printf("%d\n", ft_atoi(nb));
	return (m);
}

int			nblight(t_env *e, char *str, int m)
{
	int		i;
	char	*nb;

	i = 2;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	nb = ft_strsub(str, 2, (i - 2));
	e->nb_light = ft_atoi(nb);
	e->lights = (t_light *)malloc(sizeof(t_light) * e->nb_light);
	return (m);
}

int			lookat(t_env *e, char *str, int m)
{
	int		i;
	char	*nb;
	char	**tmp;

	i = 0;
	while (str[i] < '0' || str[i] > '9')
		i++;
	nb = ft_strsub(str, i, (ft_strlen(str) - i));
	tmp = ft_strsplit(nb, ' ');
	if (tmp[3] != '\0')
		exit(0); //too arg
	e->look_at_point = init_vec(ft_atoi(tmp[0]), ft_atoi(tmp[1]),
	ft_atoi(tmp[2]));
	return (m);
}

int			pov(t_env *e, char *str, int m)
{
	int		i;
	char	*nb;
	char	**tmp;

	i = 0;
	while (str[i] < '0' || str[i] > '9')
		i++;
	nb = ft_strsub(str, i, (ft_strlen(str) - i));
	tmp = ft_strsplit(nb, ' ');
	if (tmp[3] != '\0')
		exit(0); //too arg
	e->cam.pos = init_vec(ft_atoi(tmp[0]), ft_atoi(tmp[1]), ft_atoi(tmp[2]));
	return (m);
}
