/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 18:52:51 by fkalb             #+#    #+#             */
/*   Updated: 2014/03/26 11:45:41 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "sh42.h"

static char		*ft_cd_conc_path(char ***tab)
{
	int			i;
	char		*ret;

	i = -1;
	ret = ft_strnew(0);
	while (*tab && (*tab)[++i])
	{
		if (!ft_strequ((*tab)[i], "\\\\"))
			ret = ft_strfjoin_key(ret, (*tab)[i], "/");
	}
	ret = ft_strjoin_free(ret, "/");
	ft_strtabdel(tab);
	return (ret);
}

static char		*ft_cd_check_path(char *cmd)
{
	int			i;
	int			j;
	char		**tab;

	i = -1;
	tab = ft_strsplit_esc(cmd, '/');
	while (tab && tab[++i])
	{
		if (ft_strequ(tab[i], ".") || ft_strequ(tab[i], ".."))
		{
			if (i > 0 && ft_strequ(tab[i], ".."))
			{
				j = 1;
				while ((i - j) > -1 && ft_strequ(tab[i - j], "\\\\"))
					j++;
				ft_strdel(&tab[i - j]);
				tab[i - j] = ft_strdup("\\\\");
			}
			ft_strdel(&tab[i]);
			tab[i] = ft_strdup("\\\\");
		}
	}
	return (ft_cd_conc_path(&tab));
}

int				ft_cd(t_sh *sh, char **cmd)
{
	char		ret;
	char		*pwd;
	char		*path;

	ret = 1;
	pwd = ft_search_inallenv(sh, "PWD");
	if (!cmd || !cmd[1])
		path = ft_search_inallenv(sh, "HOME");
	else if (ft_strequ(cmd[1], "-"))
		path = ft_search_inallenv(sh, "OLDPWD");
	else if (ft_strstartwith(cmd[1], "/"))
		path = ft_strdup(cmd[1]);
	else
		path = ft_strjoin_key(pwd, cmd[1], "/");
	path = ft_cd_check_path(path);
	if (!path || access(path, F_OK) == -1 || chdir(path) == -1)
		ret = ft_error2("no such file or directory", cmd[1]);
	else
	{
		ft_setallenv(sh, "OLDPWD", pwd);
		ft_setallenv(sh, "PWD", path);
	}
	ft_strdel(&pwd);
	ft_strdel(&path);
	return (ret);
}
