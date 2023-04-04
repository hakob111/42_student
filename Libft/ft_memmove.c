/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchalaby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:00:19 by hchalaby          #+#    #+#             */
/*   Updated: 2023/01/25 19:00:25 by hchalaby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*ds;
	char	*sr;
	int		m;

	ds = dest;
	sr = (char *)src;
	m = (int)(n - 1);
	if (ds == sr)
		return (ds);
	if (ds < sr)
	{
		while (n--)
		{
			*(ds++) = *(sr++);
		}
		return (dest);
	}
	while (m >= 0)
	{
		ds[m] = sr[m];
		m--;
	}
	return (ds);
}
