/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 12:27:17 by fkalb             #+#    #+#             */
/*   Updated: 2014/03/27 13:08:04 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "sh42.h"

char		*ft_read_cmd_result(t_sh *sh, char *path, char **args)
{
	pid_t	new_cmd;
	int		pipe1[2];

	pipe(pipe1);
	new_cmd = fork();
	if (new_cmd == 0)
	{
		close(pipe1[0]);
		dup2(pipe1[1], 1);
		ft_exec_cmd(sh, new_cmd, path, args);
	}
	else if (new_cmd < 0)
	{
		ft_error2("failure during execution", args[0]);
		LAST_RET_VAL = EXIT_FAILURE;
	}
	else
	{
		wait(&new_cmd);
		LAST_RET_VAL = WEXITSTATUS(new_cmd);
		close(pipe1[1]);
		return (ft_read_fd(pipe1[0]));
	}
	return (NULL);
}
