/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchalaby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:37:01 by hchalaby          #+#    #+#             */
/*   Updated: 2023/02/16 19:37:04 by hchalaby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	checkformat(va_list str, const char s)
{
	int	i;

	i = 0;
	if (s == 'i' || s == 'd')
		i += ft_printint(va_arg(str, int));
	else if (s == 's')
		i += ft_printstring(va_arg(str, char *));
	else if (s == 'x')
		i += ft_printhex(va_arg(str, int), 87);
	else if (s == 'X')
		i += ft_printhex(va_arg(str, int), 55);
	else if (s == 'u')
		i += ft_printunsig(va_arg(str, unsigned int));
	else if (s == 'p')
		i += ft_printpointer(va_arg(str, unsigned long long));
	else if (s == 'c')
		i += ft_printchar(va_arg(str, int));
	else if (s == '%')
		i += ft_printchar('%');
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		ret;
	va_list	string;

	i = 0;
	ret = 0;
	va_start(string, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ret += checkformat(string, str[i + 1]);
			i++;
		}
		else
			ret += ft_printchar(str[i]);
		i++;
	}
	va_end(string);
	return (ret);
}
