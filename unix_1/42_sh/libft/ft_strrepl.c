/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrepl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 11:37:48 by fkalb             #+#    #+#             */
/*   Updated: 2014/03/25 21:05:59 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

char	*ft_strrepl(char *src, char *del, char *repl)
{
	char	*tmp;
	char	*str;

	repl = repl == NULL ? "" : repl;
	if (!src || !del)
		return (NULL);
	tmp = ft_strstr(src, del);
	if (!tmp)
		return (ft_strdup(src));
	str = ft_strsub(src, 0, tmp - src);
	str = ft_strjoin_free(str, repl);
	str = ft_strjoin_free(str, tmp + ft_strlen(del));
	return (str);
}

char	*ft_strrepl_all(char *src, char *del, char *repl)
{
	int		i;
	int		len;
	char	*str;
	char	*tmp;

	i = -1;
	if ((str = NULL) != NULL || !src || !del)
		return (NULL);
	tmp = ft_strrepl(src, del, repl);
	len = ft_strlen(del);
	while (src[++i])
	{
		if (ft_strnequ(&(src[i]), del, len))
		{
			if (!tmp)
				tmp = ft_strdup(str);
			ft_strdel(&str);
			str = ft_strrepl(tmp, del, repl);
			ft_strdel(&tmp);
		}
	}
	ft_strdel(&tmp);
	if (!str || ft_strequ(str, ""))
		str = ft_strdup(src);
	return (str);
}
