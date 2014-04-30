/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gterm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 13:48:05 by glasset           #+#    #+#             */
/*   Updated: 2014/04/30 14:22:16 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include <sys/select.h>
#include "script.h"

void		readg()
{
	fd_set	readf;

	while (1)
	{
		FD_ZERO(&readf);
		FD_SET(0, &readf);
		FD_SET(e.fd_master, &readf);
		if ((select(e.fd_master + 1, &readf, NULL, NULL, NULL)) >= 0)
			write(e.fd, "|",1);
	}
	exit (0);
}

void		gterm()
{
	if (e.pid == 0)
	{
		execve(e.path, NULL, NULL);
		exit(0);
	}
	else
	{
		readg();
	}
}
