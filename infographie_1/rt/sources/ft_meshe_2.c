/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_meshe_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 14:11:01 by glasset           #+#    #+#             */
/*   Updated: 2014/03/26 09:43:51 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int				m_normal(t_env *e, char *str, int c, int flag)
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
	if (flag == T_PLAN)
	{
		e->meshes[c].prim.plan.normal = init_vec(ft_atod(tmp[0]),
				ft_atod(tmp[1]), ft_atod(tmp[2]));
		return (2);
	}
	if (flag == T_TRIANGLE)
	{
		e->meshes[c].prim.triangle.normal = init_vec(ft_atod(tmp[0]),
				ft_atod(tmp[1]), ft_atod(tmp[2]));
		return (2);
	}
	return (-1);
}

int				m_rotate(t_env *e, char *str, int c, int flag)
{
	char		**tmp;

	(void)flag;
	tmp = ft_strsplit(str, BREAK);
	tmp = ft_strsplit(tmp[1], BREAK2);
	if (check_arg(tmp[0], 0) == -1)
		return (-2);
	if (check_arg(tmp[1], 0) == -1)
		return (-2);
	if (check_arg(tmp[2], 0) == -1)
		return (-2);
	inv_rot_matrix_x(&e->meshes[c].rot_x, ft_atod(tmp[0]));
	inv_rot_matrix_y(&e->meshes[c].rot_y, ft_atod(tmp[1]));
	inv_rot_matrix_z(&e->meshes[c].rot_z, ft_atod(tmp[2]));
	return (0);
}

int				m_coef(t_env *e, char *str, int c, int flag)
{
	char		**tmp;

	tmp = ft_strsplit(str, BREAK);
	if (check_arg(tmp[1], 1) == -1)
		return (-2);
	if (flag == T_CONE)
		e->meshes[c].prim.cone.coeff = ft_atod(tmp[1]);
	else if (flag == T_PARABOLE)
		e->meshes[c].prim.parabole.coeff = ft_atod(tmp[1]);
	else if (flag == T_HYPERBOLE)
		e->meshes[c].prim.hyperbole.coeff = ft_atod(tmp[1]);
	else
		return (-1);
	return (2);
}

int				init_flag(t_env *e, int type, int c)
{
	e->meshes[c].type = type;
	return (type);
}

int				color_m(t_env *e, char *str, int c, int flag)
{
	char		**tmp;

	(void)flag;
	tmp = ft_strsplit(str, BREAK);
	tmp[1] = ft_strsub(tmp[1], cut_space(tmp[1]), ft_strlen(tmp[1]));
	if (check_col(tmp[1]) == -1)
		return (-1);
	e->meshes[c].color = get_color(tmp[1]);
	return (0);
}
