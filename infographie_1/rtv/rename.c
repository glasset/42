/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rename.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 19:38:49 by glasset           #+#    #+#             */
/*   Updated: 2014/03/01 19:55:20 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			init_s(t_env *e, char *str, int m)
{
	char	**tmp;

	tmp = ft_strsplit(str, '[');
	if (e->nb_mesh <= 0);
		exit(0);
	if (tmp[7] != '\0')
		exit(0);// wrong format spheres line ??
	e->meshes[m].type = T_SPHERE;
	e->meshes[m].prim.sphere.radius = ft_atoi(tmp[4]) ;
	e->meshes[m].prim.sphere.pos = init_vec(ft_atoi(tmp[1]), ft_atoi(tmp[2]),
		ft_atoi(tmp[3]);
	e->meshes[m].color.r = 0.0;//tmp[5]
	e->meshes[m].color.g = 0.2;
	e->meshes[m].color.b = 0.7;
	e->meshes[m].diff = ft_atoi(tmp[6];
	return (current_m + 1);
}
