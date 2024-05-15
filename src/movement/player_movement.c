/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:56:46 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/15 17:25:18 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	handle_movement(t_player *player, t_map *map, t_direction direct)
{
	if (check_hit_wall(map, player->pos_map.x, player->pos_map.y, direct))
		return ;
	if (direct == WEST)
		player->pos_pix.x -= MOVEMENT_SPEED;
	else if (direct == EAST)
		player->pos_pix.x += MOVEMENT_SPEED;
	else if (direct == NORTH)
		player->pos_pix.y -= MOVEMENT_SPEED;
	else if (direct == SOUTH)
		player->pos_pix.y += MOVEMENT_SPEED;
	set_player_position(player, player->pos_pix.x, player->pos_pix.y);
	get_player_position(player);
}
