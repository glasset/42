/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 23:04:19 by fkalb             #+#    #+#             */
/*   Updated: 2014/02/01 17:12:38 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char		*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc (sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	while (i <= size)
		str[i++] = '\0';
	return (str);
}
