/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 10:38:29 by glasset           #+#    #+#             */
/*   Updated: 2014/02/14 19:11:18 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
#include "rtv.h"
#include <stdio.h>

void		print_px(t_ray *ray, void *img, t_vec *index)
{
	t_vec	spheres;
	t_vec	plans;
	double	a;
	double	intensity;

	spheres = sphere(ray, &ray->dir, &ray->ori);
	plans = plan(ray, &ray->dir, &ray->ori);
	if (plans.x > -1.0  && spheres.z != -1.0 && plans.x < spheres.x)
		a = plans.x;
	else
		a = spheres.x + 1.0;
	if (spheres.z == -1.0 && plans.x == -1.0)
		put_px_to_img(img, index->x, index->y, 200, 0, 0);
	else if (spheres.x <= a && spheres.z != -1.0 )
	{
		intensity = find_light(ray, spheres.x, spheres.z, 1);
		put_px_to_img(img, index->x, index->y,
				(int)ray->obj[(int)spheres.z].color.x * intensity,
				(int)ray->obj[(int)spheres.z].color.y * intensity,
				(int)ray->obj[(int)spheres.z].color.z * intensity);
	}
	else
	{
		intensity = find_light(ray, plans.x, plans.y, 0);
		put_px_to_img(img, index->x, index->y,
				(int)ray->obj[(int)plans.y].color.x * intensity,
				(int)ray->obj[(int)plans.y].color.y * intensity,
				(int)ray->obj[(int)plans.y].color.z * intensity);
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

