/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchalaby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:37:15 by hchalaby          #+#    #+#             */
/*   Updated: 2023/01/25 19:37:22 by hchalaby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stddef.h>
//#include <stdio.h>
#include "libft.h"
//#include <string.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (size && src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
		j++;
	}
	if (size)
		dest[i] = '\0';
	while (j < size && src[j])
	{
		dest[j] = '\0';
		j++;
	}
	while (src[i])
	{
		i++;
	}
	return (i);
}

/*
int main() {
  char p[] = "rrrrr000000000";
  //size_t n = strlcpy(p, "lorem ipsum dolor sit amet", 0);
  size_t n = ft_strlcpy(p, "lorem ipsum dolor sit amet", 0);
  printf("%s\n", p);
  printf("%ld", n);

  return 0;
}
*/
