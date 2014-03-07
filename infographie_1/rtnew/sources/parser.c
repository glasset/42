/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 17:47:43 by glasset           #+#    #+#             */
/*   Updated: 2014/03/07 13:57:12 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my.h"
#include "gnl.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

f				*funct(void)
{
	f			*ft;
	ft = malloc(sizeof(ft) * 8);
	ft[0] = &comment;
	ft[1] = &init_mesh;
	ft[2] = &nbmesh;
	ft[3] = &nblight;
	ft[4] = &pov;
	ft[5] = &lookat;
	ft[6] = &ambient;
	ft[7] = &init_l;
	return (ft);
}

int				whoinit(char *str)
{
	int			i;

	i  = -1;
	if (str[1] == 'P')
		return (4);
	if (str[1] == 'L')
		return (5);
	if (str[1] == 'C')
		return (6);
	while (str[++i])
	{
		if (str[i] == 'l' && str[i + 1] == 'i')
			return (3);
		if (str[i] == 'o' && str[i + 1] == 'b')
			return (2);
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
		if ('L' == str[0])
			return (7);
		if (opt[i] == str[0])
			return (1);
	}
	return (0);
}

void			parse(t_env *e, char *path)
{
	char		*line;
	int			fd;
	int			current_m;
	f			*ft;
	int			i;
	int			x;

	x = 0;
	ft = funct();
	current_m = 1;
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		error_p(ft[i = check_line(line)](e, line), current_m, line);
		free(line);
		if (i == 4 || i == 5 || i == 6)
			x++;
		current_m++;
	}
	if (x != 3)
		write(1, "[\033[31mWARNING\033[00m]some variable uninitialized (check Pov, Look at, Color ambient)\n", 88);
}
