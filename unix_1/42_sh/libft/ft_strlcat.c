/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 00:15:10 by fkalb             #+#    #+#             */
/*   Updated: 2014/02/14 02:18:32 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t			ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		len;
	size_t		ret;

	ret = ft_strlen(dest) + ft_strlen(src);
	len = size - ft_strlen(dest) - 1;
	if (size > ft_strlen(dest) + 1)
		ft_strncat(dest, src, len);
	else
		return (ft_strnlen(dest, size) + ft_strlen(src));
	return (ret);
}
