/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 17:22:21 by glasset           #+#    #+#             */
/*   Updated: 2013/12/22 18:11:19 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINT_H
# include <stdarg.h>

typedef			int(*f)(va_list);

typedef struct	s_int
{
	int			cou;
	int			nbr;
	int			t;
}				t_int;


int				check_flag(char c);
int				ft_printf(char *format, ...);
f				*ft_function(void);
int				ft_strlen(char *str);
int				ft_atoi(char *str);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
int				ft_putstr(char *s);
void			ft_putchar(char c);
int				ft_putnbr(int n);
int				ft_putunint(unsigned int n);
int				ft_octal(unsigned int n);
int				ft_hexa(unsigned int n);
int				ft_hexax(unsigned long n);
int				check_space(char *str);
int				check_nbr(char *str, int *u, va_list arg);

int				use_putnbr(va_list arg);
int				use_octal(va_list arg);
int				use_hex(va_list arg);
int				use_hexx(va_list arg);
int				use_un_int(va_list arg);
int				use_putchar(va_list arg);
int				use_putstr(va_list arg);
int				use_countn(va_list arg);
int				use_pointer(va_list arg);
int				use_Z(va_list arg);
int				use_perc(char c);

#endif /* !PRINTF_H */
