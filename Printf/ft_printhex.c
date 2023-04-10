/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchalaby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:47:15 by hchalaby          #+#    #+#             */
/*   Updated: 2023/02/18 16:47:17 by hchalaby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	numlen(unsigned int num)
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

int	ft_printhex(unsigned int n, int charnum)
{
	int				i;

	i = numlen(n);
	if (n >= 16)
	{
		ft_printhex((n / 16), charnum);
		ft_printhex((n % 16), charnum);
	}
	else
	{
		if (n > 9 && n <= 15)
			ft_putchar_fd((n + charnum), 1);
		else
			ft_putchar_fd((n + '0'), 1);
	}
	return (i);
}
