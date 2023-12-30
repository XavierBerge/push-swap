/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:34:00 by xberger           #+#    #+#             */
/*   Updated: 2023/10/20 15:17:39 by xberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	lenght(unsigned int n)
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

char	*ft_uitoa(unsigned int n)
{
	char		*str;
	size_t		len;

	len = lenght(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		len--;
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}
