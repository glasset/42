/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 16:15:29 by glasset           #+#    #+#             */
/*   Updated: 2014/02/02 17:24:16 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "user.h"
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void			send(int a, int pid)
{
	usleep(500);
	if (a == 1)
		kill(pid, SIGUSR2);
	if  (a == 0)
		kill(pid, SIGUSR1);
}

void			get_bin(int c, int pid)
{
	int			a;
	char		d;

	a = c % 2;
	c = c / 2;
	if (c > 0)
		get_bin(c, pid);
	printf("%d", a);
	send(a, pid);
}

void			data(int pid, char *msg)
{
	int			i;

	i = 0;
	while(msg[i])
		get_bin((int)msg[i++], pid);
}


