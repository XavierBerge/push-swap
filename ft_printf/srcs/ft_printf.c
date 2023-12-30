/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:55:04 by xberger           #+#    #+#             */
/*   Updated: 2023/12/27 15:25:13 by xberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_putnbr(int n)
{
	char	*put_nbr;
	int		len;

	len = 0;
	put_nbr = ft_itoa(n);
	len = ft_putstr(put_nbr);
	free(put_nbr);
	return (len);
}

int	ft_uint(unsigned int i)
{
	unsigned int	len;
	char			*put_uint;

	len = 0;
	put_uint = ft_uitoa(i);
	len = ft_putstr(put_uint);
	free(put_uint);
	return (len);
}

int	ft_identifiers(va_list args, const char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (c == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		len += ft_ptr(va_arg(args, unsigned long long));
	else if (c == 'd' || c == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		len += ft_uint(va_arg(args, unsigned int));
	else if (c == 'x')
		len += ft_hex(va_arg(args, unsigned int), 0);
	else if (c == 'X')
		len += ft_hex(va_arg(args, unsigned int), 1);
	else if (c == '%')
		len += ft_percent();
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_identifiers(args, str[i + 1]);
			i++;
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
/*
#include <limits.h>
int main(void)
{
	int result = 0;
	int result1 = 0;

	result = ft_printf("%c\n", '0');
	result1 = printf("%c\n", '0');
	printf("%d : %d\n", result, result1);
	result = ft_printf(" %c \n", '0');
	result1 = printf(" %c \n", '0');
	printf("%d : %d\n", result, result1);
	result = ft_printf(" %c \n", '0' - 256);
	result1 = printf(" %c \n", '0' - 256);
	printf("%d : %d\n", result, result1);
	result = ft_printf("%c \n", '0' + 256);
	result1 = printf("%c \n", '0' + 256);
	printf("%d : %d\n", result, result1);
	result = ft_printf(" %c %c %c \n", '0', 0, '1');
	result1 = printf(" %c %c %c \n", '0', 0, '1');
	printf("%d : %d\n", result, result1);
	result = ft_printf(" %c %c %c \n", ' ', ' ', ' ');
	result1 = printf(" %c %c %c \n", ' ', ' ', ' ');
	printf("%d : %d\n", result, result1);
	result = ft_printf(" %c %c %c \n", '1', '2', '3');
	result1 = printf(" %c %c %c \n", '1', '2', '3');
	printf("%d : %d\n", result, result1);

	void *ptr = (void *)-1;
	result = ft_printf(" %p \n", ptr);
	result1 = printf(" %p \n", ptr);
	printf("%d : %d\n", result, result1);

	ptr = (void *)1;
	result = ft_printf(" %p \n", ptr);
        result1 = printf(" %p \n", ptr);
        printf("%d : %d\n", result, result1);

	ptr = (void *)15;
        result = ft_printf(" %p \n", ptr);
        result1 = printf(" %p \n", ptr);
        printf("%d : %d\n", result, result1);

	ptr = (void *)16;
        result = ft_printf(" %p \n", ptr);
        result1 = printf(" %p \n", ptr);
        printf("%d : %d\n", result, result1);

	ptr = (void *)LONG_MIN;
	void *ptr1 = (void *)LONG_MAX;
        result = ft_printf(" %p %p \n", ptr, ptr1);
        result1 = printf(" %p %p \n", ptr, ptr1);
        printf("%d : %d\n", result, result1);

	ptr = (void *)INT_MIN;
        ptr1 = (void *)INT_MAX;
        result = ft_printf(" %p %p \n", ptr, ptr1);
        result1 = printf(" %p %p \n", ptr, ptr1);
        printf("%d : %d\n", result, result1);

	ptr = (void *)ULONG_MAX;
        ptr1 = (void *)-ULONG_MAX;
        result = ft_printf(" %p %p \n", ptr, ptr1);
        result1 = printf(" %p %p \n", ptr, ptr1);
        printf("%d : %d\n", result, result1);

	ptr = (void *)0;
        ptr1 = (void *)0;
        result = ft_printf(" %p %p \n", ptr, ptr1);
        result1 = printf(" %p %p \n", ptr, ptr1);
        printf("%d : %d\n", result, result1);

	result = ft_printf(" %d \n", 0);
        result1 = printf(" %d \n", 0);
        printf("%d : %d\n", result, result1);

	result = ft_printf(" %d \n", -1);
        result1 = printf(" %d \n", -1);
        printf("%d : %d\n", result, result1);

	result = ft_printf(" %d \n", 1);
        result1 = printf(" %d \n", 1);
        printf("%d : %d\n", result, result1);

	result = ft_printf(" %d \n", INT_MIN);
        result1 = printf(" %d \n", INT_MIN);
        printf("%d : %d\n", result, result1);

	result = ft_printf(" %d \n", INT_MAX);
        result1 = printf(" %d \n", INT_MAX);
        printf("%d : %d\n", result, result1);

	result = ft_printf(" %i \n", 0);
        result1 = printf(" %i \n", 0);
        printf("%d : %d\n", result, result1);

        result = ft_printf(" %i \n", -1);
        result1 = printf(" %i \n", -1);
        printf("%d : %d\n", result, result1);

        result = ft_printf(" %i \n", 1);
        result1 = printf(" %i \n", 1);
        printf("%d : %d\n", result, result1);

        result = ft_printf(" %i \n", INT_MIN);
        result1 = printf(" %i \n", INT_MIN);
        printf("%d : %d\n", result, result1);

        result = ft_printf(" %i \n", INT_MAX);
        result1 = printf(" %i \n", INT_MAX);
        printf("%d : %d\n", result, result1);

	result = ft_printf(" %x \n", 0);
        result1 = printf(" %x \n", 0);
        printf("%d : %d\n", result, result1);

	result = ft_printf(" %x \n", 1);
        result1 = printf(" %x \n", 1);
        printf("%d : %d\n", result, result1);

	result = ft_printf(" %x \n", -1);
        result1 = printf(" %x \n", -1);
        printf("%d : %d\n", result, result1);

	result = ft_printf(" %x \n", 9);
        result1 = printf(" %x \n", 9);
        printf("%d : %d\n", result, result1);

	result = ft_printf(" %x \n", 15);
        result1 = printf(" %x \n", 15);
        printf("%d : %d\n", result, result1);

	result = ft_printf(" %x \n", 16);
        result1 = printf(" %x \n", 16);
        printf("%d : %d\n", result, result1);

}
*/
