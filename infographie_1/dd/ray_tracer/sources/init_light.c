/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 14:16:46 by glasset           #+#    #+#             */
/*   Updated: 2014/03/25 14:49:30 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser.h"

int			light(t_env *e, int c_l, int fd, char *str)
{
	char		*line;
	static int	c = 0;
	int			li;
	l			*ft;
	int			tmp;

	ft = ft_inl();
	li = 1;
	if (c == e->nb_light_malloc || e->nb_light_malloc == -1)
	{
		error_p(str, "light ignored check number of light", c_l);
		while (get_next_line(fd, &line))
		{
			if (line[0] == END_OBJ)
				break ;
			li++;
		}
		return (li);
	}
	while (get_next_line(fd, &line))
	{
		if (line[0] == END_OBJ)
		{
			error_p(str, "\033[32m[OK]\033[0m Light add", c_l);
			e->nb_light++;
			c++;
			return (li);
		}
		if (checkline_light(line) == -1)
			error_p(ft_strsub(line, cut_space(line), ft_strlen(line)),
					"\033[31m[WARNING]\033[0m unknown line", li + c_l);
		else
			tmp = ft[checkline_light(line)](e, line, c);
		if (tmp == -1)
			error_p(ft_strsub(line, cut_space(line), ft_strlen(line)),
					"\033[31m[WARNING]\033[0m wrong value", c_l + li);
		if (tmp == -2)
		{
			error_p(ft_strsub(line, cut_space(line), ft_strlen(line)),
					"\033[31m[ERROR]\033[0m light ignored", c_l + li);
			free(line);
			return (li);
		}

		free(line);
		li++;
	}
	return (li);
}
