/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchalaby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:35:12 by hchalaby          #+#    #+#             */
/*   Updated: 2023/07/04 14:35:14 by hchalaby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countchar(char *str, char a)
{
	int	index;
	int	result;

	index = 0;
	result = 0;
	while (str[index])
	{
		if (str[index] == a)
			result++;
		index++;
	}
	return (result);
}
