/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 21:23:12 by fkalb             #+#    #+#             */
/*   Updated: 2014/03/27 08:51:02 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	ft_nbword(char const *s, char *s2, size_t len)
{
	size_t		i;
	size_t		j;
	char		equ;
	short int	bol;

	j = 0;
	i = -1;
	bol = 0;
	while (len > 0 && s[++i])
	{
		equ = 0;
		if (s[i] == s2[0] && (equ = ft_strnequ(&s[i], s2, len)))
		{
			bol = 0;
			i += (len - 1);
		}
		if (equ == 0 && !bol)
		{
			j++;
			bol = 1;
		}
	}
	return (j);
}

static size_t	ft_strslen(char const *s, char *s2, size_t len)
{
	size_t		i;

	i = 0;
	while (s[i] && (s[i] != s2[0] || !ft_strnequ(&s[i], s2, len)))
		i++;
	return (i);
}

char			**ft_strssplit(char const *s, char *s2)
{
	size_t		i;
	size_t		j;
	size_t		len;
	size_t		wlen;
	char		**ret;

	i = 0;
	j = 0;
	len = ft_strlen(s2);
	if (!s || !(ret = malloc(sizeof(char *) * (ft_nbword(s, s2, len) + 1))))
		return (NULL);
	while (s[i])
	{
		while (s[i] == s2[0] && ft_strnequ(&s[i], s2, len))
			i += len;
		if (!s[i])
			break ;
		wlen = ft_strslen(&s[i], s2, len);
		ret[j++] = ft_strsub(s, i, wlen);
		i += wlen;
	}
	ret[j] = '\0';
	return (ret);
}
