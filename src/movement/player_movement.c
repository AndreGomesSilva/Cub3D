/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:56:46 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/13 20:42:30 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	move_up(t_player *player, t_map *map)
{
  int position_x;
  int position_y;

  position_x = player->pos.x / player->sprite->size.w;
  position_y = player->pos.y / player->sprite->size.h;
	if (check_hit_wall(map, position_x, position_y))
		return ;
	set_player_position(player, player->pos.x, player->pos.y - 1);
  get_player_position(player);
}

void	move_down(t_player *player, t_map *map)
{
  int position_x;
  int position_y;

  position_x = player->pos.x / player->sprite->size.w;
  position_y = player->pos.y / player->sprite->size.h;
  if (check_hit_wall(map, position_x, position_y))
    return ;
  set_player_position(player, player->pos.x, player->pos.y + 1);
  get_player_position(player);
}

void move_right(t_player *player, t_map *map)
{
  int position_x;
  int position_y;

  position_x = player->pos.x / player->sprite->size.w;
  position_y = player->pos.y / player->sprite->size.h;
  if (check_hit_wall(map, position_x + 1, position_y))
    return ;
  set_player_position(player, player->pos.x + 1, player->pos.y);
  get_player_position(player);
}

void move_left(t_player *player, t_map *map)
{
  int position_x;
  int position_y;

  position_x = player->pos.x / player->sprite->size.w;
  position_y = player->pos.y / player->sprite->size.h;
  if (check_hit_wall(map, position_x, position_y))
    return ;
  set_player_position(player, player->pos.x - 1, player->pos.y);
  get_player_position(player);
}

// void turn_left(t_player *player)
// {
// }
