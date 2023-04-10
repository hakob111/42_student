/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchalaby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:36:49 by hchalaby          #+#    #+#             */
/*   Updated: 2023/01/30 19:36:52 by hchalaby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	index;
	size_t	len1;
	char	*result;

	index = 0;
	if (!s1)
		return (0);
	len1 = ft_strlen(s1);
	while (s1[index] && ft_strchr(set, s1[index]))
	{
		index++;
	}
	if (index == len1)
	{
		result = ft_substr("\0", 0, 1);
		return (result);
	}
	while ((ft_strchr(set, s1[len1 - 1])) && len1 > 0)
	{
		len1--;
	}
	result = ft_substr(s1 + index, 0, (len1 - index));
	return (result);
}
