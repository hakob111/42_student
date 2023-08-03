/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchalaby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:34:22 by hchalaby          #+#    #+#             */
/*   Updated: 2023/02/24 18:51:20 by hchalaby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*joinandfree(char *str, char *buffer)
{
	char	*result;

	result = NULL;
	if (!str)
	{
		str = (char *)malloc(1 * sizeof(char));
		if (!str)
			return (0);
		str[0] = '\0';
	}
	result = ft_strjoin(str, buffer);
	if (!result)
		return (0);
	free(str);
	return (result);
}

void	finkcia(char **str, char	**str1)
{
	free(*str);
	if (*str1)
		free(*str1);
	*str1 = NULL;
}

char	*longline(char *str)
{
	int		index;
	int		ind2;
	char	*result;

	index = 0;
	while (str[index] && str[index] != '\n')
		index++;
	if (str[index] == '\0' || str[index + 1] == '\0')
	{
		free(str);
		return (0);
	}
	ind2 = index + 1;
	result = malloc(1 + (ft_strlen(str) - ind2) * sizeof(char));
	if (!result)
		return (0);
	index = 0;
	while (str[ind2 + index])
	{
		result[index] = str[index + ind2];
		index++;
	}
	result[index] = '\0';
	free(str);
	return (result);
}

char	*getn(char *string)
{
	int		index;
	char	*valid_line;

	index = 0;
	if (!string || !string[index])
		return (0);
	while (string[index] && string[index] != '\n')
		index++;
	if (string[index] == '\n')
		index++;
	valid_line = (char *)malloc((index + 1) * sizeof(char));
	if (!valid_line)
		return (0);
	index = 0;
	while (string[index] && string[index] != '\n')
	{
		valid_line[index] = string[index];
		index++;
	}
	if (string[index] == '\n')
		valid_line[index++] = '\n';
	valid_line[index] = '\0';
	return (valid_line);
}

char	*get_next_line(int fd)
{
	char		*tmp;
	int			fd_read;
	static char	*start_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	fd_read = 1;
	tmp = (char *)malloc(1 + BUFFER_SIZE * sizeof(char));
	if (!tmp)
		return (0);
	while (!(ft_strchr(start_str, '\n')) && fd_read != 0)
	{
		fd_read = read(fd, tmp, BUFFER_SIZE);
		if (fd_read == -1)
		{
			finkcia(&tmp, &start_str);
			return (0);
		}
		tmp[fd_read] = '\0';
		start_str = joinandfree(start_str, tmp);
	}
	free(tmp);
	tmp = getn(start_str);
	start_str = longline(start_str);
	return (tmp);
}
