/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_sh.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 12:12:01 by glasset           #+#    #+#             */
/*   Updated: 2014/01/14 21:28:37 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "minishell.h"

char			**get_path(char **path, char ***env)
{
	int		i;

	i = 0;
	while (ft_strncmp(*env[i], "PATH=", 5) != 0)
		i++;
	path = ft_strsplit(*env[i], ':');
	path[0] = ft_strchr(path[0], '/');
	i = 0;
	while (path[i])
	{
		path[i] = ft_strjoin(path[i], "/");
		i++;
	}
	return (path);
}

void			ft_exec(char *str, char ***env)
{
	char		**path;
	char		**arg;

	arg = ft_strsplit(str, ' ');
	path = get_path(path, env);
	while (*path)
	{
		if (builtins(arg, env))
			return ;
		execve(ft_strjoin(*path++, arg[0]), arg, *env);
	}
	notfound(arg[0]);
}

void			gl_sh(char ***env)
{
	pid_t		pid;
	char		buf[4097];
	int			ret;

	write(1, "$> ", 3);
	while ((ret = read(0, buf, 4097)) != 0)
	{
		buf[ret - 1] = '\0';
		pid = fork();
		if (pid > 0)
		{
			wait(0);
			write(1, "$> ", 3);
		}
		else
		{
			ft_exec(buf, env);
			write(1, "$> ", 3);
		}
		buf[0] = '\0';
	}
	kill(pid, SIGQUIT);
}
