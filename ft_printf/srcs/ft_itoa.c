/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:34:00 by xberger           #+#    #+#             */
/*   Updated: 2023/10/13 09:37:50 by xberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	lengh(int n)
{
	size_t	l;

	l = 0;
	if (n == 0)
		l = 1;
	while (n != 0)
	{
		n /= 10;
		l++;
	}
	return (l);
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		len;
	long int	num;

	num = n;
	len = lengh(n);
	if (num < 0)
	{
		num *= -1;
		len++;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = num % 10 + '0';
		num = num / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
