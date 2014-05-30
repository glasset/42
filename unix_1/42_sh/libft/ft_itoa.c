/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 10:37:25 by fkalb             #+#    #+#             */
/*   Updated: 2014/03/25 00:33:05 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char			*ft_itoa(int n)
{
	int			i;
	int			div;
	int			len;
	char		*str;
	short int	sign;

	i = 0;
	div = 1;
	len = 0;
	sign = n < 0 ? 1 : 0;
	if (n > 0)
		n *= -1;
	while (n / div < -9 && ++len > 0)
		div *= 10;
	str = malloc(sizeof(char) * (len + sign + 1));
	if (sign)
		str[i++] = '-';
	while (div >= 1)
	{
		str[i++] = '0' - n / div % 10;
		div /= 10;
	}
	str[i] = '\0';
	return (str);
}
