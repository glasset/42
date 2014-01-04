/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c									    :+:      :+:    :+:   */
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

char	*ft_getenv(char ***envp, const char *name)
{
	char	**parts;
	char	**env;
	int		i;
	
	i = 0;
	env = *envp;
	while ((parts = ft_str_split(env[i++], '=')) != NULL)
	{
		if (ft_strcmp(parts[0], name))
			return (parts[1]);
	}
	return (NULL);
}
