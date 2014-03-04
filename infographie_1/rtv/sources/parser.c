/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 17:47:43 by glasset           #+#    #+#             */
/*   Updated: 2014/03/04 12:20:52 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "my.h"
#include "ray_tracer.h"
#include "gnl.h"
#include <stdlib.h>
#include <fcntl.h>

f				*funct(void)
{
	f			*ft;
	ft = malloc(sizeof(ft) * 10);
	ft[0] = &comment;
//	ft[1] = &init_c;
	ft[2] = &init_s;
//	ft[3] = &init_p;
	ft[4] = &init_l;
	ft[5] = &nbmesch;
	ft[6] = &nblight;
	ft[7] = &pov;
	ft[8] = &lookat;
	ft[9] = &ambiant;
	return (ft);
}

int				whoinit(char *str)
{
	int			i;

	i  = -1;
	if (str[1] == 'P')
		return (7);
	if (str[1] == 'L')
		return (8);
	if (str[1] == 'C')
		return (9);
	while (str[++i])
	{
		if (str[i] == 'l' && str[i + 1] == 'i')
			return (6);
		if (str[i] == 'o' && str[i + 1] == 'b')
			return (5);
	}
	return (0);
}

int				check_line(char *str)
{
	char		*opt;
	int			i;

	i = -1;
	opt = "cSPLC";
	while (opt[++i])
	{
		if (str[0] == '|')
			return (whoinit(str));
		if (opt[i] == str[0])
			return (i + 1);
	}
	return (0);
}

void			parse(t_env *e, char *path)
{
	char		*line;
	int			fd;
	int			current_m;
	f			*ft;

	ft = funct();
	current_m = 1;
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		error_p(ft[check_line(line)](e, line, current_m), current_m);
		free(line);
		current_m++;
	}
}
