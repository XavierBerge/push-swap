/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:33:39 by xberger           #+#    #+#             */
/*   Updated: 2023/10/06 11:22:03 by xberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t				i;

	i = 0;
	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return ((int)str1[i] - str2[i]);
		i++;
	}
	return (0);
}
/*
int main()
{
    // Données de test
    char str1[] = "Hello";
    char str2[] = "Hello";
    char str3[] = "World";

    // Comparaison avec la fonction originale
    int result1 = memcmp(str1, str2, 5);
    int result2 = memcmp(str1, str3, 5);

    // Comparaison avec votre fonction
    int result3 = memcmp(str1, str2, 5);
    int result4 = memcmp(str1, str3, 5);

    // Affichage des résultats
    printf("memcmp(str1, str2): %d\n", result1);
    printf("memcmp(str1, str3): %d\n", result2);
    printf("ft_memcmp(str1, str2): %d\n", result3);
    printf("ft_memcmp(str1, str3): %d\n", result4);

    return 0;
}
*/
