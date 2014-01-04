/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmizzi <cmizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 16:59:54 by cmizzi            #+#    #+#             */
/*   Updated: 2013/12/21 16:35:32 by cmizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_builtins.h"

void	ft_unsetenv(char ***envp, const char *alias)
{
	char	**env;
	char	**parts;
	int		i;
	
	env = *envp;
	i = 0;
	while (env[i] != 0 && (parts = ft_str_split(env[i], '=')) != 0)
	{
		if (ft_strcmp(parts[0], (char *) alias))
			env[i] = "";
		i = i + 1;
	}
}