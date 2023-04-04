/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchalaby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:59:11 by hchalaby          #+#    #+#             */
/*   Updated: 2023/01/25 18:59:17 by hchalaby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

void	*ft_memchr(void *src, int c, size_t n)
{
	const char	*s;
	size_t		num;
	char		m;

	s = src;
	m = c;
	num = 0;
	while (num < n)
	{
		if (s[num] == m)
			return ((void *)s + num);
		num++;
	}
	return (0);
}

/*
int main(void)
{
	char p[15] = "Hello World";
	char *m = ft_memchr(p, 'W', 11);
	printf("%s", m);
}
*/
