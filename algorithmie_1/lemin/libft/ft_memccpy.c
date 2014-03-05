/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:17:18 by glasset           #+#    #+#             */
/*   Updated: 2013/11/26 10:53:45 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	const char	*tmp2;
	char		*tmp;

	tmp = (char *)s1;
	tmp2 = (const char *)s2;
	while (n--)
	{
		*tmp = *tmp2;
		tmp++;
		if (*tmp2 == (unsigned char) c)
			return ((void*)tmp);
		tmp2++;
	}
	return (NULL);
}

