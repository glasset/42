/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_search.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 21:49:58 by fkalb             #+#    #+#             */
/*   Updated: 2014/03/25 20:32:03 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sh42.h"

char		*ft_search_inenv(char **env, char *key)
{
	int		i;
	char	*value;
	char	*tmpkey;

	i = -1;
	if (!env || !key)
		return (NULL);
	tmpkey = ft_strjoin(key, "=");
	while (env[++i])
	{
		if (ft_strstartwith(env[i], tmpkey))
		{
			value = ft_strrepl(env[i], tmpkey, "");
			ft_strdel(&tmpkey);
			return (value);
		}
	}
	ft_strdel(&tmpkey);
	return (NULL);
}

char		*ft_search_inallenv(t_sh *sh, char *key)
{
	char	*tmp;

	tmp = ft_search_inenv(ENV, key);
	if (!tmp)
		tmp = ft_search_inenv(DEF_ENV, key);
	return (tmp);
}

int			ft_is_inenv(char **env, char *key)
{
	int		ret;
	char	*srch;

	ret = FALSE;
	if ((srch = ft_search_inenv(env, key)))
		ret = TRUE;
	free(srch);
	return (ret);
}

int			ft_envsize(char **env)
{
	int		i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}
