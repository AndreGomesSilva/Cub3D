/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player_minimap.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:00:55 by angomes-          #+#    #+#             */
/*   Updated: 2024/06/14 11:27:28 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_plane_line(t_screen *screen, t_player *player)
{
	t_line	plane_pos;
	t_line	plane_neg;

	plane_pos.start.x = player->dir_line.end.x;
	plane_pos.start.y = player->dir_line.end.y;
	plane_pos.end.x = player->dir_line.end.x;
	plane_pos.end.y = player->dir_line.end.y - player->size.h;
	plane_neg.start.x = player->dir_line.end.x;
	plane_neg.start.y = player->dir_line.end.y;
	plane_neg.end.x = player->dir_line.end.x;
	plane_neg.end.y = player->dir_line.end.y - player->size.h;
	player->plane_pos = plane_pos;
	player->plane_neg = plane_neg;
	player->plane_pos = rotate_line(player->plane_pos, 90);
	player->plane_neg = rotate_line(player->plane_neg, -90);
	draw_screen(screen, player->plane_pos, player->color.hex, draw_line);
	draw_screen(screen, player->plane_neg, player->color.hex, draw_line);
}

void	draw_fov_line(t_screen *screen, t_player *player)
{
	t_line	fov_left;
	t_line	fov_right;

	fov_left.start.x = player->origin.x;
	fov_left.start.y = player->origin.y;
	fov_right.start.x = player->origin.x;
	fov_right.start.y = player->origin.y;
	if (player->angle == 0)
	{
		fov_left.end.x = player->origin.x;
		fov_left.end.y = player->origin.y - player->size.h - 50;
		fov_right.end.x = player->origin.x;
		fov_right.end.y = player->origin.y - player->size.h - 50;
	}
	fov_left = rotate_line(fov_left, -(FOV / 2));
	fov_right = rotate_line(fov_right, FOV / 2);
	player->fov.l_line = fov_left;
	player->fov.r_line = fov_right;
	draw_screen(screen, fov_left, player->color.hex, draw_line);
	draw_screen(screen, fov_right, player->color.hex, draw_line);
}

void	draw_dir_line(t_screen *screen, t_player *player)
{
	t_line	line;

	update_player_origin(player);
	line.start.x = player->origin.x;
	line.start.y = player->origin.y;
	line.end.x = player->origin.x;
	line.end.y = player->origin.y - 10;
	player->dir_line = line;
	player->dir_line.color.hex = get_hex_color(&player->dir_line.color, 20, 160,
			180);
	player->dir_line = rotate_line(player->dir_line, player->angle);
	draw_screen(screen, player->dir_line, player->dir_line.color.hex,
		draw_line);
}

void	draw_player_minimap(t_screen *minimap)
{
	t_player	*player;
	t_line		line;

	player = &minimap->player;
	line.start.x = player->origin.x;
	line.start.y = player->origin.y;
	line.end.x = line.start.x + 7;
	line.end.y = line.start.y + 7;
	draw_screen(minimap, line, player->color.hex, draw_circle);
	draw_dir_line(minimap, player);
	// draw_plane_line(minimap, player);
	draw_fov_line(minimap, player);
}
