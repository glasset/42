/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 04:40:31 by fkalb             #+#    #+#             */
/*   Updated: 2014/03/27 13:08:07 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sh42.h"
#include <unistd.h>

int			ft_check_located_cmd(t_sh *sh, char **args)
{
	if (!ft_strnequ(args[0], "./", 2) && !ft_strnequ(args[0], "../", 3))
	{
		if (!ft_strnequ(args[0], "/", 1))
			return (ft_check_unlocated_cmd(sh, args));
	}
	if (access(args[0], F_OK) == -1)
		return (ft_error2("command not found", args[0]));
	if (access(args[0], X_OK) == -1)
		return (ft_error2("permission denied", args[0]));
	ft_fork_and_exec(sh, args[0], args);
	return (0);
}

int			ft_check_unlocated_cmd(t_sh *sh, char **args)
{
	int		i;
	char	*path;
	char	**pathlst;

	i = -1;
	path = ft_search_inallenv(sh, "PATH");
	pathlst = ft_strsplit(path, ':');
	while (path && pathlst[++i])
	{
		ft_strdel(&path);
		path = ft_strjoin_key(pathlst[i], args[0], "/");
		if (access(path, F_OK) != -1)
			break ;
	}
	if (!path || !pathlst[i])
		LAST_RET_VAL = ft_error2("command not found", args[0]);
	else if (access(path, X_OK) == -1)
		LAST_RET_VAL = ft_error2("permission denied", args[0]);
	else
		ft_fork_and_exec(sh, path, args);
	ft_strdel(&path);
	ft_strtabdel(&pathlst);
	return (LAST_RET_VAL);
}

void		ft_fork_and_exec(t_sh *sh, char *path, char **args)
{
	pid_t	new_cmd;

	new_cmd = fork();
	ft_exec_cmd(sh, new_cmd, path, args);
}

void		ft_exec_cmd(t_sh *sh, pid_t pid, char *path, char **args)
{
	if (pid == 0)
	{
		if (execve(path, args, ENV) == -1)
		{
			ft_error2("exec format error", args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		ft_error2("failure during execution", args[0]);
		LAST_RET_VAL = EXIT_FAILURE;
	}
	else
	{
		wait(&pid);
		LAST_RET_VAL = WEXITSTATUS(pid);
	}
}
