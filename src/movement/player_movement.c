/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:56:46 by angomes-          #+#    #+#             */
/*   Updated: 2024/06/11 22:02:43 by angomes-         ###   ########.fr       */
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
	printf("P.Angle %f\n", player->angle);
	if (direct == LEFT)
		rotate_player(player, SPEED, LEFT);
	else if (direct == RIGHT)
		rotate_player(player, SPEED, RIGHT);
	else if (direct == UP)
	{
		if (player->angle == 0)
			player->pix_pos.y -= SPEED;
		else if (player->angle > 0 && player->angle < 45)
		{
      printf("sin %f", SPEED * sin(player->angle));
			player->pix_pos.y -= SPEED * sin(player->angle);
			printf("Pos.y %f\n", player->pix_pos.y);
      printf("sin %f", SPEED * cos(player->angle));
			player->pix_pos.x += SPEED * cos(player->angle);
			printf("Pos.x %f\n", player->pix_pos.x);
		}
		//	else if (direct == DOWN)
		//  {
		//    if (player->dir_line.angle == 360)
		//      player->dir_line.angle = 0;
		//    else
		//      player->dir_line.angle += MOVEMENT_SPEED;
		//  }
		// set_player_position(player, player->pos_pix.x, player->pos_pix.y);
		// get_player_position(player);
	}
}
