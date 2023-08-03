/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchalaby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:36:45 by hchalaby          #+#    #+#             */
/*   Updated: 2023/01/25 19:36:53 by hchalaby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stddef.h>
//#include <string.h>
#include "libft.h"
/*
size_t	ft_strlen(const char *st)
{
	size_t	i;

	i = 0;
	while (st[i] != '\0')
	{
		i++;
	}
	return (i);
}
*/

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	d_len;
	size_t	s_len;

	if (size == 0 && !dest)
		return (ft_strlen(src));
	i = ft_strlen(dest);
	j = 0;
	d_len = i;
	s_len = ft_strlen(src);
	while (src[j] && i + 1 < size)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	if (size < d_len)
		return (s_len + size);
	else
		return (d_len + s_len);
}

/*
int main (void)
{
	char p[] = "rrrrr00000000a0";
	char c[] = "lorem ipsum dolor sit amet";
	size_t m = ft_strlcat(p, c, 15);
	//size_t n = strlcat(p, c, 15);
	printf("%s\n", p);
	printf("%ld\n", m);
	//printf("%ld\n", n);
	return (0);
}
*/
