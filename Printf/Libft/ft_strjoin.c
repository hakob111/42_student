/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchalaby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:27:59 by hchalaby          #+#    #+#             */
/*   Updated: 2023/02/01 20:28:02 by hchalaby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		index;
	int		index1;
	char	*result;

	index = 0;
	index1 = 0;
	if (!s1 || !s2)
		return (NULL);
	result = malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!result)
		return (0);
	while (s1[index])
	{
		result[index] = s1[index];
		index++;
	}
	while (s2[index1])
	{
		result[index] = s2[index1];
		index++;
		index1++;
	}
	result[index] = '\0';
	return (result);
}
