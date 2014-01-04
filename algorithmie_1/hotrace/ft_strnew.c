/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 16:48:50 by glasset           #+#    #+#             */
/*   Updated: 2013/12/15 20:44:33 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char			*ft_strnew(int size)
{
	char		*tmp;
	int			i;

	i = 0;
	tmp = (char *)malloc(sizeof(char) * (size + 1));
	if (tmp)
	{
	while (i < (size + 1))
		{
			tmp[i] = 0;
			i++;
		}
		return (tmp);
	}
	return (NULL);
}
