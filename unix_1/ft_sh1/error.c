/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 14:32:48 by glasset           #+#    #+#             */
/*   Updated: 2014/01/14 21:28:46 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "minishell.h"

void			notfound(char *str)
{
	write(1, "command not found: ", 19);
	write(1, &*str, ft_strlen(str));
	write(1, "\n", 1);
}

void			notdir(char *str)
{
	write(1, "cd: ", 4);
	write(1, &*str, ft_strlen(str));
	write(1, ": No such file or dorectory\n", 28);
}
