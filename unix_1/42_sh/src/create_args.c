/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 14:41:48 by fkalb             #+#    #+#             */
/*   Updated: 2014/03/25 21:08:27 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sh42.h"
#include <stdlib.h>

char		**ft_create_args(t_sh *sh, char *str)
{
	int		i;
	char	*tmp;
	char	**args;

	i = -1;
	str = ft_strtrim(str);
	args = ft_strsplit_esc(str, ' ');
	str = ft_strnew(0);
	while (args[++i])
	{
		args[i] = ft_repl_dollars(sh, args[i]);
		args[i] = ft_repl_tilds(sh, args[i]);
		tmp = ft_strtrim(args[i]);
		str = ft_strfjoin_key(str, tmp, " ");
		ft_strdel(&tmp);
	}
	tmp = str;
	str = ft_strtrim(tmp);
	ft_strtabdel(&args);
	args = ft_strsplit_esc(str, ' ');
	ft_strdel(&tmp);
	return (args);
}

static char	*ft_repl_dollars_spe(t_sh *sh, char *str)
{
	char	*tmp;
	char	*val;

	val = ft_itoa(LAST_RET_VAL);
	tmp = ft_strrepl_all(str, "$?", val);
	ft_strdel(&val);
	if (!tmp)
		tmp = str;
	else
		ft_strdel(&str);
	return (tmp);
}

char		*ft_repl_dollars(t_sh *sh, char *str)
{
	int		i;
	int		j;
	char	*tmp;
	char	*tmp2;
	char	*env_line;

	i = -1;
	str = ft_repl_dollars_spe(sh, str);
	while (str && str[++i])
	{
		j = i + 1;
		while (str[i] == '$' && ft_isalpha(str[j]))
			j++;
		if (str[i] == '$' && (tmp = ft_strsub(str, i, j - i)))
		{
			env_line = ft_search_inallenv(sh, &tmp[1]);
			tmp2 = ft_strrepl(str, tmp, env_line);
			ft_strdel(&str);
			str = tmp2;
			ft_strdel(&tmp);
			ft_strdel(&env_line);
			i--;
		}
	}
	return (str);
}

char		*ft_repl_tilds(t_sh *sh, char *str)
{
	char	*tmp;
	char	*home;

	if (!str || !str[0])
		return (str);
	tmp = NULL;
	home = ft_search_inallenv(sh, "HOME");
	if (ft_strnequ(str, "~/", 2) || (str[0] == '~' && !str[1]))
		tmp = ft_strrepl(str, "~", home);
	if (!tmp)
		tmp = str;
	else
		ft_strdel(&str);
	ft_strdel(&home);
	return (tmp);
}
