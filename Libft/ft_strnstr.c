/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchalaby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:35:11 by hchalaby          #+#    #+#             */
/*   Updated: 2023/01/25 19:35:20 by hchalaby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *hst, const char *need, size_t len)
{
	size_t	m;
	size_t	j;

	m = 0;
	j = 0;
	if (!hst && !len)
		return (0);
	if (!*need)
		return ((char *)hst);
	while (hst[m] && m < len)
	{
		while (hst[m] && (hst[m + j] == need[j]) && m + j < len)
		{
			j++;
			if (!need[j])
				return ((char *)hst + m);
		}
		if (j)
			j = 0;
		m++;
	}
	return (0);
}

/*
int main(void)
{
	char	p[] = "lorem ipsum dolor sit amet";
	char	s[] = "dolor";
	char	*res;

	res = ft_strnstr(p, s, 0);
	printf("main :%s\n", res);
	//res = strnstr(p, s, 0);
	//printf("original :%s", res);
	return (0);
}
*/
