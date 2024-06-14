/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:56:46 by angomes-          #+#    #+#             */
/*   Updated: 2024/06/13 21:52:38 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_cardinal	get_cardinal(double angle)
{
	if (angle == 270)
		return (WEST);
	else if (angle == 180)
		return (SOUTH);
	else if (angle == 90)
		return (EAST);
	else if (angle > 0 && angle < 90)
		return (NORTHEAST);
	else if (angle > 90 && angle < 180)
		return (SOUTHEAST);
	else if (angle > 180 && angle < 270)
		return (SOUTHWEST);
	else if (angle > 270 && angle < 360)
		return (NORTHWEST);
	return (NORTH);
}

t_point	calculate_movement(t_point pos, double angle, t_direction dir)
{
	t_point		new_pos;
	double		cosent;
	double		sinent;
	t_cardinal	card;

	cosent = cos(degrees_to_radians(angle));
	sinent = sin(degrees_to_radians(angle));
	card = get_cardinal(angle);
	if (cosent < 0)
		cosent *= -1;
	if (sinent < 0)
		sinent *= -1;
	if ((dir == UP && card == NORTH) || (dir == DOWN && card == SOUTH))
		pos.y -= SPEED;
	else if ((dir == UP && card == NORTHEAST) ||
				(dir == DOWN && card == SOUTHEAST))
	{
		pos.y -= SPEED * cosent;
		pos.x += SPEED * sinent;
	}
	else if ((dir == UP && card == EAST) || (dir == DOWN && card == WEST))
		pos.x += SPEED;
	else if ((dir == UP && card == NORTHWEST) ||
				(dir == DOWN && card == SOUTHWEST))
	{
		pos.y += SPEED * cosent;
		pos.x += SPEED * sinent;
	}
	else if ((dir == UP && card == SOUTH) || (dir == DOWN && card == NORTH))
		pos.y += SPEED;
	else if ((dir == UP && card == SOUTHEAST) ||
				(dir == DOWN && card == NORTHEAST))
	{
		pos.y += SPEED * cosent;
		pos.x -= SPEED * sinent;
	}
	else if ((dir == UP && card == WEST) || (dir == DOWN && card == EAST))
		pos.x -= SPEED;
	else if ((dir == UP && card == SOUTHWEST) ||
				(dir == DOWN && card == NORTHWEST))
	{
		pos.y -= SPEED * cosent;
		pos.x -= SPEED * sinent;
	}
	else if ((dir == UP && card == NORTH) || (dir == DOWN && card == SOUTH))
		pos.y -= SPEED;
	new_pos = pos;
	return (new_pos);
}
//
// void angle_movement(t_player *player, t_direction direct) {
//   if (player->angle == 0)
//     player->pix_pos.y -= SPEED;
//   else if (player->angle > 0 && player->angle < 90) {
//     if (direct == UP)
//       player->pix_pos =
//           calculate_movement(player->pix_pos, player->angle, UP, 0);
//     else if (direct == DOWN)
//       player->pix_pos =
//           calculate_movement(player->pix_pos, player->angle, DOWN, 1);
//     player->pix_pos.y -= SPEED * cos(degrees_to_radians(player->angle));
//     player->pix_pos.x += SPEED * sin(degrees_to_radians(player->angle));
//   } else if (player->angle == 90) {
//     player->pix_pos.x += SPEED;
//   } else if (player->angle > 90 && player->angle < 180) {
//     player->pix_pos.y += -SPEED * cos(degrees_to_radians(player->angle));
//     player->pix_pos.x += SPEED * sin(degrees_to_radians(player->angle));
//   } else if (player->angle == 180) {
//     player->pix_pos.y += SPEED;
//   } else if (player->angle > 180 && player->angle < 270) {
//     player->pix_pos.y += -SPEED * cos(degrees_to_radians(player->angle));
//     player->pix_pos.x -= -SPEED * sin(degrees_to_radians(player->angle));
//   } else if (player->angle == 270) {
//     player->pix_pos.x -= SPEED;
//   } else if (player->angle > 270 && player->angle < 360) {
//     player->pix_pos.y -= SPEED * cos(degrees_to_radians(player->angle));
//     player->pix_pos.x -= -SPEED * sin(degrees_to_radians(player->angle));
//   } else if (player->angle == 360) {
//     player->pix_pos.y -= SPEED;
//   }
// }

void	handle_movement(t_player *player, t_direction direct)
{
	player->is_moving = TRUE;
	printf("player angle: %d\n", (int)player->angle);
	if (direct == LEFT)
		rotate_player(player, SPEED, LEFT);
	else if (direct == RIGHT)
		rotate_player(player, SPEED, RIGHT);
	else if (direct == UP || direct == DOWN)
		player->pix_pos =
			calculate_movement(player->pix_pos, player->angle, direct);
	// else if (direct == UP) {
	//   if (player->angle == 0)
	//     player->pix_pos.y -= SPEED;
	//   else if (player->angle > 0 && player->angle < 90) {
	//     player->pix_pos.y -= SPEED * cos(degrees_to_radians(player->angle));
	//     player->pix_pos.x += SPEED * sin(degrees_to_radians(player->angle));
	//   } else if (player->angle == 90) {
	//     player->pix_pos.x += SPEED;
	//   } else if (player->angle > 90 && player->angle < 180) {
	//     player->pix_pos.y += -SPEED * cos(degrees_to_radians(player->angle));
	//     player->pix_pos.x += SPEED * sin(degrees_to_radians(player->angle));
	//   } else if (player->angle == 180) {
	//     player->pix_pos.y += SPEED;
	//   } else if (player->angle > 180 && player->angle < 270) {
	//     player->pix_pos.y += -SPEED * cos(degrees_to_radians(player->angle));
	//     player->pix_pos.x -= -SPEED * sin(degrees_to_radians(player->angle));
	//   } else if (player->angle == 270) {
	//     player->pix_pos.x -= SPEED;
	//   } else if (player->angle > 270 && player->angle < 360) {
	//     player->pix_pos.y -= SPEED * cos(degrees_to_radians(player->angle));
	//     player->pix_pos.x -= -SPEED * sin(degrees_to_radians(player->angle));
	//   } else if (player->angle == 360) {
	//     player->pix_pos.y -= SPEED;
	//   }
	// } else if (direct == DOWN) {
	//   if (player->angle == 0)
	//     player->pix_pos.y += SPEED;
	//   else if (player->angle > 0 && player->angle < 90) {
	//     player->pix_pos.y += SPEED * cos(degrees_to_radians(player->angle));
	//     player->pix_pos.x -= SPEED * sin(degrees_to_radians(player->angle));
	//   } else if (player->angle == 90) {
	//     player->pix_pos.x -= SPEED;
	//   } else if (player->angle > 90 && player->angle < 180) {
	//     player->pix_pos.y -= -SPEED * cos(degrees_to_radians(player->angle));
	//     player->pix_pos.x -= SPEED * sin(degrees_to_radians(player->angle));
	//   } else if (player->angle == 180) {
	//     player->pix_pos.y -= SPEED;
	//   } else if (player->angle > 180 && player->angle < 270) {
	//     player->pix_pos.y -= -SPEED * cos(degrees_to_radians(player->angle));
	//     player->pix_pos.x += -SPEED * sin(degrees_to_radians(player->angle));
	//   } else if (player->angle == 270) {
	//     player->pix_pos.x += SPEED;
	//   } else if (player->angle > 270 && player->angle < 360) {
	//     player->pix_pos.y += SPEED * cos(degrees_to_radians(player->angle));
	//     player->pix_pos.x += -SPEED * sin(degrees_to_radians(player->angle));
	//   } else if (player->angle == 360) {
	//     player->pix_pos.y += SPEED;
	//   }
	// }
}
