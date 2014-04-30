/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openptmx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 12:42:11 by glasset           #+#    #+#             */
/*   Updated: 2014/04/30 14:11:09 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include "script.h"

void		openty()
{
	char	*name;
//	int		tmp;

//	tmp = 0;
	e.fd_master = open("/dev/ptmx", O_RDWR);
	if (e.fd_master < 0)
		exit(0);
//	if (ioctl(e.fd_master, TIOCSPTLCK, &tmp))
//		exit(0);
	name = ptsname(e.fd_master);
	e.fd_slave = open(name, O_RDWR | O_NOCTTY);
}
