/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchalaby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:47:11 by hchalaby          #+#    #+#             */
/*   Updated: 2023/07/04 15:22:59 by hchalaby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include <stdio.h>

int	keypress_mlx(int keypress, t_map *map)
{
	static int	i = 0;

	if (map->moves % 2 == 0)
		i = 1;
	else
		i = 0;
	if (keypress == 13 || keypress == 126)
		w_logic(map);
	if (keypress == 2 || keypress == 124)
	{
		d_logic(map);
		map->img_path.pl_img = map->right_anim[i];
	}
	if (keypress == 1 || keypress == 125)
		s_logic (map);
	if (keypress == 0 || keypress == 123)
	{
		a_logic(map);
		map->img_path.pl_img = map->left_anim[i];
	}
	if (keypress == 53 || keypress == -1)
		exit_game(map, "QUIT\n");
	return (0);
}

void	check_key(t_map *map)
{
	static int	i = 0;

	if (i % 15 == 0)
		map->img_path.pl_img = map->player_anim[0];
	if (i % 30 == 0)
		map->img_path.pl_img = map->player_anim[1];
	if (i % 45 == 0)
		map->img_path.pl_img = map->player_anim[2];
	if (i % 60 == 0)
		map->img_path.pl_img = map->player_anim[3];
	i++;
}

int	function(t_map *map)
{
	char	*steps;

	steps = ft_itoa(map->moves);
	check_key(map);
	mlx_clear_window(map->mlx, map->mlx_win);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->img_path.bg_img, 0, 0);
	put_images(map->map, map);
	mlx_string_put(map->mlx, map->mlx_win, 15, 15, \
		0xFFFF2F, steps);
	free(steps);
	return (0);
}
