/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:56:46 by angomes-          #+#    #+#             */
/*   Updated: 2024/06/10 21:50:07 by angomes-         ###   ########.fr       */
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
	player->is_moving = TRUE;
	printf("%f\n", player->angle);
	if (direct == WEST)
		rotate_player(player, MOVEMENT_SPEED, WEST);
	else if (direct == EAST)
		rotate_player(player, MOVEMENT_SPEED, EAST);
	else if (direct == NORTH)
	{
		if (player->angle > 0 && player->angle < 90)
		{
			player->pix_pos.y -= sin(degrees_to_radians(player->angle))
				* MOVEMENT_SPEED;
			player->pix_pos.x += cos(degrees_to_radians(player->angle))
				* MOVEMENT_SPEED;
		}
		else if (player->angle > 90 && player->angle < 180)
		{
			player->pix_pos.y += sin(degrees_to_radians(player->angle))
				* MOVEMENT_SPEED;
			player->pix_pos.x += cos(degrees_to_radians(player->angle))
				* MOVEMENT_SPEED;
		}
		else if (player->angle > 180 && player->angle < 270)
		{
			player->pix_pos.y += sin(degrees_to_radians(player->angle))
				* MOVEMENT_SPEED;
			player->pix_pos.x -= cos(degrees_to_radians(player->angle))
				* MOVEMENT_SPEED;
		}
		else if (player->angle > 270 && player->angle < 360)
		{
			player->pix_pos.y -= sin(degrees_to_radians(player->angle))
				* MOVEMENT_SPEED;
			player->pix_pos.x -= cos(degrees_to_radians(player->angle))
				* MOVEMENT_SPEED;
		}
		else if (player->angle == 0)
		{
			player->pix_pos.y -= MOVEMENT_SPEED;
		}
		else if (player->angle == 90)
		{
			player->pix_pos.x += MOVEMENT_SPEED;
		}
		else if (player->angle == 180)
		{
			player->pix_pos.y -= MOVEMENT_SPEED;
		}
		else if (player->angle == 270)
		{
			player->pix_pos.x += MOVEMENT_SPEED;
		}
	}
	else if (direct == SOUTH)
		player->pix_pos.y += MOVEMENT_SPEED;
	// set_player_position(player, player->pos_pix.x, player->pos_pix.y);
	// get_player_position(player);
}
