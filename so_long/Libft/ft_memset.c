/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchalaby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:38:24 by hchalaby          #+#    #+#             */
/*   Updated: 2023/01/25 19:38:37 by hchalaby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

char	*ft_memset(const void *dest, int c, size_t n)
{
	char	*pt;
	size_t	i;

	pt = (char *)dest;
	i = 0;
	while (i < n)
	{
		pt[i] = c;
		i++;
	}
	return (pt);
}

/*
int main(void)
{
	char p[10] = "012345678";
	ft_memset(p, '5', 10);
	printf("%s\n", p);
	memset(p, '5', 10);
	printf("%s\n", p);
	return (0);

}
*/
