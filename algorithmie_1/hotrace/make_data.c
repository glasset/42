/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorbel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 12:56:36 by fcorbel           #+#    #+#             */
/*   Updated: 2014/01/04 14:15:29 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "hotrace.h"

int				make_data(t_lst info, char c, t_lst ***data)
{
	t_lst		*new;
	int			i;

	new = ft_lstnew(info.keyword, info.value);
	if (new && info)
	{
		if (c == '\n')
			ft_lstadd(&(*data)[127], new);
		else if (c >= 0 && c <= 127)
		{
			i = 0;
			while (i != c)
				i++;
			ft_lstadd(&(*data)[i], new);
		}
		else
			return (-1);
		return (0);
	}
	else
		return (-1);
}
