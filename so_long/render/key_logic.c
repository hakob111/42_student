/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_logic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchalaby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:46:57 by hchalaby          #+#    #+#             */
/*   Updated: 2023/07/04 14:59:03 by hchalaby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	w_logic(t_map *map)
{
	if (map->map[map->player.y - 1][map->player.x] == 'C')
	{
		map->map[map->player.y - 1][map->player.x] = 'P';
		map->map[map->player.y][map->player.x] = '0';
		map->player.y--;
		map->colect--;
		map->moves++;
	}
	else if (map->map[map->player.y - 1][map->player.x] == '0')
	{
		map->map[map->player.y - 1][map->player.x] = 'P';
		map->map[map->player.y--][map->player.x] = '0';
		map->moves++;
	}
	else if (map->map[map->player.y - 1][map->player.x] == 'e')
		exit_game(map, "Game Over you lose");
	else if (map->map[map->player.y - 1][map->player.x] \
			== 'E' && map->colect == 0)
	{
		map->map[map->player.y - 1][map->player.x] = 'P';
		map->map[map->player.y][map->player.x] = '0';
		map->player.y--;
		map->moves++;
		exit_game(map, "You win");
	}
}

void	d_logic(t_map *map)
{
	if (map->map[map->player.y][map->player.x + 1] == 'C')
	{
		map->map[map->player.y][map->player.x + 1] = 'P';
		map->map[map->player.y][map->player.x] = '0';
		map->player.x++;
		map->moves++;
		map->colect--;
	}
	else if (map->map[map->player.y][map->player.x + 1] == '0')
	{
		map->map[map->player.y][map->player.x + 1] = 'P';
		map->map[map->player.y][map->player.x++] = '0';
		map->moves++;
	}
	else if (map->map[map->player.y][map->player.x + 1] == 'e')
		exit_game(map, "Game Over you lose");
	else if (map->map[map->player.y][map->player.x + 1] \
			== 'E' && map->colect == 0)
	{
		map->map[map->player.y][map->player.x + 1] = 'P';
		map->map[map->player.y][map->player.x++] = '0';
		map->moves++;
		exit_game(map, "You win");
	}
}

void	s_logic(t_map *map)
{
	if (map->map[map->player.y + 1][map->player.x] == 'C')
	{
		map->map[map->player.y + 1][map->player.x] = 'P';
		map->map[map->player.y][map->player.x] = '0';
		map->player.y++;
		map->moves++;
		map->colect--;
	}
	else if (map->map[map->player.y + 1][map->player.x] == '0')
	{
		map->map[map->player.y + 1][map->player.x] = 'P';
		map->map[map->player.y++][map->player.x] = '0';
		map->moves++;
	}
	else if (map->map[map->player.y + 1][map->player.x] == 'e')
		exit_game(map, "Game Over you lose");
	else if (map->map[map->player.y + 1][map->player.x] \
			== 'E' && map->colect == 0)
	{
		map->map[map->player.y + 1][map->player.x + 1] = 'P';
		map->map[map->player.y][map->player.x] = '0';
		map->player.y++;
		map->moves++;
		exit_game(map, "You win");
	}
}

void	a_logic(t_map *map)
{
	if (map->map[map->player.y][map->player.x - 1] == 'C')
	{
		map->map[map->player.y][map->player.x - 1] = 'P';
		map->map[map->player.y][map->player.x] = '0';
		map->player.x--;
		map->moves++;
		map->colect--;
	}
	else if (map->map[map->player.y][map->player.x - 1] == '0')
	{
		map->map[map->player.y][map->player.x - 1] = 'P';
		map->map[map->player.y][map->player.x--] = '0';
		map->moves++;
	}
	else if (map->map[map->player.y][map->player.x - 1] == 'e')
		exit_game(map, "Game Over you lose");
	else if (map->map[map->player.y][map->player.x - 1] \
			== 'E' && map->colect == 0)
	{
		map->map[map->player.y][map->player.x - 1] = 'P';
		map->map[map->player.y][map->player.x] = '0';
		map->player.x--;
		map->moves++;
		exit_game(map, "You win");
	}
}
