/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 15:34:21 by glasset           #+#    #+#             */
/*   Updated: 2014/03/22 13:04:05 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "lemin.h"

static int			check(char **tmp, char *str, int curr)
{
	int				i;

	i = -1;
	if (curr == 0)
		return (0);
	while (++i < curr)
	{
		if (!ft_strcmp(tmp[i], str))
			return (1);
	}
	return (0);
}

static void			pr(char *s1, char *s2)
{
	ft_putstr(s1);
	write(1, "-", 1);
	ft_putendl(s2);
}

static void			print_l(t_env *e)
{
	size_t		i;
	size_t		s;
	char		**tmp;
	int			x;

	tmp = (char **)malloc(sizeof(char *) * e->room->len);
	i = -1;
	while (++i < e->room->len)
	{
		if (e->room->start->tube)
		{
			s = -1;
			while (++s < e->room->start->tube->len)
			{
				if (check(tmp, e->room->start->tube->start->name, i) == 0)
					pr(e->room->start->name, e->room->start->tube->start->name);
				e->room->start->tube->start = e->room->start->tube->start->next;
			}
		}
		tmp[i] = (char *)malloc(sizeof(char) * ft_strlen(e->room->start->name));
		x = -1;
		while (e->room->start->name[++x])
			tmp[i][x] = e->room->start->name[x];
		e->room->start = e->room->start->next;
	}
}

void				print(t_env *e)
{
	size_t			i;

	i = -1;
	ft_putnbr(e->ants);
	write(1, "\n", 1);
	while (++i < e->room->len)
	{
		if (e->room->start->pos == 1)
			write(1, "##start\n", 8);
		if (e->room->start->pos == 2)
			write(1, "##end\n", 6);
		ft_putstr(e->room->start->name);
		write(1, " ", 1);
		ft_putnbr(e->room->start->xy[0]);
		write(1, " ", 1);
		ft_putnbr(e->room->start->xy[1]);
		write(1, "\n", 1);
		e->room->start = e->room->start->next;
	}
	print_l(e);
	write(1, "\n", 1);
}
