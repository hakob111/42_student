/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ber.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchalaby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:39:39 by hchalaby          #+#    #+#             */
/*   Updated: 2023/07/04 14:39:48 by hchalaby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maps.h"

void	check_ber(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	while (i >= 0)
	{
		if (str[i] == '.')
			break ;
		i--;
	}
	if (ft_strncmp(&str[i], ".ber", 4) != 0)
		err_exit("invalid file type");
}

void	fill(char **map, int x, int y, char c)
{
	if (x < 0 || y < 0 || (map[y][x] != 'C' && map[y][x] != '0' \
		&& map[y][x] != c && map[y][x] != 'E'))
		return ;
	map[y][x] = 'x';
	fill(map, x - 1, y, c);
	fill(map, x + 1, y, c);
	fill(map, x, y - 1, c);
	fill(map, x, y + 1, c);
}

void	floodfill(char **map, int x, int y)
{
	int		i;
	int		j;
	char	z;

	i = 0;
	j = 0;
	z = map[y][x];
	fill(map, x, y, z);
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				err_exit("invalid map");
			j++;
		}
		j = 0;
		i++;
	}
}
