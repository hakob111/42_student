/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchalaby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:05:59 by hchalaby          #+#    #+#             */
/*   Updated: 2023/02/19 17:06:01 by hchalaby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	unsigned int	ft_nummin(int n)
{
	if (n < 0)
		return (n * (-1));
	else
		return (n);
}

static int	numllen(int num)
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

int	ft_printint(int n)
{
	unsigned int	num;
	int				i;

	i = 0;
	num = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		i++;
	}
	num = ft_nummin(n);
	i += numllen(n);
	if (num >= 10)
	{
		ft_printint((num / 10));
		ft_printint((num % 10));
	}
	else
		ft_putchar_fd((num + 48), 1);
	return (i);
}
