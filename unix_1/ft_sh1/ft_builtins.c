/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmizzi <cmizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 16:59:54 by cmizzi            #+#    #+#             */
/*   Updated: 2014/01/04 19:24:28 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_builtins.h"
#include "ft_string.h"

int		ft_builtins(char *command, char **args, char ***envp)
{
	if (ft_strcmp(command, "cd"))
		ft_cd(args, envp);
	else if (ft_strcmp(command, "pwd"))
		ft_putendl(ft_getenv(envp, "PWD"));
	else if (ft_strcmp(command, "exit"))
		kill(0, SIGQUIT);
	else if (ft_strcmp(command, "getenv"))
		ft_putendl(ft_getenv(envp, args[1]));
	else if (ft_strcmp(command, "setenv"))
		ft_setenv(envp, args[1], args[2]);
	else if (ft_strcmp(command, "unsetenv"))
		ft_unsetenv(envp, args[1]);
	else
		return (0);
	return (1);
}
