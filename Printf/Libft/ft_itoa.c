/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchalaby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:39:38 by hchalaby          #+#    #+#             */
/*   Updated: 2023/01/26 17:39:43 by hchalaby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(long int n)
{
	int	result;

	result = 0;
	if (n == 0)
		result++;
	if (n < 0)
	{
		result++;
		n = -n;
	}
	while (n > 0)
	{
		result++;
		n = n / 10;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	m;
	int			num_len;

	m = (long int)n;
	num_len = ft_numlen(n);
	str = malloc(num_len + 1);
	if (!str)
		return (0);
	str[num_len--] = '\0';
	if (m < 0)
		(str[0] = '-');
	if (m < 0)
		(m = -m);
	if (m == 0)
		str[0] = '0';
	while (m > 0)
	{
		str[num_len] = (m % 10) + '0';
		m = m / 10;
		num_len--;
	}
	return (str);
}
