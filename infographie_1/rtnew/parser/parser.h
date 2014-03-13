/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 15:22:29 by glasset           #+#    #+#             */
/*   Updated: 2014/03/13 16:06:06 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# define START_OBJ "{"
# define END_OBJ "}"

# include "ray_tracer.h"
# include "gnl.h"

typedef			int(*f)(t_env *e, int c_l, int fd);
/*
**	tools
*/
f				*funct(void);
t_color			get_color(char *str);
int				check_arg(char *str, int flag);

#endif /* !PARSER_H */

