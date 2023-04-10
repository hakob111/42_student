/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchalaby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:11:57 by hchalaby          #+#    #+#             */
/*   Updated: 2023/02/03 01:27:27 by hchalaby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**dif(char **str1)
{
	str1 = malloc(sizeof(char *));
	if (!str1)
		return (0);
	str1[0] = 0;
	return (str1);
}

static int	char_count(const char *s, char c)
{
	int	count;
	int	index;

	count = 0;
	index = 0;
	while (s[index++])
	{
		if ((s[index] != '\0' && s[index] == c && s[index + 1] != c)
			&& (s[index + 1] != '\0') && index > 0)
		{
			count++;
			while (s[index] == c)
				index++;
		}
	}
	return (count);
}

static size_t	char_count1(const char *s, char c)
{
	int	index;

	index = 0;
	while (s[index] && s[index] != c)
		index++;
	return (index);
}

static char	**whi(char **result, const char *s, char c, int ch_coun)
{
	int	i;

	i = 0;
	while (i < ch_coun + 1)
	{
		while (*s == c)
			s++;
		result[i] = ft_substr(s, 0, char_count1(s, c));
		if (!result[i])
		{
			while (i >= 0)
			{
				free(result[i]);
				i--;
			}
			free(result);
			return (0);
		}
		s = s + (char_count1(s, c));
		i++;
	}
	result[i] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		ch_coun;

	result = NULL;
	if (!s)
		return (0);
	while (*s == c && *s)
		s++;
	if (!*s)
		return (dif(result));
	ch_coun = (char_count(s, c));
	result = malloc (sizeof(char *) * (ch_coun + 2));
	if (!result)
		return (0);
	result = whi (result, s, c, ch_coun);
	return (result);
}
