/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 09:57:00 by fkalb             #+#    #+#             */
/*   Updated: 2014/03/27 10:59:46 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define PATH_FILE "/etc/paths"

static void	ft_def_set_path(t_sh *sh)
{
	int		i;
	int		fd;
	char	*str;
	char	*tmp;
	char	**tab;

	i = 0;
	fd = open(PATH_FILE, O_RDONLY);
	tmp = ft_read_fd(fd);
	close(fd);
	tab = ft_strsplit(tmp, '\n');
	ft_strdel(&tmp);
	str = NULL;
	if (tab && tab[i])
	{
		str = ft_strdup(tab[i]);
		while (tab[++i])
			str = ft_strfjoin_key(str, tab[i], ":");
	}
	ft_strtabdel(&tab);
	ft_setenv(sh, &DEF_ENV, "PATH", str);
	ft_strdel(&str);
}

int			ft_defaultenv(t_sh *sh)
{
	char	*str;
	char	**tab;

	if (!(DEF_ENV = (char **)malloc(sizeof(char *))))
		return (ft_defaultenv(sh));
	sh->warn_bypass = TRUE;
	DEF_ENV[0] = NULL;
	ft_def_set_path(sh);
	ft_setenv(sh, &DEF_ENV, "HOME", "./");
	tab = ft_strsplit("/bin/sh -c whoami", ' ');
	str = ft_read_cmd_result(sh, tab[0], tab);
	ft_setenv(sh, &DEF_ENV, "USER", str);
	ft_strdel(&str);
	ft_strtabdel(&tab);
	str = getcwd(NULL, 0);
	ft_setenv(sh, &DEF_ENV, "PWD", str);
	ft_setenv(sh, &DEF_ENV, "OLDPWD", str);
	ft_strdel(&str);
	sh->warn_bypass = FALSE;
	return (0);
}

int			ft_newenv(t_sh *sh, char **env)
{
	int		i;
	char	**tab;

	i = -1;
	if (!(ENV = (char **)malloc(sizeof(char *))))
		return (ft_newenv(sh, env));
	ENV[0] = NULL;
	while (env[++i])
	{
		tab = ft_strsplit(env[i], '=');
		ft_setenv(sh, &ENV, tab[0], tab[1]);
		ft_strtabdel(&tab);
	}
	return (0);
}
