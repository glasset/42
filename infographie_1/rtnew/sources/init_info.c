/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 15:41:58 by glasset           #+#    #+#             */
/*   Updated: 2014/03/14 16:31:08 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "parser.h"
#include <stdio.h>

i			*ft_inf(void)
{
	i		*ft;

	ft = malloc(sizeof(ft) * 6);
	ft[0] = &comment_b;
	ft[1] = &nb_light;
	ft[2] = &nb_mesh;
	ft[3] = &pov;
	ft[4] = &look;
	ft[5] = &ambient;
	return (ft);
}

int			ambient(t_env *e, char *str)
{
	char	**tmp;

	tmp = ft_strsplit(str, BREAK);
	if (tmp[1] == NULL || check_arg(tmp[1], 1) == -1)
		return (-1);
	e->ambient = ft_atod(tmp[1]);
	return (0);
}

int			look(t_env *e, char *str)
{
	char	**tmp;
	int		i;

	i = -1;
	tmp = ft_strsplit(str, BREAK);
	if (tmp[1] == NULL)
		return (-1);
	tmp = ft_strsplit(tmp[1], ' ');
	while (tmp[++i] != NULL)
	{
		if (check_arg(tmp[i], 0) == -1)
			return (-1);
	}
	if (i != 3)
		return (-1);
	e->look_at_point = init_vec(ft_atod(tmp[0]), ft_atod(tmp[1]),
			ft_atod(tmp[2]));
	return (0);
}

int			pov(t_env *e, char *str)
{
	char	**tmp;
	int		i;

	i = -1;
	tmp = ft_strsplit(str, BREAK);
	if (tmp[1] == NULL)
		return (-1);
	tmp = ft_strsplit(tmp[1], ' ');
	i = i ;
/*	while (tmp[++i] != NULL)
	{
		if (check_arg(tmp[i], 0) == -1)
			return (-1);
	}
	if (i != 3)
		return (-1);*/
	e->cam.pos = init_vec(ft_atod(tmp[0]), ft_atod(tmp[1]),
			ft_atod(tmp[2]));

	return (0);
}

int			checkline_inf(char *str)
{
	char	**tmp;
	if (str[0] == START_OBJ || str[0] == COMMENT)
		return (0);
	tmp = ft_strsplit(str, BREAK);
	tmp[0] = ft_strsub(tmp[0], cut_space(tmp[0]), ft_strlen(tmp[0]));
	if (!ft_strcmp(tmp[0], "numbers of light"))
		return (1);
	if (!ft_strcmp(tmp[0], "numbers of object"))
		return (2);
	if (!ft_strcmp(tmp[0], "point of view"))
		return (3);
	if (!ft_strcmp(tmp[0], "look at"))
		return (4);
	if (!ft_strcmp(tmp[0], "color ambient"))
		return (5);
	return (-1);
}

int			all_init(t_env *e)
{
	if (e->nb_mesh < 0 && e->nb_light > 0)
		return (-1);
	return (0);
}

int			nb_mesh(t_env *e, char *str)
{
	char	**tmp;

	tmp = ft_strsplit(str, BREAK);
	if (tmp[1] == NULL || check_arg(tmp[1], 0) == -1)
		return (-1);
	e->nb_mesh = ft_atoi(tmp[1]);
	e->meshes = (t_mesh *)malloc(sizeof(t_mesh) * e->nb_mesh);
	return (0);
}

int			nb_light(t_env *e, char *str)
{
	char	**tmp;

	tmp = ft_strsplit(str, BREAK);
	if (tmp[1] == NULL || check_arg(tmp[1], 0) == -1)
		return (-1);
	e->nb_light = ft_atoi(tmp[1]);
	e->lights = (t_light *)malloc(sizeof(t_light) * e->nb_light);
	return (0);
}

int			information(t_env *e, int c_l, int fd, char *str)
{
	char	*line;
	int		l;
	i		*ft;

	(void)c_l;
	(void)str;
	l = 1;
	ft = ft_inf();
	while (get_next_line(fd, &line))
	{
		if (line[0] == END_OBJ)
			return (l);//error(all_init(e), l));
		if (checkline_inf(line) == -1)
			write(1, "BADI\n", 5);// 3error("BAD LINE IGNORED);
		else
			ft[checkline_inf(line)](e, line);
		free(line);
		l++;
	}
	return (l);
}
