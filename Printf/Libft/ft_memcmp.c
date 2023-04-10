/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchalaby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:59:28 by hchalaby          #+#    #+#             */
/*   Updated: 2023/01/25 18:59:35 by hchalaby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t				m;
	const unsigned char	*s1;
	const unsigned char	*s2;

	s1 = str1;
	s2 = str2;
	m = 0;
	while (m < n)
	{
		if (s2[m] > s1[m])
			return (s1[m] - s2[m]);
		if (s2[m] < s1[m])
			return (s1[m] - s2[m]);
		m++;
	}
	return (0);
}

/*
int main (void)
{
	int real;
	int main;


	char st1[5] = "Alfaa";
	char st2[5] = "Aetta";
	real = memcmp(st1, st2, 4);
	main = ft_memcmp(st1, st2, 4);
	printf("%d\n %d", real, main);
	return (0);
}
*/
