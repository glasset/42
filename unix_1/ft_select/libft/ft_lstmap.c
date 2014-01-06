/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 17:26:31 by glasset           #+#    #+#             */
/*   Updated: 2013/12/11 16:24:33 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;
	t_list	**alst;

	alst = NULL;
	if (lst && (*f))
	{
		tmp = ft_lstnew(lst->content, lst->content_size);
		tmp = f(tmp);
		alst = &tmp;
		lst = lst->next;
		while (lst)
		{
			new = ft_lstnew(lst->content, lst->content_size);
			new = f(new);
			tmp->next = new;
			lst = lst->next;
		}
	}
	return (*alst);
}
