/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchalaby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:06:40 by hchalaby          #+#    #+#             */
/*   Updated: 2023/02/19 17:06:43 by hchalaby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstring(char *str)
{
	int	i;

	i = 0;
	if (!str)
		i = write(1, "(null)", 6);
	else
	{
		i = ft_strlen(str);
		ft_putstr_fd(str, 1);
	}
	return (i);
}
