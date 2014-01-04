/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmizzi <cmizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 16:59:54 by cmizzi            #+#    #+#             */
/*   Updated: 2013/12/21 16:35:32 by cmizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

int		ft_strlen(const char *);
int		ft_strcmp(const char *, const char *);

char	*ft_strcpy(char **, char *);
char	*ft_strjoin(char *, const char *, char);
char	*ft_strcat(const char *, const char *, char);

char	**ft_str_split(const char *, char);

void	ft_putstr(const char *);
void	ft_putendl(const char *);

#endif /* !FT_STRING_H */