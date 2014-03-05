/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 12:59:00 by glasset           #+#    #+#             */
/*   Updated: 2014/02/18 16:26:58 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "lemin.h"
#include <stdio.h>
#include <unistd.h>

int				check_nbr(char *line) /* A REFAIRE */
{
	int			i;

	i = 0;
	while (line[i] != '\0')
	{
		if (/*line[i] < 48 && line[i] > 57 && */line[i] == ' ' || line[i] == '-')
			return (-1);
		i++;
	}
	return (1);
}

int				check_line(char *line)
{
	if (line[0] == '\n')
		return (-3);
	if (!ft_strcmp(line, "##start"))
		return (START);
	if (!ft_strcmp(line, "##end"))
		return (END);
	if (line[0] == '#')
		return (COMMENT);
	if (check_nbr(line) == 1)
		return (NBR_ANTS);
	while (*line)
	{
		if (*line++ == '-')
			return (TUBE);
	}
	return (ROOM);
}

void			make(char **cord, int status, t_env *e)
{
	int			*xy;
	if (!cord)
		error();
	if (status == 0)
	{
		/* remplir liaisons */
	}
	else
	{
		xy[0] = ft_atoi(cord[1]);
		xy[1] = ft_atoi(cord[2]);
	}
	e->room = lst_add_end(e->room, cord[0], xy, status);
}

int				check_ants(char *line, t_env *e)
{
	if (e->ants == -1)
		e->ants = ft_atoi(line);
	else
		return (-1);
	return (0);
}

char			char_split(int status)
{
	if (status == END || status == START || status == ROOM)
		return (' ');
	else
		return ('-');
}

void			parser(t_env *e)
{
	char		*line;
	int			status;
	char		**tmp;

	e->ants = -1;
	while (get_next_line(0, &line))
	{
		status = check_line(line);
		if (status >= 0)
		{
			if (status == START || status == END)
			{
				ft_putendl(line);
				get_next_line(0, &line);
			}
			tmp = ft_strsplit(line, char_split(status));
			make(tmp, status, e);
		}
		else if (status == NBR_ANTS)
		{
			if (check_ants(line, e) == -1)
				status = -3;
		}
		ft_putendl(line);
		free(line);
		if (status == -3)
			break ;
	}
}
