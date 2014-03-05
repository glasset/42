/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 18:38:00 by glasset           #+#    #+#             */
/*   Updated: 2014/03/03 13:01:39 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <string.h>
#include "my.h"
char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = (char*)malloc(sizeof(s) * len);
	if (tmp)
	{
		while (len--)
		{
		tmp[i] = s[start];
		start++;
		i++;
		}
		tmp[i] = 0;
		return (tmp);
	}
	return (NULL);
}
