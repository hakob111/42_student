/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchalaby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:45:53 by hchalaby          #+#    #+#             */
/*   Updated: 2023/07/06 20:45:56 by hchalaby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	add_anim_img(void *mlx, t_map *map)
{
	int	img_width;
	int	img_hight;

	img_width = 60;
	img_hight = 60;
	map->player_anim = malloc (sizeof(void *) * 4);
	map->left_anim = malloc(sizeof(void *) * 2);
	map->right_anim = malloc(sizeof(void *) * 2);
	map->player_anim[0] = mlx_xpm_file_to_image(mlx, "./img/kietto1.xpm", \
		&img_width, &img_hight);
	map->player_anim[1] = mlx_xpm_file_to_image(mlx, "./img/kietto2.xpm", \
		&img_width, &img_hight);
	map->player_anim[2] = mlx_xpm_file_to_image(mlx, "./img/kietto3.xpm", \
		&img_width, &img_hight);
	map->player_anim[3] = mlx_xpm_file_to_image(mlx, "./img/kietto4.xpm", \
		&img_width, &img_hight);
	map->left_anim[0] = mlx_xpm_file_to_image(mlx, "./img/ich_left1.xpm", \
		&img_width, &img_hight);
	map->left_anim[1] = mlx_xpm_file_to_image(mlx, "./img/ich_left2.xpm", \
		&img_width, &img_hight);
	map->right_anim[0] = mlx_xpm_file_to_image(mlx, "./img/ich_right1.xpm", \
		&img_width, &img_hight);
	map->right_anim[1] = mlx_xpm_file_to_image(mlx, "./img/ich_right2.xpm", \
		&img_width, &img_hight);
}
