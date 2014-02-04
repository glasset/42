/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 12:25:54 by glasset           #+#    #+#             */
/*   Updated: 2014/02/04 16:39:03 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <mlx.h>
#include "rtv.h"

int				put_px_to_img(void *img, int x, int y)
{
	char		*data;
	int			bpp;
	int			size;
	int			endian;
	int			pos;

	data = mlx_get_data_addr(img, &bpp, &size, &endian);
	pos = y * size + x * bpp / 8;
	data[pos] = 200;
	data[pos + 1] = 200;
	data[pos + 2] = 200;
	return (0);
}
