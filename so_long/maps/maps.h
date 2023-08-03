/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchalaby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:40:04 by hchalaby          #+#    #+#             */
/*   Updated: 2023/07/04 14:40:06 by hchalaby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPS_H
# define MAPS_H

# include "../Libft/libft.h"
# include "../Printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"

typedef struct s_data {
	int				map_hight;
	int				map_width;
	int				player;
	int				colect;
	int				exit;
	int				error;
	int				enemy;
	int				zero_count;
}					t_map_data;

t_map_data	make_zero(t_map_data *map1);
void		check_ber(char *str);
char		**check_fd(int argc, char **argv, t_map_data *map1);
char		**check_in_map(char *map, t_map_data *map1);
char		**check_map(int fd, t_map_data *map1);
void		floodfill(char **map, int x, int y);
void		fill(char **map, int x, int y, char c);
void		err_exit(char *str);
void		free_map(char **map);

#endif
