/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchalaby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:53:51 by hchalaby          #+#    #+#             */
/*   Updated: 2023/01/25 18:54:06 by hchalaby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

void	ft_bzero(void *dest, size_t n)
{
	char	*s;
	size_t	m;

	s = dest;
	m = 0;
	while (m < n)
	{
		s[m] = '\0';
		m++;
	}
}

/*
int main (void)
{
	char p[10] = "0123456789";
	ft_bzero(p, 5);
	printf("%s\n", p);
	bzero(p, 1);
	printf("%s", p);
	return (0);
}
*/
