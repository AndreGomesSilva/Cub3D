/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:56:46 by angomes-          #+#    #+#             */
/*   Updated: 2024/06/12 19:44:58 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include <stdio.h>

void handle_movement(t_player *player, t_direction direct) {
  player->is_moving = TRUE;
  printf("player angle: %f\n", player->angle);
  // printf("Player position x: %f, y: %f\n", player->pix_pos.x,
  // player->pix_pos.y);
  if (direct == LEFT)
    rotate_player(player, SPEED, LEFT);
  else if (direct == RIGHT)
    rotate_player(player, SPEED, RIGHT);
  else if (direct == UP) {
    if (player->angle == 0)
      player->pix_pos.y -= SPEED;
    else if (player->angle > 0 && player->angle < 90) {
      player->pix_pos.y -= SPEED * cos(degrees_to_radians(player->angle));
      player->pix_pos.x += SPEED * sin(degrees_to_radians(player->angle));
    } else if (player->angle == 90) {
      player->pix_pos.x += SPEED;
    } else if (player->angle > 90 && player->angle < 180) {
      player->pix_pos.y += -SPEED * cos(degrees_to_radians(player->angle));
      player->pix_pos.x += SPEED * sin(degrees_to_radians(player->angle));
    } else if (player->angle == 180) {
      player->pix_pos.y += SPEED;
    } else if (player->angle > 180 && player->angle < 270) {
      player->pix_pos.y += -SPEED * cos(degrees_to_radians(player->angle));
      player->pix_pos.x -= -SPEED * sin(degrees_to_radians(player->angle));
    } else if (player->angle == 270) {
      player->pix_pos.x -= SPEED;
    } else if (player->angle > 270 && player->angle < 360) {
      player->pix_pos.y -= SPEED * cos(degrees_to_radians(player->angle));
      player->pix_pos.x -= -SPEED * sin(degrees_to_radians(player->angle));
    } else if (player->angle == 360) {
      player->pix_pos.y -= SPEED;
    }
  }
}
