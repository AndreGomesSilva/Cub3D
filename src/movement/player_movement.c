/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:56:46 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/13 19:19:42 by angomes-         ###   ########.fr       */
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
	set_player_position(player, player->pos.x, player->pos.y - 5);
  get_player_position(player);
}
