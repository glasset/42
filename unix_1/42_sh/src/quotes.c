/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 21:31:44 by fkalb             #+#    #+#             */
/*   Updated: 2014/03/26 19:38:00 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sh42.h"
#include <unistd.h>

static int	ft_count(char *str, char c)
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (str[++i])
	{
		if (str[i] == c)
			count++;
	}
	return (count);
}

static int	ft_is_escape(char *str, int i)
{
	int		j;

	j = i - 1;
	while (j > 0 && str[j] == '\\')
		j--;
	if (((i - j) % 2))
		return (FALSE);
	return (TRUE);
}

static char	*ft_quotes_read(char *str, char c)
{
	int			count;
	char		*line;
	char		*prompt;

	count = 0;
	line = NULL;
	prompt = c == '\"' ? "dquotes > " : "quotes > ";
	while (count % 2 == 0)
	{
		ft_putstr(prompt);
		if (ft_getline(0, &line) > 0)
		{
			count += ft_count(line, c);
			str = ft_strfjoin_key(str, line, "\\n");
			free(line);
		}
	}
	return (str);
}

char		**ft_strsplit_esc(char *str, char c)
{
	int		i;
	char	**tab;
	char	type;
	int		nb;

	i = -1;
	nb = 0;
	type = -1;
	while (str[++i])
	{
		if (nb % 2 == 0)
		{
			if ((str[i] == '\'' || str[i] == '\"') && !ft_is_escape(str, i))
				type = str[i];
		}
		if (str[i] == type && !ft_is_escape(str, i))
			nb++;
		if (nb % 2 == 0 && str[i] == c)
			str[i] = 127;
	}
	if (nb % 2 != 0)
		return (ft_strsplit_esc(ft_quotes_read(str, type), c));
	tab = ft_strsplit(str, 127);
	ft_strdel(&str);
	return (tab);
}
