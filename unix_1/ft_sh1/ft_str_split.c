/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmizzi <cmizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 16:59:54 by cmizzi            #+#    #+#             */
/*   Updated: 2013/12/21 16:35:32 by cmizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"

static char	*ft_splitwords(char *s, char c)
{
	int		i;
	char	*word;
	
	i = 0;
	word = 0;
	word = (char *) malloc(sizeof(char *) * 100);
	while (*s != '\0' && *s != (unsigned char) c)
		word[i++] = *s++;
	word[i] = '\0';
	return (word);
}

char		**ft_str_split(const char *string, char c)
{
	char	**tab;
	int		i;
	char	*str;
	
	i = 0;
	tab = (char **) malloc(sizeof(char **) * 10);
	str = (char *) string;
	while (*str != '\0')
	{
		while (*str == (unsigned char) c)
			str++;
		if (*str != '\0')
		{
			tab[i++] = ft_splitwords(str, c);
			str = str + ft_strlen(tab[i - 1]);
		}
	}
	tab[i] = 0;
	return (tab);
}
