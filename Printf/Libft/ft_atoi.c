/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchalaby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:56:05 by hchalaby          #+#    #+#             */
/*   Updated: 2023/01/25 18:56:14 by hchalaby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	num;

	i = 1;
	num = 0;
	while (*str == 32 || (*str == '\t' || *str == '\r'
			|| *str == '\v' || *str == '\f' || *str == '\n'))
		str++;
	if ((*str == '-') || (*str == '+'))
	{
		if (*str == '-')
			i = -i;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	if (i < 0)
		return (num * i);
	return (num);
}

/*
int main (void)
{
	int val1;
	int val2;
	char st[10] = "4hello";
	val1 = ft_atoi(st);
	val2 = atoi(st);
	printf("original %d\n mayne %d", val2, val1);
	return (0);
}
*/
