/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 17:21:46 by glasset           #+#    #+#             */
/*   Updated: 2013/12/29 18:36:32 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "hotrace.h"

t_lst			*reverse(t_lst *alst)
{
	t_lst		*tmp1;
	t_lst		*tmp2;

	if (alst)
	{
		tmp1 = alst->next;
		alst->next = NULL;
		while (tmp1)
		{
			tmp2 = tmp1->next;
			tmp1->next = alst;
			alst = tmp1;
			tmp1 = tmp2;
		}
	}
	return (alst);
}

void			search(char *str, t_lst *tmp)
{
	while (ft_strcmp(str, tmp->keyword) != 0 && tmp->next)
		tmp = tmp->next;
	if (ft_strcmp(str, tmp->keyword) == 0)
		ft_putendl(tmp->value);
	else
		ft_error(str);
}

int				result_data(t_lst ***data)
{
	int			i;
	char		c;
	char		*str;
	t_lst		*tmp;

	(*data)[127] = reverse((*data)[127]);
	(*data)[127] = (*data)[127]->next;
	while ((*data)[127] != NULL)
	{
		str = (*data)[127]->keyword;
		c = (*data)[127]->keyword[0];
		i = 0;
		while (i != c)
			i++;
		tmp = (*data)[i];
		search(str, tmp);
		if ((*data)[127]->next)
			(*data)[127] = (*data)[127]->next;
		else
			return (0);
	}
	return (-1);
}
