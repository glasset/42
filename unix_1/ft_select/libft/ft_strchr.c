/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:27:02 by glasset           #+#    #+#             */
/*   Updated: 2013/11/30 15:27:34 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	char	*tmp;

	tmp = (char *) s;
	while (*tmp != '\0')
	{
		if (*tmp == (unsigned char) c)
			return (tmp);
		tmp++;
	}
	if (*tmp == (unsigned char) c)
		return (tmp);
	return (NULL);
}

