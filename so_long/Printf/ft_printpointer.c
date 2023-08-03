/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchalaby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:30:30 by hchalaby          #+#    #+#             */
/*   Updated: 2023/02/20 17:30:33 by hchalaby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	numlen(unsigned long long num)
{
	int	len;

	len = 1;
	while (num / 16 != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

static char	*ft_inttohex(unsigned long long num)
{
	char	*result;
	int		num_len;

	num_len = numlen(num);
	result = ft_calloc((num_len + 1), sizeof(char));
	if (!result)
		return (0);
	while (num != 0 && num_len > 0)
	{
		if (num % 16 > 9 && num % 16 <= 15)
			result[num_len - 1] = (num % 16) + 87;
		else if (num % 16 < 10)
			result[num_len - 1] = (num % 16) + '0';
		num = num / 16;
		num_len--;
	}
	return (result);
}

int	ft_printpointer(unsigned long long c)
{
	int		i;
	char	*str;

	str = ft_inttohex(c);
	i = write(1, "0x", 2);
	if (!c)
		i += write(1, "0", 1);
	ft_putstr_fd(str, 1);
	i += ft_strlen(str);
	free(str);
	return (i);
}
