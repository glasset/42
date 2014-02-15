/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 10:38:29 by glasset           #+#    #+#             */
/*   Updated: 2014/02/15 18:24:18 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
#include "rtv.h"
#include <stdio.h>

t_vec		check_color(t_vec *color, double intensity)
{
	t_vec	final;

	final.x= color->x * intensity;
	final.y = color->y * intensity;
	final.z = color->z * intensity;
	if (final.x > 255)
		final.x = 255;
	if (final.y > 255)
		final.y = 255;
	if (final.z > 255)
		final.z = 255;
	return (final);
}

void		print_px(t_ray *ray, t_mlx *t, t_vec *index)
{
	t_vec	spheres;
	t_vec	plans;
//	t_vec	cylindres;
	t_vec	f_col;
	double	a;

//	cylindres = cylindre(ray, &ray->dir, &ray->ori, -2);
	spheres = sphere(ray, &ray->dir, &ray->ori, -2);
	plans = plan(ray, &ray->dir, &ray->ori, -2);
	if (plans.x != -1.0  && spheres.x != -1.0)
	{
		if (plans.x < spheres.x)
			a = plans.x;
		else
			a = spheres.x + 1.0;
	}
	if (spheres.z == -1.0 && plans.x == -1.0)
		put_px_to_img(t->img, index->x, index->y, 0, 0, 0);
	else if (spheres.x < a && spheres.x != -1.0 )
	{
		f_col = check_color(&ray->obj[(int)spheres.z].color,
				find_light(ray, spheres.x, spheres.z, 1));
		put_px_to_img(t->img, index->x, index->y, f_col.x, f_col.y, f_col.z);
	}
	else
	{
		f_col = check_color(&ray->obj[(int)plans.y].color,
				find_light(ray, plans.x, plans.y, 0));
		put_px_to_img(t->img, index->x, index->y, f_col.x, f_col.y, f_col.z);
	}
}

void		color(char *str, t_vec *color)
{
	int		i;
	int		ccolor;

	ccolor = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			ccolor =  ccolor * 16 + (str[i] - '0');
		else if (str[i] >= 'a' && str[i] <= 'f')
			ccolor = ccolor * 16 + (str[i] - 'a' + 10);
		i++;
	}
	color->z = ccolor % 256;
	color->y = ccolor / 256 % 256;
	color->x = ccolor / 256 / 256;
}

void		init_obj(t_ray *ray, char *str)
{
	int		fd;
	int		i;
	char	*line;
	char	**tmp;

	i = 0;
	ray->obj = (t_obj *)malloc(sizeof(t_obj));
	fd = open(str, O_RDONLY);
	if (fd == -1)
		exit(0);
	get_next_line(fd, &line);
	ray->size_obj_s = ft_atoi(line);
	free(line);
	while (i < ray->size_obj_s)
	{
		get_next_line(fd, &line);
		tmp = ft_strsplit(line, '|');
		ray->obj[i].point.x = ft_atoi(tmp[0]) + 0.0;
		ray->obj[i].point.y = ft_atoi(tmp[1]) + 0.0;
		ray->obj[i].point.z = ft_atoi(tmp[2]) + 0.0;
		ray->obj[i].o_r = ft_atoi(tmp[3]) + 0.0;
		color(tmp[4], &ray->obj[i++].color);
		free(line);
	}
	init_plans(ray, fd);
	close(fd);
}

