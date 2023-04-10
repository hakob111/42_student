/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchalaby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:01:07 by hchalaby          #+#    #+#             */
/*   Updated: 2023/01/25 19:01:09 by hchalaby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

char	*ft_strdup(const char *s1)
{
	char	*ret;
	size_t	ind;
	size_t	len;

	ind = 0;
	len = ft_strlen(s1) + 1;
	ret = malloc(len);
	if (!ret)
		return (0);
	while (ind < len)
	{
		ret[ind] = s1[ind];
		ind++;
	}
	ret[ind] = '\0';
	return (ret);
}

/*
int main (void)
{
	char *srt = "Hello World";
	char *copy = ft_strdup(srt);
	printf("%s", copy);
	return (0);
}
*/