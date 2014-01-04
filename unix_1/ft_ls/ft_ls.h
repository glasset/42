/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 10:36:29 by glasset           #+#    #+#             */
/*   Updated: 2013/12/15 23:30:40 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# define error (-1)
# include <dirent.h>
# include "libft.h"

typedef struct dirent	d_struct;

typedef struct			s_struct
{
	char				*a;
}						t_struct;

void					ft_printbadopt(char c);
void					ft_printperror(char *str);

int						ft_check(char **av, int ac, t_struct **t);
int						ft_noption(char **alst, int ac);
int						ft_a(char **alst, int ac);

#endif /* !FT_LS_H */
