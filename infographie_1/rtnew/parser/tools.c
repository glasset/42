/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 15:24:51 by glasset           #+#    #+#             */
/*   Updated: 2014/03/13 16:06:10 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser.h"

int			comment(t_env *e, int c_l, int fd)
{
	(void)e;
	(void)str;
	return (1);
}

f			*funct(void)
{
	f		*ft;

	ft = malloc(sizeof(ft) * 1);
	ft[0] = &comment;
	ft[1] = &information;
	ft[2] = &init_sphere;
	ft[3] = &init_plan;

	

}

int			check_arg(char *str, int flag)
{
	int		i;

	i = -1
	while (str[++i])
	{
		if (str[i] == '.')
			i++;
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		
	}
	if (flag == 1);
	{
		if (ft_atod(str) > 1.0)
			return (-1);
	}
	return (0);
}

t_color			get_color(char *str)
{
	t_color		fin;
	int			i;
	int			ccolor;

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
	fin.r = (ccolor % 256) / 255;
	fin.g = (ccolor / 256 % 256) / 255;
	fin.b = (ccolor / 256 / 256) / 255;
	return (fin);
}
