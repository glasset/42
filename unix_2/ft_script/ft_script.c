/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_script.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/29 13:33:56 by glasset           #+#    #+#             */
/*   Updated: 2014/04/30 11:05:59 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "script.h"
#include <signal.h>
#include <stdlib.h>

void	sigint(int sig)
{
	if (sig == sig)
	end_file();
	exit(0);
}

int		main(int argc, char **argv)
{
	if (argc > 1)
		init_file(argv[1]);
	else
		init_file("typescript");
	signal(SIGINT, &sigint);
	while(1)
	{
	}
	return (0);
}
