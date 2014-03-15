/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset </var/mail/glasset>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 12:37:07 by glasset           #+#    #+#             */
/*   Updated: 2014/03/15 13:22:11 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>
int				comment_m(t_env *e, char *str, int c, int flag)
{
	(void)e;
	(void)str;
	(void)c;
	(void)flag;
	return (0);
}

int				m_normal(t_env *e, char *str, int c, int flag)
{
	char		**tmp;

	tmp = ft_strsplit(str, ' ');
	if (flag == T_PLAN)
		e->meshes[c].prim.plan.normal = init_vec(ft_atod(tmp[1]), ft_atod(tmp[2]),
				ft_atod(tmp[3]));
	return (0);
}

int				m_rotate(t_env *e, char *str, int c, int flag)
{
	char		**tmp;

	(void)flag;
	tmp = ft_strsplit(str, ' ');
	e->meshes[c].rot_x = malloc_matrix(4, 4);
	e->meshes[c].rot_y = malloc_matrix(4, 4);
	e->meshes[c].rot_z = malloc_matrix(4, 4);
	inv_rot_matrix_x(&e->meshes[c].rot_x, ft_atod(tmp[1]));
	inv_rot_matrix_y(&e->meshes[c].rot_y, ft_atod(tmp[2]));
	inv_rot_matrix_z(&e->meshes[c].rot_z, ft_atod(tmp[3]));
	return (0);
}

int				m_coef(t_env *e, char *str, int c, int flag)
{
	char		**tmp;

	tmp = ft_strsplit(str, BREAK);
	if (flag == T_CONE)
		e->meshes[c].prim.cone.coeff = ft_atod(tmp[1]);
	return (0);
}

int				init_flag(t_env *e, int type, int c)
{
	e->meshes[c].type = type;
	return (type);
}

int				color_m(t_env *e, char *str, int c, int flag)
{
	char		**tmp;
	int			i;

	i = 0;
	(void)flag;
	tmp = ft_strsplit(str, BREAK);
	while (tmp[1][i])
		i++;
	if (i != 10)
	{
		tmp[1][0] = '0';
		tmp[1][1] = '\0';
		i = -1;
	}
	else
		i = 0;
	e->meshes[c].color = get_color(tmp[1]);
	return (i);
}

int				m_diffuse(t_env *e, char *str, int c, int flag)
{
	char		**tmp;

	(void)flag;
	tmp = ft_strsplit(str, BREAK);
	e->meshes[c].diff = ft_atod(tmp[1]);
	return (0);
}

int				m_radius(t_env *e, char *str, int c, int flag)
{
	char		**tmp;

	tmp = ft_strsplit(str, BREAK);
	if (flag == T_SPHERE)
		e->meshes[c].prim.sphere.radius = ft_atod(tmp[1]);
	if (flag == T_CYLINDER)
		e->meshes[c].prim.cylinder.radius = ft_atod(tmp[1]);
	return (0);
}

int				m_specular(t_env *e, char *str, int c, int flag)
{
	char		**tmp;

	(void)flag;
	tmp = ft_strsplit(str, BREAK);
	e->meshes[c].spec = ft_atod(tmp[1]);
	return (0);
}

int				m_reflection(t_env *e, char *str, int c, int flag)
{
	char		**tmp;

	(void)flag;
	tmp = ft_strsplit(str, BREAK);
	e->meshes[c].refl = ft_atod(tmp[1]);
	return (0);
}

int				m_refraction(t_env *e, char *str, int c, int flag)
{
	char		**tmp;

	(void)flag;
	tmp = ft_strsplit(str, BREAK);
	e->meshes[c].refr = ft_atod(tmp[1]);
	return (0);
}

int				m_scale(t_env *e, char *str, int c, int flag)
{
	char		**tmp;

	(void)flag;
	tmp = ft_strsplit(str, ' ');
	e->meshes[c].scale = malloc_matrix(4, 4);
	inv_scale_matrix(&e->meshes[c].scale, ft_atod(tmp[1]), ft_atod(tmp[2]), ft_atod(tmp[3]));
	return (0);
}

int				m_position(t_env *e, char *str, int c, int flag)
{
	static char	**tmp;
	static int	i = 0;

	(void)flag;
	if (i == 0)
	{
		tmp = ft_strsplit(str, ' ');
		e->meshes[c].trans = malloc_matrix(4, 4);
		i = 1;
	}
	else
	{
		inv_trans_matrix(&e->meshes[c].trans, ft_atod(tmp[1]), ft_atod(tmp[2]),
				ft_atod(tmp[3]));
		compute_matrix(&e->meshes[c]);
		i = 0;
	}
	return (0);
}
