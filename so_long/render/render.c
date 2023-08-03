/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchalaby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:47:27 by hchalaby          #+#    #+#             */
/*   Updated: 2023/07/04 14:47:33 by hchalaby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	finde(char **map, char c, t_play_d *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[x] != NULL)
	{
		while (map[x][y] != '\0')
		{
			if (map[x][y] == c)
			{
				game->x = y;
				game->y = x;
				break ;
			}
			y++;
		}
		y = 0;
		x++;
	}
}

void	app_spr(void *mlx, t_path *path)
{
	int	img_width;
	int	img_hight;

	img_hight = 60;
	img_width = 60;
	path->pl_img = mlx_xpm_file_to_image(mlx, "./img/kietto1.xpm", \
		&img_width, &img_hight);
	path->co_img = mlx_xpm_file_to_image(mlx, "./img/collect.xpm", \
		&img_width, &img_hight);
	path->ex_img = mlx_xpm_file_to_image(mlx, "./img/exit.xpm", \
		&img_width, &img_hight);
	path->wall_img = mlx_xpm_file_to_image(mlx, "./img/wall.xpm", \
		&img_width, &img_hight);
	path->bg_img = mlx_xpm_file_to_image(mlx, "./img/back.xpm", \
		&img_width, &img_hight);
	path->enemy_img = mlx_xpm_file_to_image(mlx, "./img/GHOST.xpm", \
		&img_width, &img_hight);
}

void	add_map(t_map *map1, t_map_data maps)
{
	map1->mlx = mlx_init();
	map1->colect = maps.colect;
	map1->with = maps.map_width;
	map1->hight = maps.map_hight;
	app_spr(map1->mlx, &map1->img_path);
	add_anim_img(map1->mlx, map1);
	finde(map1->map, 'P', &map1->player);
	finde(map1->map, 'E', &map1->exit);
	map1->moves = 0;
	map1->enemy = maps.enemy;
}

void	put_images(char **map, t_map *map1)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[x])
	{
		while (map[x][y])
		{
			if (map[x][y] == '1')
				mlx_put_image_to_window(map1->mlx, map1->mlx_win, \
					map1->img_path.wall_img, \
					(y * IMG_WIDTH), (x * IMG_HIGHT));
			else
				put_imge2(map, map1, x, y);
			y++;
		}
		y = 0;
		x++;
	}
}

void	put_imge2(char **map, t_map *map1, int x, int y)
{
	if (map[x][y] == 'E')
		mlx_put_image_to_window(map1->mlx, map1->mlx_win, \
			map1->img_path.ex_img, \
			(map1->exit.x * IMG_WIDTH), (map1->exit.y * IMG_HIGHT));
	else if (map[x][y] == 'P')
		mlx_put_image_to_window(map1->mlx, map1->mlx_win, \
			map1->img_path.pl_img, \
			(map1->player.x * IMG_WIDTH), (map1->player.y * IMG_HIGHT));
	else if (map[x][y] == 'e')
		mlx_put_image_to_window(map1->mlx, map1->mlx_win, \
			map1->img_path.enemy_img, \
			(y * IMG_WIDTH), (x * IMG_HIGHT));
	else if (map[x][y] == 'C')
		mlx_put_image_to_window(map1->mlx, map1->mlx_win, \
			map1->img_path.co_img, \
			(y * IMG_WIDTH), (x * IMG_HIGHT));
}
