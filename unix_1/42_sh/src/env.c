/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 06:54:24 by fkalb             #+#    #+#             */
/*   Updated: 2014/03/27 14:16:47 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sh42.h"

static void		ft_env_i(t_sh *sh, char **args)
{
	char		**save_env;

	if (!args || !args[0])
		return ;
	save_env = ENV;
	ENV = NULL;
	ft_check_unlocated_cmd(sh, args);
	ENV = save_env;
}

static void		ft_env_u(t_sh *sh, char **args, char **env)
{
	char		*line;

	if (!args || !args[0])
		return ;
	if (env && env[0])
		line = ft_search_inenv(env, args[0]);
	else
		line = ft_search_inenv(DEF_ENV, args[0]);
	if (line)
		ft_putendl(line);
	ft_strdel(&line);
}

static void		ft_env_print(t_sh *sh, char **env)
{
	int			i;

	i = -1;
	if ((!env || !env[0]) && DEF_ENV[0])
		ft_env_print(sh, DEF_ENV);
	while (env && env[++i])
		ft_putendl(env[i]);
}

int				ft_env(t_sh *sh, char **args, char **env)
{
	if (args && args[0] && args[1])
	{
		if (ft_strequ(args[1], "-") || ft_strequ(args[1], "-i"))
			ft_env_i(sh, &args[2]);
		else if (ft_strequ(args[1], "-u"))
			ft_env_u(sh, &args[2], env);
		else
			ft_check_located_cmd(sh, &args[1]);
	}
	else
		ft_env_print(sh, env);
	return (1);
}
