/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:05:30 by angomes-          #+#    #+#             */
/*   Updated: 2024/06/11 21:59:03 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_line	get_line_grid_to_pix(t_point p, t_dimension size)
{
	t_line	line;

	line.start.x = p.x * size.w;
	line.start.y = p.y * size.h;
	line.end.x = line.start.x + size.w;
	line.end.y = line.start.y + size.h;
	return (line);
}

void	update_player_origin(t_player *player)
{
	player->origin.x = player->pix_pos.x + (double)player->size.w / 2;
	player->origin.y = player->pix_pos.y + (double)player->size.h / 2;
}

void	set_player_positions(t_player *player, t_point p)
{
	player->grid_pos.x = p.x;
	player->grid_pos.y = p.y;
	player->pix_pos.x = p.x * player->size.w;
	player->pix_pos.y = p.y * player->size.h;
  update_player_origin(player);
}

void	cover_screen(t_screen *screen, t_dimension size, unsigned int color)
{
	t_line	line;

	line.start.x = 0;
	line.start.y = 0;
	line.end.x = size.w;
	line.end.y = size.h;
	draw_screen(screen, line, color, draw_rect);
}
