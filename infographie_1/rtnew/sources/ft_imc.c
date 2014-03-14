/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset </var/mail/glasset>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 12:37:07 by glasset           #+#    #+#             */
/*   Updated: 2014/03/14 16:31:10 by glasset          ###   ########.fr       */
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

int				m_direction(t_env *e, char *str, int c, int flag)
{
	(void)e;
	(void)str;
	(void)c;
	(void)flag;
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

	(void)flag;
	tmp = ft_strsplit(str, BREAK);
	e->meshes[c].color = get_color(tmp[1]);
	return (0);
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

int				m_position(t_env *e, char *str, int c, int flag)
{
	char		**tmp;

	(void)flag;
	tmp = ft_strsplit(str, ' ');
	e->meshes[c].trans = malloc_matrix(4, 4);
	e->meshes[c].scale = malloc_matrix(4, 4);
	e->meshes[c].rot_x = malloc_matrix(4, 4);
	e->meshes[c].rot_y = malloc_matrix(4, 4);
	e->meshes[c].rot_z = malloc_matrix(4, 4);
	inv_scale_matrix(&e->meshes[c].scale, 1.0, 1.0, 1.0);
	inv_rot_matrix_x(&e->meshes[c].rot_x, 0.0);
	inv_rot_matrix_y(&e->meshes[c].rot_y, 0.0);
	inv_rot_matrix_z(&e->meshes[c].rot_z, 0.0);
	inv_trans_matrix(&e->meshes[c].trans, ft_atod(tmp[1]), ft_atod(tmp[2]),
			ft_atod(tmp[3]));
	compute_matrix(&e->meshes[c]);
	return (0);
}
