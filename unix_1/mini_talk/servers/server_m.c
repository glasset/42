/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_m.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 15:22:36 by glasset           #+#    #+#             */
/*   Updated: 2014/02/02 19:06:42 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <signal.h>
#include "server.h"

void		one(int c)
{
	c = c;
	env->onechar[env->oct] = 1;
	env->oct++;
	if (env->oct == 8)
		convert();
}

void		zero(int c)
{
	c = c;
	env->onechar[env->oct] = 0;
	env->oct++;
	if (env->oct == 8)
		convert();
}

int			main(void)
{
	pid_t	pid;

	env = malloc(sizeof(t_data));
	env->oct = 0;
	pid = getpid();
	ft_printf("Pid server: %d.\n", pid);
	signal(SIGUSR2, &one);
	signal(SIGUSR1, &zero);
	while (42)
	{
	}
	return (0);
}
