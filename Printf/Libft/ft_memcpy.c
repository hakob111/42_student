/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchalaby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:59:52 by hchalaby          #+#    #+#             */
/*   Updated: 2023/01/25 18:59:59 by hchalaby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	unsigned char		*p;
	const char			*c;
	size_t				m;

	if (!s1 && !s2)
		return (NULL);
	p = s1;
	c = s2;
	m = 0;
	while (m < n)
	{
		p[m] = c[m];
		m++;
	}
	return (s1);
}

/*
int main(void)
{
	char p[5] ;
	char c[15] = "it is string";
	//ft_memcpy(p, c, 9);
	//printf("%s\n", p);
	memcpy(p, c, 0);
	printf("%s", p);
	return (0);
}
*/
