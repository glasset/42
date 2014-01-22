/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:24:13 by glasset           #+#    #+#             */
/*   Updated: 2013/12/10 17:00:30 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*tmp;
	size_t	i;

	tmp = (char *) s;
	i = 0;
	while (i < n)
	{
		if (*tmp == (unsigned char) c)
			return (tmp);
		tmp++;
		i++;
	}
	return (NULL);
}
