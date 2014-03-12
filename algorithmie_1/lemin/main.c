/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 12:59:06 by glasset           #+#    #+#             */
/*   Updated: 2014/03/12 15:19:12 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
#include "lemin.h"

#include <stdio.h>

void			error()
{
	write(1, "ERROR\n", 6);
	exit(0);
}

int				main(void)
{
	t_env		e;
	size_t			i;
	size_t			s;
	i = 0;
	e.room = lst_new();
	parser(&e);
	printf("%d ants\n\n", e.ants);
	while(i < e.room->len)
	{
		printf("name: %s\npos: %d\nx:%d|y:%d\n", e.room->start->name,
				e.room->start->pos, e.room->start->xy[0], e.room->start->xy[1]);
		e.room->start = e.room->start->next;
		if (e.room->start->tube)
		{
			s = 0;
			while(s < e.room->start->tube->len)
			{
				printf("liaison: %s\n", e.room->start->tube->start->name);
				e.room->start->tube->start = e.room->start->tube->start->next;
				s++;
			}
		}
		i++;
		write(1, "\n", 1);
	}
	return (0);
}
