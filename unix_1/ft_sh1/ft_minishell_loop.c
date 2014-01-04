/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_loop.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmizzi <cmizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 16:59:54 by cmizzi            #+#    #+#             */
/*   Updated: 2014/01/04 19:17:13 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include "ft_sh1.h"

void	ft_minishell_loop(char ***envp)
{
	pid_t	pid;
	char	buffer[BUFF_SIZE];
	int		bread;
	
	PRINT_PROMPT;
	while ((bread = read(0, buffer, BUFF_SIZE)) != 0)
	{
		buffer[bread - 1] = '\0';
		pid = fork();
		if (pid > 0)
		{
			wait(0);
			PRINT_PROMPT;
		}
		else
		{
			ft_exec(buffer, envp);
			PRINT_PROMPT;
		}
		buffer[0] = '\0';
	}
	kill(pid, SIGQUIT);
}
