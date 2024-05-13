/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:56:46 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/13 18:25:51 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	get_player_position(t_player *player)
{
	player->pos.x = player->sprite->img->instances[0].x;
	player->pos.y = player->sprite->img->instances[0].y;
	player->pos.z = player->sprite->img->instances[0].z;
}

void	set_player_position(t_player *player, int x, int y)
{
	player->sprite->img->instances[0].x = x;
	player->sprite->img->instances[0].y = y;
}

void	move_up(t_player *player, t_map *map)
{
  int position_x;
  int position_y;

  position_x = player->pos.x / player->sprite->size.w;
  position_y = player->pos.y / player->sprite->size.h;
  if (check_hit_wall(map, position_x, position_y - 1))
    return ;
  set_player_position(player, player->pos.x, player->pos.y - 1);
}
