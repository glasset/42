/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 16:00:05 by glasset           #+#    #+#             */
/*   Updated: 2013/12/29 18:40:04 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <string.h>

typedef struct		s_lst
{
	int				num;
	struct s_lst	*next;
	struct s_lst	*prev;
}					t_lst;

typedef struct		p_lst
{
	size_t			len;
	struct s_lst	*end;
	struct s_lst	*start;
}					l_lst;

l_lst				*lst_new(void);
l_lst				*lst_add_end(l_lst *l_x, int num);
l_lst				*lst_add_start(l_lst *l_x, int num);

int					s_swap(l_lst **la, l_lst **lb, char c);
int					p_swap(l_lst **la, l_lst **lb, char c);
int					r_swap(l_lst **la, l_lst **lb, char c, char way);
int					ft_atoi(char *str);

l_lst				*l_sort(l_lst *la, l_lst *lb);

#endif /* !PUSHSWAP_H */
