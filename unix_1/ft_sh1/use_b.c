/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 16:25:06 by glasset           #+#    #+#             */
/*   Updated: 2014/01/15 16:02:10 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"

char				*g_getenv(char *get, char ***env)
{
	int				i;
	char			**str;
	char			**envp;

	envp = *env;
	i = 0;
	while ((str = ft_strsplit(envp[i++], '=')) != NULL)
	{
		if (!ft_strcmp(str[0], get))
			return (str[1]);
	}
	return (0);
}

char				**g_setenv(char *replace, char *value, char ***env)
{
	char			**envp;
	char			**str;
	int				i;

	envp = *env;
	i = 0;
	value = ft_strjoin("=", value);
	while (envp[i] && (str = ft_strsplit(envp[i], '=')) != 0)
	{
		if (!ft_strcmp(str[0], replace))
		{
			envp[i] = ft_strjoin(replace, value);
			return (envp);
		}
		i++;
	}
	envp[i] = (char *)malloc(sizeof(char *));
	envp[i] = ft_strcat(replace, value);
	envp[i + 1] = 0;
	return (envp);
}

void				g_unsetenv(char *free, char ***env)
{
	char			**envp;
	char			**str;
	int				i;

	envp = *env;
	i = 0;
	while (envp[i] && (str = ft_strsplit(envp[i], '=')) != 0)
	{
		if (!ft_strcmp(str[0], free))
			envp[i] = "";
		i++;
	}
}
