/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr_hex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:58:48 by xberger           #+#    #+#             */
/*   Updated: 2023/10/25 14:08:43 by xberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_ptr(unsigned long long p)
{
	int	len;

	len = 0;
	if (p == 0)
	{
		len += write(1, "(nil)", 5);
		return (len);
	}
	else
	{
		len += write(1, "0x", 2);
		ft_put_ptr(p);
	}
	while (p != 0)
	{
		p /= 16;
		len++;
	}
	return (len);
}

void	ft_put_ptr(unsigned long long p)
{
	if (p >= 16)
	{
		ft_put_ptr(p / 16);
		ft_put_ptr(p % 16);
	}
	else
	{
		if (p <= 9)
			ft_putchar((p + '0'));
		else
			ft_putchar((p - 10 + 'a'));
	}
}

int	ft_hex(unsigned int i, int uppercase)
{
	int	len_hex;

	len_hex = 0;
	ft_puthex(i, uppercase);
	if (i == 0)
		return (1);
	while (i != 0)
	{
		i /= 16;
		len_hex++;
	}
	return (len_hex);
}

void	ft_puthex(unsigned int i, int uppercase)
{
	char	hex_char;
	int		remainder;

	if (i >= 16)
		ft_puthex(i / 16, uppercase);
	remainder = i % 16;
	if (remainder < 10)
		hex_char = '0' + remainder;
	else
	{
		if (uppercase)
			hex_char = 'A' + remainder - 10;
		else
			hex_char = 'a' + remainder - 10;
	}
	ft_putchar(hex_char);
}
