/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmizzi <cmizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 16:59:54 by cmizzi            #+#    #+#             */
/*   Updated: 2013/12/21 16:35:32 by cmizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strjoin(char *dest, const char *src, char c)
{
	int		i;
	int		dlen;
	
	dlen = ft_strlen(dest);
	i = 0;
	dest[dlen++] = c;
	while (src[i] != '\0')
		dest[dlen++] = src[i++];
	dest[dlen] = '\0';
	
	return (dest);
}
