/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmizzi <cmizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 16:59:54 by cmizzi            #+#    #+#             */
/*   Updated: 2013/12/21 16:35:32 by cmizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"
#include "ft_builtins.h"

char	**ft_setenv(char ***envp, const char *name, const char *value)
{
	char	**parts;
	char	**env;
	int		i;
	
	env = *envp;
	i = 0;
	while (env[i] != 0 && (parts = ft_str_split(env[i], '=')) != 0)
	{
		if (ft_strcmp(parts[0], name))
		{
			parts[1] = (char *) value;
			env[i] = ft_strcat((char *) name, parts[1], '=');

			return (env);
		}
		i = i + 1;
	}
	env[i] = (char *) malloc(sizeof(char *));
	env[i++] = ft_strcat((char *) name, value, '=');
	env[i] = 0;
	return (env);
}
