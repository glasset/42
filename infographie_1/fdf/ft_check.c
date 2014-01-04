/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 19:28:35 by glasset           #+#    #+#             */
/*   Updated: 2013/12/13 21:10:09 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int			ft_div(int x)
{
	int		y;

	y = 2;
	if (x > 100000)
		y = 14;
	else if (x > 50000)
		y = 12;
	else if (x > 20000)
		y = 10;
	else if (x > 10000)
		y = 8;
	else if (x > 5000)
		y = 6;
	return (y);
}

int			ft_check(t_point **s)
{
	int		y;
	int		x;
	int		minx;
	int		maxx;

	y = 0;
	while (y < s[0][0].y)
	{
		x = 1;
		if (s[y][0].x)
		{
			while (x < s[y][0].x)
			{
				if (s[y][x].x < minx)
					minx = s[y][x].x;
				else if (s[y][x].x > maxx)
					maxx = s[y][x].x;
				x++;
			}
		}
		y++;
	}
	x = ft_abs(maxx) + ft_abs(minx);
	return (ft_div(x));
}
