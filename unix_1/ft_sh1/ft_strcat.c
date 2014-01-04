/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmizzi <cmizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 16:59:54 by cmizzi            #+#    #+#             */
/*   Updated: 2013/12/21 16:35:32 by cmizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"

char	*ft_strcat(const char *s1, const char *s2, char c)
{
	char	*str;
	int		i;
	
	str = 0;
	str = (char *) malloc(sizeof(char *) * 10);
	if (str)
	{
		i = 0;
		while (*s1 != '\0')
			str[i++] = *s1++;
		str[i++] = c;
		while (*s2 != '\0')
			str[i++] = *s2++;
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
