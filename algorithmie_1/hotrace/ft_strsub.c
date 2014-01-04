/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 12:15:09 by glasset           #+#    #+#             */
/*   Updated: 2013/12/15 20:44:43 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char			*ft_strsub(char *str, int start, int len)
{
	char		*tmp;
	int			i;

	i = 0;
	tmp = (char*)malloc(sizeof(str) * len);
	if (tmp)
	{
		while (len--)
		{
			tmp[i] = str[start];
			start++;
			i++;
		}
		tmp[i] = 0;
		return (tmp);
	}
	return (NULL);
}

