/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 16:15:29 by glasset           #+#    #+#             */
/*   Updated: 2014/02/01 16:44:56 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "user.h"
#include <unistd.h>

void			get_bin(int c)
{
	int			a;
	char		d;

	a = c % 2;
	c = c / 2;
	if (c > 0)
		get_bin(c);
	d = a + '0';
	write(1, &d, 1);
}

void			data(int pid, char *msg)
{
	
	pid = 0;
	while(msg[pid])
		get_bin((int)msg[pid++]);
}
