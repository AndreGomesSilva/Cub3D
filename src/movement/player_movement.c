/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:56:46 by angomes-          #+#    #+#             */
/*   Updated: 2024/06/07 20:49:35 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// void  move_player_forward(t_map *map)
// {
//   
// }
//
void	handle_movement(t_player *player, t_direction direct)
{
	if (direct == WEST)
		player->pix_pos.x -= MOVEMENT_SPEED;
	else if (direct == EAST)
		player->pix_pos.x += MOVEMENT_SPEED;
	else if (direct == NORTH)
		player->pix_pos.y -= MOVEMENT_SPEED;
	else if (direct == SOUTH)
		player->pix_pos.y += MOVEMENT_SPEED;
	// set_player_position(player, player->pos_pix.x, player->pos_pix.y);
	// get_player_position(player);
}
