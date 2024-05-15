/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:48:27 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/15 17:39:10 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	get_player_position(t_player *player)
{
  player->pos_pix.x = player->sprite->img->instances[0].x;
  player->pos_pix.y = player->sprite->img->instances[0].y;
	player->pos_map.x = player->pos_pix.x / TILE_SIZE;
	player->pos_map.y = player->pos_pix.y / TILE_SIZE;
}

void	set_player_position(t_player *player, int x, int y)
{
	player->sprite->img->instances[0].x = x;
	player->sprite->img->instances[0].y = y;
}

t_bool	check_hit_wall(t_map *map, int x, int y, t_direction direct)
{
  if (direct == EAST)
    x++;
  else if (direct == SOUTH)
    y++;
  // else if (direct == WEST)
  //   x--;
  // else if (direct == NORTH)
  //   y--;
  
	if (map->mtx[y][x] == '1')
		return (TRUE);
	return (FALSE);
}
