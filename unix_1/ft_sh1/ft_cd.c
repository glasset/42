/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmizzi <cmizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 16:59:54 by cmizzi            #+#    #+#             */
/*   Updated: 2014/01/04 19:18:38 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include "ft_builtins.h"
#include "ft_string.h"

static char	*ft_pwd_back(char *pwd)
{
	int		i;

	i = ft_strlen(pwd) - 1;
	while (i > 0 && pwd[i] != '/')
		i--;
	pwd[i] = '\0';
	return (pwd);
}

static void	ft_error_cd(const char *folder)
{
	ft_putstr("cd: ");
	ft_putstr(folder);
	ft_putendl(": No such file or directory");
	exit(0);
}

static void ft_chdir_setenv(char ***envp, const char *pwd)
{
	chdir(pwd);
	ft_setenv(envp, "PWD", pwd);
}

void	ft_cd(char **args, char ***envp)
{
	char	*pwd;
//	char	**env;
	char	**path;
	int		i;

//	env = *envp;
	pwd = ft_getenv(envp, "PWD");
	if (args[1] == NULL)
	{
		ft_chdir_setenv(envp, "/");
		exit(0);
	}		
	path = ft_str_split(args[1], '/');
	i = 0;
	while (path[i++] != 0)
	{
		if (ft_strcmp(path[i - 1], ".."))
			pwd = ft_pwd_back(pwd);
		else
		{
			pwd = ft_strjoin(pwd, path[i - 1], '/');
			if (opendir(pwd) == NULL)
				ft_error_cd(args[1]);
		}
	}
	ft_chdir_setenv(envp, pwd);
}
