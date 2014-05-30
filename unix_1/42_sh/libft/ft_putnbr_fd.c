/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 21:48:07 by fkalb             #+#    #+#             */
/*   Updated: 2013/11/24 10:21:41 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	div;

	div = 1;
	if (n < 0)
		ft_putchar_fd('-', fd);
	else
		n *= -1;
	while (n / div < -9)
		div *= 10;
	while (div >= 1)
	{
		ft_putchar_fd('0' - n / div % 10, fd);
		div /= 10;
	}
}
