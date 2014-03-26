/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 14:16:46 by glasset           #+#    #+#             */
/*   Updated: 2014/03/26 13:39:20 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser.h"

static int	light_ign(int c_l, int fd, char *str)
{
	char	*line;
	int		li;

	li = 1;
	error_p(str, "light ignored check number of light", c_l);
	while (get_next_line(fd, &line))
	{
		if (line[0] == END_OBJ)
			break ;
		li++;
	}
	return (li);
}

static int	print_mess(char *line, int c_l, int li, int tmp)
{
	if (tmp == -1)
		error_p(ft_strsub(line, cut_space(line), ft_strlen(line)),
				"\033[31m[WARNING]\033[0m wrong value", c_l + li);
	if (tmp == -2)
	{
		error_p(ft_strsub(line, cut_space(line), ft_strlen(line)),
				"\033[31m[ERROR]\033[0m light ignored", c_l + li);
		free(line);
		return (-1);
	}
	return (0);
}

static int	ret_light(char *str, int c_l, int li, t_env *e)
{
	error_p(str, "\033[32m[OK]\033[0m Light add", c_l);
	e->nb_light++;
	return (li);
}

int			light(t_env *e, int c_l, int fd, char *str)
{
	char		*line;
	l			*ft;
	int			li;
	int			tmp;

	ft = ft_inl();
	li = 1;
	if (e->nb_light == e->nb_light_malloc || e->nb_light_malloc == -1)
		return (light_ign(c_l, fd, str));
	while (get_next_line(fd, &line))
	{
		if (line[0] == END_OBJ)
			return (ret_light(str, c_l, li, e));
		if (checkline_light(line) == -1)
			error_p(ft_strsub(line, cut_space(line), ft_strlen(line)),
				"\033[31m[WARNING]\033[0m unknown line", li + c_l);
		else
			tmp = ft[checkline_light(line)](e, line, e->nb_light);
		if (print_mess(line, c_l, li, tmp) == -1)
			return (li);
		free(line);
		li++;
	}
	return (li);
}
