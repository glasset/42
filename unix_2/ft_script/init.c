/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/29 14:00:45 by glasset           #+#    #+#             */
/*   Updated: 2014/04/29 16:35:24 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include "script.h"

void		init_file(char *name)
{
	int		fd;
	time_t	t;

	e.name = name;
	time(&t);
	if ((fd = open(name, O_CREAT | O_WRONLY | O_TRUNC, 0777)))
	{
		e.fd = fd;
		ft_puts("Script started, output file is ", 1);
		ft_puts(name, 1);
		ft_puts("\n", 1);
		ft_puts("Script started on ", fd);
		ft_puts(ctime(&t), fd);
	}
	else
		ft_puts("Error: can't create/open this file\n", 1);
}

void		end_file(void)
{
	time_t	t;

	time(&t);
	ft_puts("\nScript done on ", e.fd);
	ft_puts(ctime(&t), e.fd);
	close(e.fd);
	ft_puts("Script done, output file is ", 1);
	ft_puts(e.name, 1);
	ft_puts("\n", 1);
}

