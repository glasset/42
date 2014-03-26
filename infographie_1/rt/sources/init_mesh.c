/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mesh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 11:56:07 by glasset           #+#    #+#             */
/*   Updated: 2014/03/26 18:54:04 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "parser.h"

m				*ft_inm(void)
{
	m			*ft;

	ft = malloc(sizeof(ft) * 16);
	ft[0] = &comment_m;
	ft[1] = &color_m;
	ft[2] = &m_diffuse;
	ft[3] = &m_specular;
	ft[4] = &m_reflection;
	ft[5] = &m_refraction;
	ft[6] = &m_normal;
	ft[7] = &m_rotate;
	ft[8] = &m_radius;
	ft[9] = &m_coef;
	ft[10] = &m_position;
	ft[11] = &m_scale;
	ft[12] = &m_open;
	ft[13] = &m_v;
	ft[14] = &m_mat;
	ft[15] = &m_perlin;
	return (ft);
}

static int		check_lm(char **tmp)
{
	if (!ft_strcmp(tmp[0], "position"))
		return (10);
	if (!ft_strcmp(tmp[0], "scale"))
		return (11);
	if (!ft_strcmp(tmp[0], "open"))
		return (12);
	if (!ft_strcmp(tmp[0], "vertex"))
		return (13);
	if (!ft_strcmp(tmp[0], "material"))
		return (14);
	if (!ft_strcmp(tmp[0], "perlin"))
		return (15);
	return (-1);
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
	if (!ft_strcmp(tmp[0], "rotation"))
		return (7);
	if (!ft_strcmp(tmp[0], "radius"))
		return (8);
	if (!ft_strcmp(tmp[0], "coef"))
		return (9);
	return (check_lm(tmp));
}

static int		init_all_m(t_env *e, char *str, int c)
{
	int			flag;

	if (!ft_strcmp(str, "Sphere"))
		flag = init_flag(e, T_SPHERE, c);
	if (!ft_strcmp(str, "Plan"))
		flag = init_flag(e, T_PLAN, c);
	if (!ft_strcmp(str, "Cylinder"))
		flag = init_flag(e, T_CYLINDER, c);
	if (!ft_strcmp(str, "Cone"))
		flag = init_flag(e, T_CONE, c);
	if (!ft_strcmp(str, "Parabole"))
		flag = init_flag(e, T_PARABOLE, c);
	if (!ft_strcmp(str, "Hyperbole"))
		flag = init_flag(e, T_HYPERBOLE, c);
	if (!ft_strcmp(str, "Triangle"))
		flag = init_flag(e, T_TRIANGLE, c);
	init_base(e, flag, c);
	return (flag);
}

int				init_mesh(t_env *e, int c_l, int fd, char *str)
{
	t_imesh		j;

	j.count = 0;
	j.l = 1;
	e->i_pos = 0;
	if (e->nb_mesh == e->nb_mesh_malloc || e->nb_mesh_malloc == -1)
		return (check_mesh_nb(str, fd, c_l));
	j.flag = init_all_m(e, str, e->nb_mesh);
	while (get_next_line(fd, &j.line))
	{
		j.tmp = 0;
		j.cbis = e->nb_mesh;
		j.ret_m = check_end_mesh(e, &j, str, c_l);
		if (j.ret_m > -1)
			return (j.l);
		call_ft(e, &j, e->nb_mesh, c_l);
		if (check_tmp(j.line, c_l, j.l, j.tmp) == 0)
			return (j.l);
		else if (j.tmp == 2)
			j.count++;
		j.l++;
	}
	return (j.l);
}
