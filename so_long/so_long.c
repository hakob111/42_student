/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchalaby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:34:27 by hchalaby          #+#    #+#             */
/*   Updated: 2023/07/06 20:26:12 by hchalaby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_map *map)
{
	exit_game(map, "Quit");
	return (0);
}

char	**map_copy(char **map)
{
	int		i;
	char	**result;

	i = 0;
	while (map[i])
		i++;
	result = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (map[i])
	{
		result[i] = ft_strdup(map[i]);
		i++;
	}
	result[i] = NULL;
	return(result);
}

int	main(int argc, char **argv)
{
	void		*mlx_win;
	t_map_data	map;
	t_map		*map1;
	char		**map_2d;

	map_2d = NULL;
	map1 = (t_map *)malloc(sizeof(t_map));
	map1->map = check_fd(argc, argv, &map);
	map_2d = map_copy(map1->map);
	finde(map1->map, 'P', &map1->player);
	floodfill(map_2d, map1->player.x, map1->player.y);
	free_map(map_2d);
	add_map(map1, map);
	mlx_win = mlx_new_window(map1->mlx, (map1->with * IMG_WIDTH - map.zero_count), \
		(map1->hight * IMG_HIGHT), "so_long");
	map1->mlx_win = mlx_win;
	mlx_put_image_to_window(map1->mlx, map1->mlx_win, \
		map1->img_path.bg_img, 5, 5);
	put_images(map1->map, map1);
	mlx_hook(map1->mlx_win, 2, 0, &keypress_mlx, map1);
	mlx_loop_hook(map1->mlx, &function, map1);
	mlx_hook(map1->mlx_win, 17, 0, &close_window, map1);
	mlx_loop(map1->mlx);
}
