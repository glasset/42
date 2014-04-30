/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_script.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/29 13:33:56 by glasset           #+#    #+#             */
/*   Updated: 2014/04/30 14:21:23 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "script.h"
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/ioctl.h>


void					sigint(int sig)
{
	if (sig == sig)
	end_file();
	exit(0);
}

void					get_term()
{
	e.path = "/bin/zsh";
	tcgetattr(0, &e.term);
	ioctl(0, TIOCGWINSZ, &e.win);
	e.term.c_lflag |= ECHO;
}

int						main(int argc, char **argv)
{
	if (argc > 1)
		init_file(argv[1]);
	else
		init_file("typescript");
	get_term();
	openty();
	e.pid = fork();
	signal(SIGINT, &sigint);
	gterm();
	return (0);
}
