/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:56:46 by angomes-          #+#    #+#             */
/*   Updated: 2024/06/24 15:24:06 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void move_player(t_player *player, t_map *map) { player->has_moved = TRUE; }

void handle_player_movement(t_player *player, t_move move) {
  player->has_moved = TRUE;
  if (move == LEFT)
    player->angle = rotate_entity(player->angle, ROTATION_SPEED, LEFT);
  else if (move == RIGHT)
    player->angle = rotate_entity(player->angle, ROTATION_SPEED, RIGHT);
  else if (move == UP || move == DOWN) {
    player->pix_pos =
        move_entity(player->pix_pos, player->angle, move, MOVEMENT_SPEED);
    player->grid_pos =
        move_entity(player->grid_pos, player->angle, move, MOVEMENT_SPEED);
    printf("Angle: %lf\n", player->angle);
    printf("Player grid_pos: x: %f y: %f\n", player->grid_pos.x,
           player->grid_pos.y);
  }
}
