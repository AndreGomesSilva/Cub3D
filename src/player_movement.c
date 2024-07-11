/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:56:46 by angomes-          #+#    #+#             */
/*   Updated: 2024/07/08 15:23:09 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_player_forward_backward(t_player *player, t_map *map, t_move move)
{
	t_point	final_pos;

	if (move == FORWARD)
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

void	move_player_left_right(t_player *player, t_map *map, t_move move)
{
	t_point	final_pos;

	if (move == RIGHT)
	{
		final_pos.x = player->grid_pos.x + player->plane.x * MOVEMENT_SPEED;
		final_pos.y = player->grid_pos.y + player->plane.y * MOVEMENT_SPEED;
	}
	else
	{
		final_pos.x = player->grid_pos.x - player->plane.x * MOVEMENT_SPEED;
		final_pos.y = player->grid_pos.y - player->plane.y * MOVEMENT_SPEED;
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

void	rotate_player(t_player *player, t_move move)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rotation_angle;

	old_dir_x = player->dir.x;
	old_plane_x = player->plane.x;
	if (move == A_LEFT)
		rotation_angle = -ROTATION_SPEED;
	else if (move == A_RIGHT)
		rotation_angle = ROTATION_SPEED;
	else if (move == M_LEFT)
		rotation_angle = -MOUSE_ROTATION_SPEED;
	else
		rotation_angle = MOUSE_ROTATION_SPEED;
	player->dir.x = player->dir.x * cos(rotation_angle) - player->dir.y
		* sin(rotation_angle);
	player->dir.y = old_dir_x * sin(rotation_angle) + player->dir.y
		* cos(rotation_angle);
	player->plane.x = player->plane.x * cos(rotation_angle) - player->plane.y
		* sin(rotation_angle);
	player->plane.y = old_plane_x * sin(rotation_angle) + player->plane.y
		* cos(rotation_angle);
	player->has_moved = TRUE;
}

void	handle_player_movement(t_player *player, t_map *map, t_move move)
{
	if (move == LEFT || move == RIGHT)
		move_player_left_right(player, map, move);
	else if (move == FORWARD || move == BACKWARD)
		move_player_forward_backward(player, map, move);
	else if (move == A_RIGHT || move == A_LEFT || move == M_RIGHT
		|| move == M_LEFT)
	{
		rotate_player(player, move);
		if (move == A_LEFT || move == A_RIGHT)
			player->rad_angle = rotate_minimap_player(player->rad_angle,
					ROTATION_SPEED, move);
		else
			player->rad_angle = rotate_minimap_player(player->rad_angle,
					MOUSE_ROTATION_SPEED, move);
	}
}
