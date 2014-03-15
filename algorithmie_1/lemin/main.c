/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 12:59:06 by glasset           #+#    #+#             */
/*   Updated: 2014/03/15 15:13:53 by glasset          ###   ########.fr       */
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

void			print_res(t_env *e)
{

	seek_room(e, 1, "s");
	while (e->room->start->pos != END)
	{
		ft_putstr(e->room->start->name);
		write(1, "->", 2);
		seek_room(e, 0, e->room->start->back);
	}
	ft_putstr(e->room->start->name);
	write(1, "\n", 1);
}

int				main(void)
{
	t_env		e;

	e.room = lst_new();
	parser(&e);
	print(&e);
	shoort(&e);
	print_res(&e);
	return (0);
}
