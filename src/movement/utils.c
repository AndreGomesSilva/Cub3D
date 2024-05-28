/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:48:27 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/27 17:35:14 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// void	get_player_position(t_player *player)
// {
// 	set_vector(&player->pos_pix, player->sprite->img->instances[0].x,
// 			player->sprite->img->instances[0].y);
//   set_vector(&player->pos_map, player->pos_pix.x / TILE_SIZE, player->pos_pix.y / TILE_SIZE);
// }

// void	set_player_position(t_player *player, int x, int y)
// {
// 	player->sprite->img->instances[0].x = x;
// 	player->sprite->img->instances[0].y = y;
// 	player->dir_line.sprite->img->instances[0].x = x - 15;
// 	player->dir_line.sprite->img->instances[0].y = y - 15;
//   player->plane.sprite->img->instances[0].x = player->dir_line.sprite->img->instances[0].x;
//   player->plane.sprite->img->instances[0].y = player->dir_line.sprite->img->instances[0].y; 
// }

t_bool	check_hit_wall(t_map *map, int x, int y, t_direction direct)
{
	if (direct == EAST)
		x++;
	else if (direct == SOUTH)
		y++;
	else if (direct == WEST)
	  x--;
	else if (direct == NORTH)
	  y--;
	if (map->mtx[y][x] == '1')
		return (TRUE);
	return (FALSE);
}
