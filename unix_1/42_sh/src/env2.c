/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 16:31:54 by fkalb             #+#    #+#             */
/*   Updated: 2014/03/25 18:44:27 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sh42.h"
#include <stdlib.h>

static int	ft_verif(t_sh *sh, char *key)
{
	char	*str;
	char	err;

	err = 1;
	if (sh->warn_bypass == TRUE)
		return (err);
	ft_putstr("\033[2m\033[33mWARNING\033[m: ");
	ft_putstr("do you really want replace / delete \033[1m");
	ft_putstr(key);
	ft_putstr("\033[m");
	ft_putstr(" ? (yes/no) : ");
	str = ft_read_fd(0);
	if (!ft_strnequ(str, "y", 1))
		err = ERROR;
	ft_strdel(&str);
	return (err);
}

int			ft_setenv(t_sh *sh, char ***env, char *key, char *value)
{
	int		i;
	char	*equ;
	char	**tmp;

	i = -1;
	if (!key)
		return (ft_error2("setenv failure", "key not set"));
	value = value == NULL ? "" : value;
	if (ft_unsetenv(sh, env, key) == ERROR)
		return (ERROR);
	if (!(tmp = (char **)malloc(sizeof(char *) * (2 + ft_envsize(*env)))))
		return (ft_error2("setenv failure", "malloc"));
	while ((*env)[++i])
		tmp[i] = ft_strdup((*env)[i]);
	if (!(equ = ft_strstr(key, "=")))
		tmp[i] = ft_strjoin_key(key, value, "=");
	else
		tmp[i] = ft_strdup(key);
	tmp[i + 1] = NULL;
	ft_strtabdel(env);
	*env = tmp;
	return (1);
}

int			ft_setallenv(t_sh *sh, char *key, char *value)
{
	int		err;

	err = 1;
	sh->warn_bypass = TRUE;
	if (ft_setenv(sh, &ENV, key, value) == ERROR)
		err = ERROR;
	if (ft_setenv(sh, &DEF_ENV, key, value) == ERROR)
		err = ERROR;
	sh->warn_bypass = FALSE;
	return (err);
}

int			ft_unsetenv(t_sh *sh, char ***env, char *key)
{
	int		i;
	int		j;
	char	**tmp;

	i = -1;
	j = -1;
	if (ft_is_inenv(*env, key) == FALSE)
		return (1);
	if (ft_verif(sh, key) == ERROR)
		return (ERROR);
	if (!(tmp = (char **)malloc(sizeof(char *) * ft_envsize(*env))))
		return (ft_error2("unsetenv failure", "malloc"));
	while ((*env)[++i])
	{
		if (!ft_strstartwith((*env)[i], key))
			tmp[++j] = ft_strdup((*env)[i]);
	}
	tmp[j + 1] = NULL;
	ft_strtabdel(env);
	*env = tmp;
	return (1);
}

int			ft_unsetenv_all(t_sh *sh, char *key)
{
	if (ft_unsetenv(sh, &ENV, key) == ERROR)
		return (ERROR);
	if (ft_unsetenv(sh, &DEF_ENV, key) == ERROR)
		return (ERROR);
	return (1);
}
