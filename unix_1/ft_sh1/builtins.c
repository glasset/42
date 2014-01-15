/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 15:57:33 by glasset           #+#    #+#             */
/*   Updated: 2014/01/15 14:14:24 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <signal.h>
#include "minishell.h"

int				builtins(char **arg, char ***env)
{
	if (!ft_strcmp(arg[0], "cd"))
		cd(arg, env);
	else if (!ft_strcmp(arg[0], "pwd"))
		ft_putendl(g_getenv("PWD", env));
	else if (!ft_strcmp(arg[0], "exit"))
		kill(0, SIGQUIT);
	else if (!ft_strcmp(arg[0], "getenv"))
		ft_putendl(g_getenv(arg[1], env));
	else if (!ft_strcmp(arg[0], "setenv"))
		g_setenv(arg[1], arg[2], env);
	else if (!ft_strcmp(arg[0], "unsetenv"))
		g_unsetenv(arg[1], env);
	else
		return (0);
	return (1);
}
