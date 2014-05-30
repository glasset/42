/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 01:18:24 by fkalb             #+#    #+#             */
/*   Updated: 2014/03/27 13:15:36 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

static void		ft_prompt(t_sh *sh)
{
	char	*res;
	char	*src;
	char	*del;

	src = ft_search_inallenv(sh, "PWD");
	del = ft_search_inallenv(sh, "HOME");
	ft_putstr("\xF0\x9F\x93\x82  ");
	if (!(res = ft_strrepl(src, del, "\033[0;33;m~\033[0m")))
		ft_putstr(src);
	else
		ft_putstr(res);
	ft_putstr(" > ");
	ft_strdel(&res);
	ft_strdel(&del);
	ft_strdel(&src);
}

int				main(int ac, char **av, char **env)
{
	t_sh		sh;

	(void)ac;
	(void)av;
	sh.end = FALSE;
	ft_newenv(&sh, env);
	ft_defaultenv(&sh);
	while (sh.end == FALSE)
	{
		ft_prompt(&sh);
		ft_read(&sh);
	}
	ft_strtabdel(&(sh.env));
	ft_strtabdel(&(sh.def_env));
	return (sh.exit_ret);
}
