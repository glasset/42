/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_meshe_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset </var/mail/glasset>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 12:37:07 by glasset           #+#    #+#             */
/*   Updated: 2014/03/25 14:41:31 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int				m_scale(t_env *e, char *str, int c, int flag)
{
	char		**tmp;

	(void)flag;
	tmp = ft_strsplit(str, BREAK);
	tmp = ft_strsplit(tmp[1], BREAK2);
	if (check_arg(tmp[0], 1) == -1)
		return (-2);
	if (check_arg(tmp[1], 1) == -1)
		return (-2);
	if (check_arg(tmp[2], 1) == -1)
		return (-2);
	inv_scale_matrix(&e->meshes[c].scale, ft_atod(tmp[0]), ft_atod(tmp[1]), ft_atod(tmp[2]));
	return (0);
}

int				m_position(t_env *e, char *str, int c, int flag)
{
	static char	**tmp;
	static int	i = 0;

	(void)flag;
	if (i == 0)
	{
		tmp = ft_strsplit(str, BREAK);
		tmp = ft_strsplit(tmp[1], BREAK2);
		if (check_arg(tmp[0], 0) == -1)
			return (-2);
		if (check_arg(tmp[1], 0) == -1)
			return (-2);
		if (check_arg(tmp[2], 0) == -1)
			return (-2);
		e->meshes[c].trans = malloc_matrix(4, 4);
		i = 1;
	}
	else
	{
		inv_trans_matrix(&e->meshes[c].trans, ft_atod(tmp[0]), ft_atod(tmp[1]),
				ft_atod(tmp[2]));
		compute_matrix(&e->meshes[c]);
		i = 0;
	}
	return (2);
}

int				min_arg(int flag)
{
	if (flag == T_HYPERBOLE)
		return (3);
	if (flag == T_TRIANGLE)
		return (4);
	return (2);
}

void			init_base(t_env *e, int flag, int c)
{
	(void)flag;
	e->meshes[c].rot_x = malloc_matrix(4, 4);
	e->meshes[c].rot_y = malloc_matrix(4, 4);
	e->meshes[c].rot_z = malloc_matrix(4, 4);
	inv_rot_matrix_x(&e->meshes[c].rot_x, 0.0);
	inv_rot_matrix_y(&e->meshes[c].rot_y, 0.0);
	inv_rot_matrix_z(&e->meshes[c].rot_z, 0.0);
	e->meshes[c].mat.type = NO_MAT;
	e->meshes[c].color.r = 0.5;
	e->meshes[c].color.g = 0.5;
	e->meshes[c].color.b = 0.5;
	e->meshes[c].diff = 0.8;
	e->meshes[c].spec = 0.8;
	e->meshes[c].refl = 0.0;
	e->meshes[c].refr = 0.0;
	e->meshes[c].scale = malloc_matrix(4, 4);
	inv_scale_matrix(&e->meshes[c].scale, 0.2, 0.2, 0.2);
}
