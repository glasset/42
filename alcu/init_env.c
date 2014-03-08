/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 11:23:56 by glasset           #+#    #+#             */
/*   Updated: 2014/03/08 18:56:35 by gmarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "puissance.h"

int					init_board(t_env *e)
{
	int				i;
	int				j;

	i = 0;
	e->board = (char **)malloc(sizeof(char *) * e->line + 1);
	if (!e->board)
		return (put_error("ERROR: big bad malloc. U MAD?\n", -1));
	while (i < e->line)
	{
		j = 0;
		e->board[i] = (char *)malloc(sizeof(char) * e->col + 1);
		if (!e->board[i])
			return (put_error("ERROR: big bad malloc. U MAD?\n", -1));
		while (j < e->col)
			e->board[i][j++] = '.';
		e->board[i++][j] = '\0';
	}
	e->board[i] = NULL;
	return (0);
}

static char			*get_user(char **env)
{
	int		i;
	char	*ret;

	ret = NULL;
	i = -1;
	while (env[++i])
	{
		if (!ft_strncmp("USER=", env[i], 5))
			ret = ft_strdup(env[i] + 5);
	}
	if (ret)
		return (ret);
	return (ft_strdup("Player"));
}

int					init_env(t_env *e, char **av, char **env)
{
	e->line = ft_atoi(av[1]);
	e->col = ft_atoi(av[2]);
	if (e->line < MIN_L || e->col < MIN_C)
		return (put_error("ERROR : invalid parameters.\n", -1));
	e->name = get_user(env);
	return (0);
}
