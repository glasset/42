/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mesh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset </var/mail/glasset>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 11:56:07 by glasset           #+#    #+#             */
/*   Updated: 2014/03/14 15:44:38 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "parser.h"

m				*ft_inm(void)
{
	m			*ft;

	ft = malloc(sizeof(ft) * 11);
	ft[0] = &comment_m;
	ft[1] = &color_m;
	ft[2] = &m_diffuse;
	ft[3] = &m_specular;
	ft[4] = &m_reflection;
	ft[5] = &m_refraction;
	ft[6] = &m_normal;
	ft[7] = &m_direction;
	ft[8] = &m_radius;
	ft[9] = &m_coef;
	ft[10] = &m_position;
	return (ft);
}

int				checkline_mesh(char *str)
{
	char	**tmp;

	if (str[0] == START_OBJ || str[0] == COMMENT)
		return (0);
	tmp = ft_strsplit(str, BREAK);
	tmp[0] = ft_strsub(tmp[0], cut_space(tmp[0]), ft_strlen(tmp[0]));
	if (!ft_strcmp(tmp[0], "color"))
		return (1);
	if (!ft_strcmp(tmp[0], "diffuse"))
		return (2);
	if (!ft_strcmp(tmp[0], "specular"))
		return (3);
	if (!ft_strcmp(tmp[0], "reflection"))
		return (4);
	if (!ft_strcmp(tmp[0], "refraction"))
		return (5);
	if (!ft_strcmp(tmp[0], "normal"))
		return (6);
	if (!ft_strcmp(tmp[0], "direction"))
		return (7);
	if (!ft_strcmp(tmp[0], "radius"))
		return (8);
	if (!ft_strcmp(tmp[0], "coef"))
		return (9);
	if (!ft_strcmp(tmp[0], "position"))
		return (10);
	return (-1);
}

#include <stdio.h>

int				init_mesh(t_env *e, int c_l, int fd, char *str)
{
	static int	c = 0;
	int			l;
	int			flag;
	char		*line;
	m			*ft;

	(void)c_l;
	ft = ft_inm();
	l = 1;
	if (c == e->nb_mesh || e->nb_mesh == -1)
	{
		write(1, "er\n", 3);//error ("L:x Object ignored");
		while (get_next_line(fd, &line))
		{
			if (line[0] == END_OBJ)
				break ;
			l++;
		}
		return (l);
	}
	if (!ft_strcmp(str, "Sphere"))
		flag = init_flag(e, T_SPHERE, c);
	while (get_next_line(fd, &line))
	{
		if (line[0] == END_OBJ)
		{
			c++;
			return (l);//check all init
		}
		if (checkline_mesh(line) == -1)
			write(1, "BAD\n", 4);//error("bad lineda");
		else
			ft[checkline_mesh(line)](e, line, c, flag);
		free(line);
		l++;
	}
	return (l);
}
