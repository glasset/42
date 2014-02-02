/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 15:52:50 by glasset           #+#    #+#             */
/*   Updated: 2014/02/02 20:57:24 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef USER_H
# define USER_H
# include <stdlib.h>
# include "printf.h"

int				ft_atoi(char *str);
int				get_bin(int c);
void			send_signal(int pid, int oc);
void			data(int pid, char *msg);

#endif /* !USE_H */
