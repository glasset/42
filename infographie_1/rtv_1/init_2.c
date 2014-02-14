/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 12:16:39 by glasset           #+#    #+#             */
/*   Updated: 2014/02/14 12:42:59 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "rtv.h"

void			init_plans(t_ray *ray, int fd)
{
	int			i;
	int			cp;
	char		**tmp;
	char		*line;

	i = ray->size_obj_s;
	cp = -1;
	if (get_next_line(fd, &line))
	{
		ray->size_obj_p = ft_atoi(line);
		free(line);
		while (++cp < ray->size_obj_p)
		{
			get_next_line(fd, &line);
			tmp = ft_strsplit(line, '|');
			ray->obj[i].point.x = ft_atoi(tmp[0]) + 0.0;
			ray->obj[i].point.y = ft_atoi(tmp[1]) + 0.0;
			ray->obj[i].point.z = ft_atoi(tmp[2]) + 0.0;
			ray->obj[i].norme.x = ft_atoi(tmp[3]) + 0.0;
			ray->obj[i].norme.y = ft_atoi(tmp[4]) + 0.0;
			ray->obj[i].norme.z = ft_atoi(tmp[5]) + 0.0;
			color(tmp[6], &ray->obj[i++].color);
			free(line);
		}
	}
}

