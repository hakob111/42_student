/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchalaby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:45:16 by hchalaby          #+#    #+#             */
/*   Updated: 2023/07/11 17:45:18 by hchalaby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	exit_game(t_map *map, char *str)
{
	mlx_destroy_image(map->mlx, map->img_path.co_img);
	mlx_destroy_image(map->mlx, map->img_path.ex_img);
	mlx_destroy_image(map->mlx, map->img_path.enemy_img);
	mlx_destroy_image(map->mlx, map->img_path.wall_img);
	mlx_destroy_image(map->mlx, map->img_path.bg_img);
	mlx_destroy_image(map->mlx, map->right_anim[0]);
	mlx_destroy_image(map->mlx, map->right_anim[1]);
	mlx_destroy_image(map->mlx, map->left_anim[0]);
	mlx_destroy_image(map->mlx, map->left_anim[1]);
	mlx_destroy_image(map->mlx, map->player_anim[0]);
	mlx_destroy_image(map->mlx, map->player_anim[1]);
	mlx_destroy_image(map->mlx, map->player_anim[2]);
	mlx_destroy_image(map->mlx, map->player_anim[3]);
	free(map->right_anim);
	free(map->left_anim);
	free(map->player_anim);
	free_map(map->map);
	mlx_destroy_window(map->mlx, map->mlx_win);
	ft_putstr_fd(str, 1);
	system("leaks so_long");
	exit(0);
}
