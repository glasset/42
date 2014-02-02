/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 15:23:57 by glasset           #+#    #+#             */
/*   Updated: 2014/02/02 19:28:39 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H
# include <stdlib.h>
# include "printf.h"

typedef struct			s_data
{
	int					oct;
	int					onechar[8];
}						t_data;

t_data					*env;
void					convert(void);

#endif /* !SERVER_H */

