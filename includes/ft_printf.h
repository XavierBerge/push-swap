/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:42:55 by xberger           #+#    #+#             */
/*   Updated: 2023/10/21 07:12:54 by xberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>
# include <stdarg.h>

int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_percent(void);
int		ft_putnbr(int n);
int		ft_uint(unsigned int i);
int		ft_hex(unsigned int i, int uppercase);
int		ft_ptr(unsigned long long p);
int		ft_identifiers(va_list args, const char c);
int		ft_printf(const char *str, ...);
void	ft_puthex(unsigned int i, int uppercase);
void	ft_put_ptr(unsigned long long p);
#endif
