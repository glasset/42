/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 20:55:53 by fkalb             #+#    #+#             */
/*   Updated: 2014/03/25 18:52:05 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void		*ft_memmove(void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*tmp;
	char	*ptr1;
	char	*ptr2;

	i = 0;
	ptr1 = ((char*)s1);
	ptr2 = ((char*)s2);
	tmp = malloc(sizeof(ptr2) * n);
	while (i < n)
	{
		tmp[i] = ptr2[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		ptr1[i] = tmp[i];
		i++;
	}
	free(tmp);
	return (s1);
}
