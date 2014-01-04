/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmizzi <cmizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 16:59:54 by cmizzi            #+#    #+#             */
/*   Updated: 2013/12/21 16:35:32 by cmizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "ft_string.h"
#include "ft_sh1.h"
#include "ft_builtins.h"

void	ft_exec(const char *string, char ***envp)
{
	char	**args;
	char	**split;
	char	*command;
	
	args = ft_str_split(string, ' ');
	command = args[0];

	split = ft_str_split(ft_getenv(envp, "PATH"), ':');
	while (*split != 0)
	{
		args[0] = ft_strcat(*split++, command, '/');
		if (ft_builtins(command, args, envp))
			return ;		
		execve(args[0], args, *envp);
	}
	ft_putstr(command);
	ft_putendl(": command not found");
	exit(EXIT_FAILURE);
}
