/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmizzi <cmizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 16:59:54 by cmizzi            #+#    #+#             */
/*   Updated: 2013/12/21 16:35:32 by cmizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUILTINS_H
# define FT_BUILTINS_H

int		ft_builtins(char *, char **, char ***);

void	ft_cd(char **, char ***);
char	**ft_setenv(char ***, const char *, const char *);
char	*ft_getenv(char ***, const char *);
void	ft_unsetenv(char ***, const char *);

#endif /* !FT_BUILTINS_H */