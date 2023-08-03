/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchalaby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:47:39 by hchalaby          #+#    #+#             */
/*   Updated: 2023/07/04 14:47:40 by hchalaby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# ifndef IMG_WIDTH
#  define IMG_WIDTH 59
# endif

# ifndef IMG_HIGHT
#  define IMG_HIGHT 59
# endif

# include "../mlx/mlx.h"
# include "../maps/maps.h"

typedef struct path_data {
	void		*pl_img;
	void		*co_img;
	void		*ex_img;
	void		*enemy_img;
	void		*wall_img;
	void		*bg_img;
}				t_path;

typedef struct p_data {
	int	x;
	int	y;
}				t_play_d;

typedef struct map_info {
	void		*mlx;
	void		*mlx_win;
	int			colect;
	t_play_d	player;
	t_play_d	exit;
	int			with;
	int			hight;
	char		**map;
	int			moves;
	t_path		img_path;
	int			enemy;
	void		**player_anim;
	void		**left_anim;
	void		**right_anim;
}				t_map;

void	add_map(t_map *map1, t_map_data maps);
void	put_images(char **map, t_map *map1);
void	put_imge2(char **map, t_map *map1, int x, int y);
int		keypress_mlx(int keypress, t_map *map);
int		function(t_map *map);
void	w_logic(t_map *map);
void	d_logic(t_map *map);
void	s_logic(t_map *map);
void	a_logic(t_map *map);
void	add_anim_img(void *mlx, t_map *map);
void	check_key(t_map *map);
void	exit_game(t_map *map, char *str);
void	finde(char **map, char c, t_play_d *game);

#endif
