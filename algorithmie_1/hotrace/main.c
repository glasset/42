/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 14:05:20 by glasset           #+#    #+#             */
/*   Updated: 2014/01/04 19:50:08 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <fcntl.h>
#include "hotrace.h"

int				main(void)
{
	t_lst		***data;
	t_lst		**tmp;
	int			i;

	tmp = NULL;
	tmp = (t_lst **)malloc(sizeof(tmp));
	i = 0;
	data = (t_lst ***)malloc(sizeof(data));
	while (i < 128)
	{
		tmp[i] = ft_lstnew(".", ".");
		data[i] = &tmp[i];
		i++;
	}
	get_info(&(*data), 0);
	result_data(data);
	return (0);
}

