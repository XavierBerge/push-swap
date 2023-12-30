/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:52:49 by xberger           #+#    #+#             */
/*   Updated: 2023/10/13 14:21:41 by xberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	slen;
	size_t	end;

	if (!s)
		return (0);
	slen = ft_strlen(s);
	end = 0;
	if (start >= slen)
		return (ft_strdup(""));
	if (start < slen)
		end = slen - start;
	if (end > len)
		end = len;
	substr = (char *)malloc(sizeof(char) * end + 1);
	if (!substr)
		return (0);
	ft_strlcpy(substr, s + start, end + 1);
	return (substr);
}
