/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 12:16:42 by glasset           #+#    #+#             */
/*   Updated: 2013/12/13 21:10:06 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <mlx.h>
#include <stdlib.h>
#include "fdf.h"

int		ft_abs(int c)
{
	if (c < 0)
		c = c * -1;
	return (c);
}

static void		ft_if(t_line **t, t_mlx **p)
{
	int			i;
	int			c;

	c = 53122189;
	i = 1;
	(*t)->cumul = (*t)->dx / 2;
	while (i <= (*t)->dx)
	{
		(*t)->x += (*t)->xinc;
		(*t)->cumul += (*t)->dy;
		if ((*t)->cumul >= (*t)->dx)
		{
			(*t)->cumul -= (*t)->dx;
			(*t)->y += (*t)->yinc;
		}
		mlx_pixel_put((*p)->mlx, (*p)->win, (*t)->x, (*t)->y, c);
		c = c + 1000;
		i++;
	}
}

static void		ft_else(t_line **t, t_mlx **p)
{
	int			i;
	int			c;

	c = 53122189;
	i = 1;
	(*t)->cumul = (*t)->dy / 2;
	while (i <= (*t)->dy)
	{
		(*t)->y += (*t)->yinc;
		(*t)->cumul += (*t)->dx;
		if ((*t)->cumul >= (*t)->dy)
		{
			(*t)->cumul -= (*t)->dy;
			(*t)->x += (*t)->xinc;
		}
		mlx_pixel_put((*p)->mlx, (*p)->win, (*t)->x, (*t)->y, c);
		i++;
		c = c + 1000;
	}
}

void			ft_display_line(t_mlx **p, t_point s, t_point x, int u)
{
	t_line		*t;

	t = malloc(sizeof(t_line));
	t->x = (750 + s.x / u);
	t->y = (100 + s.y / u);
	t->dx = (750 + x.x / u) - (750 + s.x / u);
	t->dy = (100 + x.y / u) - (100 + s.y / u);
	t->xinc = (t->dx > 0) ? 1 : -1;
	t->yinc = (t->dy > 0) ? 1 : -1;
	t->dx = ft_abs(t->dx);
	t->dy = ft_abs(t->dy);
	mlx_pixel_put((*p)->mlx, (*p)->win, t->x, t->y, 20520513);
	if (t->dx > t->dy)
		ft_if(&t, &(*p));
	else
		ft_else(&t, &(*p));
	ft_memdel((void **)&t);
}

void		ft_display_all(t_point **s, t_mlx **t, int u)
{
	int		y;
	int		x;
	int		ymax;

	ymax = s[0][0].y;
	y = 0;
	while (y < ymax)
	{
		x = 1;
		while (x < s[y][0].x)
		{
			if ((x + 1) < s[y][0].x)
				ft_display_line(&(*t), s[y][x], s[y][x + 1], u);
			if ((y + 1) < s[0][0].y && x < s[y + 1][0].x)
				ft_display_line(&(*t), s[y][x], s[y + 1][x], u);
			x++;
		}
		y++;
	}
}

