/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 12:59:06 by glasset           #+#    #+#             */
/*   Updated: 2014/02/18 15:33:00 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
#include "lemin.h"

void			error()
{
	write(1, "ERROR\n", 6);
	exit(0);
}

int				main(void)
{
	t_env		e;

	e.room = lst_new();
	parser(&e);
	return (0);
}
