/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsig.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchalaby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:30:12 by hchalaby          #+#    #+#             */
/*   Updated: 2023/02/20 17:30:14 by hchalaby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	numllen(unsigned int num)
{
	int	len;

	len = 1;
	while (num / 10 != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

int	ft_printunsig(unsigned int n)
{
	unsigned int	num;
	int				i;

	i = numllen(n);
	num = n;
	if (num >= 10)
	{
		ft_printunsig((num / 10));
		ft_printunsig((num % 10));
	}
	else
		ft_putchar_fd((num + '0'), 1);
	return (i);
}
