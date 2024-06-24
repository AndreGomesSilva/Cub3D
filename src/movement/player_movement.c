/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:56:46 by angomes-          #+#    #+#             */
/*   Updated: 2024/06/24 15:57:27 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void move_player(t_player *player, t_map *map, t_move move)
{
	t_point	final_pos;

	if (move == UP)
	{
		final_pos.x = player->grid_pos.x + player->dir.x * MOVEMENT_SPEED;
		final_pos.y = player->grid_pos.y + player->dir.y * MOVEMENT_SPEED;
	}
	else
	{
		final_pos.x = player->grid_pos.x - player->dir.x * MOVEMENT_SPEED;
		final_pos.y = player->grid_pos.y - player->dir.y * MOVEMENT_SPEED;
	}
	if (map->mtx[(int)final_pos.y][(int)player->grid_pos.x] != '1') 
	{
		player->grid_pos.y = final_pos.y;
		player->has_moved = TRUE;
	}
	if (map->mtx[(int)player->grid_pos.y][(int)final_pos.x] != '1') 
	{
		player->grid_pos.x = final_pos.x;
		player->has_moved = TRUE;
	}
}

void handle_player_movement(t_player *player, t_map *map, t_move move)
{
  if (move == LEFT)
    player->angle = rotate_entity(player->angle, ROTATION_SPEED, LEFT);
  else if (move == RIGHT)
    player->angle = rotate_entity(player->angle, ROTATION_SPEED, RIGHT);
  else if (move == UP || move == DOWN)
	{
    // player->pix_pos =
    //     move_entity(player->pix_pos, player->angle, move, MOVEMENT_SPEED);
		move_player(player, map, move);
    	printf("Angle: %lf\n", player->angle);
    	printf("Player grid_pos: x: %f y: %f\n", player->grid_pos.x,
           player->grid_pos.y);
	}
}
