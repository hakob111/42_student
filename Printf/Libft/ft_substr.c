/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchalaby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:19:44 by hchalaby          #+#    #+#             */
/*   Updated: 2023/02/01 19:19:46 by hchalaby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	index;

	index = 0;
	if (!s)
		return (NULL);
	if (len == 0 || ft_strlen(s) < start)
		return (ft_strdup("\0"));
	if (len > (ft_strlen(s) - start))
		len = (ft_strlen(s) - start) + 1;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	while (index < len)
	{
		result[index] = s[start + index];
		index++;
	}
	result[index] = '\0';
	return (result);
}
