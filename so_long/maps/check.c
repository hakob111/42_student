/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchalaby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:38:54 by hchalaby          #+#    #+#             */
/*   Updated: 2023/07/04 14:38:56 by hchalaby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../Printf/ft_printf.h"

t_map_data	make_zero(t_map_data *map)
{
	map->map_width = 0;
	map->map_hight = 0;
	map->player = 0;
	map->colect = 0;
	map->exit = 0;
	map->error = 0;
	map->enemy = 0;
	map->zero_count = 0;
	return (*map);
}

void	check_len(char **map, int *with, int *hight)
{
	int	i;

	i = 0;
	while(map[i] && map[i + 1])
	{
		if (ft_strlen(map[1]) != ft_strlen(map[i + 1]))
		{
			free(map);
			err_exit("wrog map");
		}
		i++;
	}
	*with = ft_strlen(map[i]) + 1;
	*hight = i + 1;
}

char	**check_fd(int argc, char **argv, t_map_data *map)
{
	int	fd;

	if (argc != 2)
		err_exit("invalid arguments");
	check_ber(argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		err_exit("no file in directory");
	return (check_map(fd, map));
}

char	**check_in_map(char *map, t_map_data *maps)
{
	int		index;
	char	**new_map;

	new_map = NULL;
	maps->player += ft_countchar(map, 'P');
	maps->colect += ft_countchar(map, 'C');
	maps->exit += ft_countchar(map, 'E');
	maps->enemy += ft_countchar(map, 'e');
	maps->zero_count += ft_countchar(map, '0') - 2;
	index = -1;
	while (map[++index])
	{
		if (!ft_strchr("01CPEe\n", map[index]))
		{
			maps->error = 2;
			printf("%d", maps->error);
		}
		if (ft_countchar(map, '\n') > (int)(ft_strlen(map) - 2))
			maps->error = 2;
	}
	if (maps->error != 0 || maps->player > 1 || \
			maps->colect == 0 || maps->exit > 1 || maps->player == 0)
		err_exit("wrog map");
	else
		new_map = ft_split(map, '\n');
	free(map);
	check_len(new_map, &maps->map_width, &maps->map_hight);
	return (new_map);
}

char	**check_map(int fd, t_map_data *map)
{
	char	*map1;
	char	*map2;
	int		i;

	i = 0;
	*map = make_zero(map);
	map2 = NULL;
	while (1)
	{
		map1 = get_next_line(fd);
		if (!map1)
			break ;
		map2 = joinandfree(map2, map1);
		free(map1);
	}
	map1 = ft_strtrim(map2, "\n");
	free(map2);
	while (map1[i] && map1[i + 1])
	{
		if (map1[i] == '\n' && map1[i + 1] == '\n')
			map->error = 1;
		i++;
	}
	return (check_in_map(map1, map));
}
