/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchau <kchau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 15:01:15 by kchau             #+#    #+#             */
/*   Updated: 2014/03/26 09:57:56 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"
#include "libft.h"

static int	ft_quit(t_sh *sh, char **args)
{
	sh->exit_ret = 0;
	sh->end = TRUE;
	if (args[1])
		sh->exit_ret = ft_atoi(args[1]);
	return (1);
}

static int	ft_pwd(t_sh *sh)
{
	char	*pwd;

	pwd = ft_search_inenv(ENV, "PWD");
	if (pwd)
		ft_putendl(pwd);
	ft_strdel(&pwd);
	return (1);
}

static int	ft_echo(char **args)
{
	int		i;
	int		option;

	option = args[1] ? ft_strequ(args[1], "-n") : -1;
	i = option == -1 ? 0 : option;
	while (args[++i])
	{
		if (i > option + 1)
			ft_putchar(' ');
		ft_putstr(args[i]);
	}
	if (!option)
		ft_putchar('\n');
	return (1);
}

int			ft_builtin(t_sh *sh, char **args)
{
	if (ft_strequ(args[0], "exit") || ft_strequ(args[0], "quit"))
		return (ft_quit(sh, args));
	if (ft_strequ(args[0], "echo"))
		return (ft_echo(args));
	if (ft_strequ(args[0], "cd"))
		return (ft_cd(sh, args));
	if (ft_strequ(args[0], "pwd"))
		return (ft_pwd(sh));
	if (ft_strequ(args[0], "env"))
		return (ft_env(sh, args, ENV));
	if (ft_strequ(args[0], "setenv"))
		return (ft_setenv(sh, &ENV, args[1], args[2]));
	if (ft_strequ(args[0], "unsetenv"))
		return (ft_unsetenv(sh, &ENV, args[1]));
	return (0);
}
