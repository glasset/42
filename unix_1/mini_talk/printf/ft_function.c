/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 12:17:05 by glasset           #+#    #+#             */
/*   Updated: 2013/12/21 17:01:06 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "printf.h"

f			*ft_function(void)
{
	f		*ft;

	ft = malloc(sizeof(ft) * 11);
	ft[0] = &use_putnbr;
	ft[1] = &use_putnbr;
	ft[2] = &use_octal;
	ft[3] = &use_hexx;
	ft[4] = &use_hex;
	ft[5] = &use_un_int;
	ft[6] = &use_putchar;
	ft[7] = &use_putstr;
	ft[8] = &use_countn;
	ft[9] = &use_pointer;
	ft[10] = &use_Z;
	return (ft);
}
