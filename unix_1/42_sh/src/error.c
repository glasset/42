/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/27 08:52:34 by fkalb             #+#    #+#             */
/*   Updated: 2014/03/25 18:00:18 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sh42.h"

int		ft_error3(char *prog, char *error, char *name)
{
	prog = prog == NULL ? PGNAME : prog;
	ft_putstr_fd(prog, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(error, 2);
	if (name)
	{
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(name, 2);
	}
	return (-1);
}

int		ft_error2(char *error, char *name)
{
	return (ft_error3(NULL, error, name));
}

int		ft_error1(char *error)
{
	return (ft_error3(NULL, error, NULL));
}
