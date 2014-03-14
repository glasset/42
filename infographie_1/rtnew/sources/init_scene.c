/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 15:42:52 by jbalestr          #+#    #+#             */
/*   Updated: 2014/03/14 15:46:03 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "ray_tracer.h"
#include "parser.h"

void			init_scene(t_env *e, char *path)
{
	e->nb_mesh = -1;
	e->nb_light = -1;
	parse(e, path);
}
