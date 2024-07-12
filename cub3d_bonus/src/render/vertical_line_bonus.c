/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 11:47:40 by angomes-          #+#    #+#             */
/*   Updated: 2024/07/06 11:52:37 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	calculate_perp_wall_dist(t_ray *ray)
{
	if (ray->side_wall == WEST || ray->side_wall == EAST)
		ray->perp_wall_dist = ray->side_dist.x - ray->delta_dist.x;
	else
		ray->perp_wall_dist = ray->side_dist.y - ray->delta_dist.y;
}

void	create_vertical_line(t_game *game, int col)
{
	int	draw_start;
	int	draw_end;

	calculate_perp_wall_dist(&game->player->ray);
	game->player->ray.line_height = (int)(WIN_HEIGHT
			/ game->player->ray.perp_wall_dist);
	draw_start = WIN_HEIGHT / 2 - game->player->ray.line_height / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = WIN_HEIGHT / 2 + game->player->ray.line_height / 2;
	if (draw_end >= WIN_HEIGHT)
		draw_end = WIN_HEIGHT - 1;
	texture_pre_render(&game->player->ray, game->player->grid_pos, draw_start,
		draw_end);
	draw_v_line(game, col, draw_start, draw_end);
	ft_bzero(game->player->ray.tex.buffer, WIN_HEIGHT);
}
