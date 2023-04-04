/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchalaby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:34:03 by hchalaby          #+#    #+#             */
/*   Updated: 2023/01/25 19:34:09 by hchalaby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
//#include <stdio.h>
//#include <stddef.h>
#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t				i;
	const unsigned char	*s1;
	const unsigned char	*s2;

	s1 = (const unsigned char *)str1;
	s2 = (const unsigned char *)str2;
	i = 0;
	while (s1[i] && i < n && s1[i] == s2[i])
	{
		i++;
	}
	if (i < n)
		return (s1[i] - s2[i]);
	else
		return (0);
}

/*
int main (void)
{
    int real;
    int main;


    char st1[5] = "test\200";
    char st2[5] = "test\0";
    real = strncmp(st1, st2, 6);
    main = ft_strncmp(st1, st2, 6);
    printf("%d\n %d", real, main);
    return (0);
}
*/
