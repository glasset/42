/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegay <alegay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 15:15:21 by glasset           #+#    #+#             */
/*   Updated: 2013/12/31 18:01:26 by alegay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_get_PATH(char **env, char **path)
{
	int		i;

	i = 0;
	while (ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	path = ft_strsplit(env[i], ':');
	path[0] = ft_strchr(path[0], '/');
	i = 0;
	while (path[i])
	{
		path[i] = ft_strjoin(path[i], "/");
		i++;
	}
	return (path);
}

void	ft_exec(t_stru s, char **cmd1, char *arg, int a)
{
	int		i;

	i = 0;
	if (a == 0)
	{
		s.path = ft_get_PATH(s.env, s.path);
		if (cmd1 != NULL)
		{
			while ((s.path)[i])
				execve(ft_strjoin((s.path)[i++], cmd1[0]), cmd1, s.env);
			execve(arg, cmd1, s.env);
		}
	}
	if (a != 1)
	{
		ft_putstr_fd("zsh: command not found: ", 2);
		ft_putendl_fd(arg, 2);
	}
	_exit(0);
}

int		ft_get_cmd(char ***cmd, char ***cmd2, char **arg, int file)
{
	*cmd = NULL;
	*cmd2 = NULL;
	if (arg[2][0] != '\0' && arg[2][0] != ' ')
		*cmd = ft_strsplit(arg[2], ' ');
	if (arg[3][0] != '\0' && arg[3][0] != ' ')
		*cmd2 = ft_strsplit(arg[3], ' ');
	file = open(arg[4], O_CREAT | O_TRUNC | O_WRONLY, 0755);
	return (file);
}
