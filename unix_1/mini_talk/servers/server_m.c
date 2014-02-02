/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_m.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 15:22:36 by glasset           #+#    #+#             */
/*   Updated: 2014/02/02 17:18:39 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
//#include "server.h"
#include <signal.h>
#include <stdio.h>

void		un(int c)
{
	write(1, "1", 1);
	c = c;
}

void		zero(int c)
{
	write(1, "0", 1);
	c = c;
}

int			main(void)
{
	pid_t	pid;

	pid = getpid();
	printf("Pid server: %d.\n", pid);
	signal(SIGUSR2, &un);
	signal(SIGUSR1, &zero);
	while (42)
	{
	}
	return (0);
}
