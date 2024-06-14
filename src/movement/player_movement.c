/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:56:46 by angomes-          #+#    #+#             */
/*   Updated: 2024/06/14 11:22:25 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	handle_player_movement(t_player *player, t_move move)
{
	player->is_moving = TRUE;
	if (move == LEFT)
		player->angle = rotate_entity(player->angle, ROTATION_SPEED, LEFT);
	else if (move == RIGHT)
		player->angle = rotate_entity(player->angle, ROTATION_SPEED, RIGHT);
	else if (move == UP || move == DOWN)
		player->pix_pos = move_entity(player->pix_pos, player->angle, move,
				MOVEMENT_SPEED);
}
