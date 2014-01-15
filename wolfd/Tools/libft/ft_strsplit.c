/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorbel <fcorbel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 15:41:31 by fcorbel           #+#    #+#             */
/*   Updated: 2013/12/16 17:33:27 by fcorbel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <string.h>

#include "libft.h"

static int	size_malloc(const char *s, char c)
{
	int		i;
	int		n_words;

	i = 1;
	n_words = 0;
	while (s[i])
	{
		if (s[i] == c && s[i - 1] != c)
			n_words++;
		i++;
	}
	if (s[i] == 0 && s[i - 1] != c)
		n_words++;
	return (n_words);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tmp;
	int		n_words;
	int		count[3];

	count[1] = 0;
	n_words = size_malloc(s, c);
	tmp = (char **)malloc(sizeof(char *) * (n_words + 1));
	while (*s && count[1] < n_words)
	{
		count[0] = 0;
		count[2] = 0;
		while (*s == c)
			s++;
		while (s[count[0]] != c && s[count[0]])
			count[0]++;
		tmp[count[1]] = (char *)malloc(sizeof(char) * (count[0] + 1));
		if (tmp == 0 || tmp[count[1]] == 0)
			return (NULL);
		while ((*s != c || *s) && count[2] < count[0])
			tmp[count[1]][count[2]++] = *s++;
		tmp[count[1]++][count[2]] = 0;
	}
	tmp[count[1]] = NULL;
	return (tmp);
}
