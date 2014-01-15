/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:17:33 by glasset           #+#    #+#             */
/*   Updated: 2013/11/28 16:25:55 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <string.h>
#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char	*tmp2;
	char	*tmp;
	size_t	i;

	tmp = s1;
	tmp2 = (char*)malloc(ft_strlen((char*)s2));
	ft_strcpy(tmp2, (const char*)s2);
	i = 0;
	while (i < n)
	{
		*tmp++ = *tmp2++;
		i++;
	}
	return (s1);
}

