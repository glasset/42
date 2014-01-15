/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 21:12:55 by glasset           #+#    #+#             */
/*   Updated: 2014/01/15 16:03:18 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include "minishell.h"
/*
static char		*cdnull(char ***envp)
{
	char		*tmp;
	char		**str;
	int			i;

	i = 0;
	tmp = g_getenv("_", envp);
	str = ft_strsplit(tmp, '.');
	while (str[0][i])
		i++;
	str[0][i - 1] = '\0';
	return (str[0]);
}*/

static char		*ft_pwd_back(char *pwd)
{
	int			i;

	i = ft_strlen(pwd) - 1;
	while (i > 0 && pwd[i] != '/')
		i--;
	pwd[i] = '\0';
	return (pwd);
}

static void		ft_chdir_setenv(char ***envp, char *pwd)
{
	chdir(pwd);
	g_setenv("PWD", pwd, envp);
}

void			cd(char **args, char ***envp)
{
	char		*pwd;
	char		**path;
	int			i;

	pwd = g_getenv("PWD", envp);
	if (args[1] == NULL)
	{
		ft_chdir_setenv(envp, "/");
		exit(0);
	}
	path = ft_strsplit(args[1], '/');
	i = -1;
	while (path[++i] != NULL)
	{
		if (!ft_strcmp(path[i], ".."))
			pwd = ft_pwd_back(pwd);
		else
		{
			pwd = ft_strjoin(pwd, "/");
			pwd = ft_strjoin(pwd, path[i]);
			if (opendir(pwd) == NULL)
				notdir(args[1]);
		}
	}
	ft_chdir_setenv(envp, pwd);
}
