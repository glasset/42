/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   script.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/29 14:56:43 by glasset           #+#    #+#             */
/*   Updated: 2014/04/29 16:41:14 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCRIPT_H
#define SCRIPT_H

typedef struct		s_env
{
	int				fd;
	char			*name;
}					t_env;

t_env				e;

void		init_file(char *name);
void		ft_puts(char *str, int fd);
void		end_file(void);

#endif
