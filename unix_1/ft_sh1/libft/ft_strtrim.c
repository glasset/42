/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 18:43:55 by glasset           #+#    #+#             */
/*   Updated: 2013/11/28 16:30:41 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		b;
	int		c;
	char	*tmp;

	i = 0;
	b = 0;
	c = ft_strlen(s) - 1;
	while (s[b] == ' ' || s[b] == '\n' || s[b] == '\t')
		b++;
	while ((s[c] == ' ' || s[c] == '\n' || s[c] == '\t') && c > b)
		c--;
	tmp = (char*)malloc(sizeof(s) * ((c - b) + 1));
	if (tmp)
	{
		if (c - b >= 0)
		{
			while (b <= c)
				tmp[i++] = s[b++];
		}
		tmp[i] = 0;
		return (tmp);
	}
	return (NULL);
}

