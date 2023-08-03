/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:23:10 by hchalaby          #+#    #+#             */
/*   Updated: 2023/01/25 00:56:37 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	c1;

	c1 = c;
	len = ((int)(ft_strlen(s)));
	while (len >= 0)
	{
		if (s[len] == c1)
			return ((char *)s + len);
		len--;
	}
	return (0);
}
