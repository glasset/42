/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmizzi <cmizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 16:59:54 by cmizzi            #+#    #+#             */
/*   Updated: 2013/12/21 16:35:32 by cmizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include "ft_sh1.h"

static void	quitHandler(int dummy)
{
	dummy = dummy + 1;
	exit(0);
}

static void	intHandler(int dummy)
{
	dummy = dummy + 1;
	ft_putstr(BACKLINE);
	exit(0);
}

extern char	**environ;

int			main(void)
{
	signal(SIGINT, intHandler);
	signal(SIGQUIT, quitHandler);
	
	ft_minishell_loop(&environ);
	return (0);
}

