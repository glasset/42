/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_operator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 01:50:00 by fkalb             #+#    #+#             */
/*   Updated: 2014/03/27 13:09:07 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"
#include "libft.h"

static void		ft_logic_operator_or(t_sh *sh, char *str)
{
	int			i;
	char		last;
	char		**tab;
	char		**args;

	i = -1;
	tab = ft_strssplit(str, "||");
	while (tab[++i])
	{
		last = i > 0 ? OR : FALSE;
		if (last == OR && LAST_RET_VAL == 0)
			break ;
		if (!(args = ft_create_args(sh, tab[i])) || !args[0])
			LAST_RET_VAL = 0;
		else if (ft_builtin(sh, args) != FALSE)
			LAST_RET_VAL = 0;
		else if (ft_check_located_cmd(sh, args) != 0)
			LAST_RET_VAL = 42;
		ft_strtabdel(&args);
	}
	ft_strtabdel(&tab);
}

void			ft_logic_operator_and(t_sh *sh, char *str)
{
	int			i;
	char		last;
	char		**tab;

	i = -1;
	last = FALSE;
	tab = ft_strssplit(str, "&&");
	while (tab[++i])
	{
		if (last == AND && LAST_RET_VAL != 0)
			break ;
		ft_logic_operator_or(sh, tab[i]);
		last = AND;
	}
	ft_strtabdel(&tab);
}
