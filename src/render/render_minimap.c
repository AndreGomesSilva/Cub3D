/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:11:22 by angomes-          #+#    #+#             */
/*   Updated: 2024/06/11 15:31:22 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_screen(t_screen *screen, t_line line, unsigned int color,
		void (*func)(mlx_image_t *img, t_line line, unsigned int color))
{
	func(screen->img, line, color);
}

void	draw_minimap(t_game *game, t_map *map, t_dimension size)
{
	t_point	p;

	p.y = 0;
	while (p.y < size.h)
	{
		p.x = 0;
		while (p.x < size.w)
		{
			if (map->mtx[(int)p.y][(int)p.x] == '1')
				draw_screen(game->minimap,
							get_line_grid_to_pix(p, game->minimap->walls.size),
							game->minimap->walls.color.hex,
							draw_rect);
			else
				draw_screen(game->minimap,
							get_line_grid_to_pix(p, game->minimap->walls.size),
							0xFFEEBBFF,
							draw_rect);
			if (game->minimap->player.grid_pos.x == 0 &&
				game->minimap->player.grid_pos.y == 0)
			{
				if (map->mtx[(int)p.y][(int)p.x] == 'P')
					set_player_positions(&game->minimap->player, p);
			}
			p.x++;
		}
		p.y++;
	}
}

void	render_minimap(t_game *game)
{
	draw_minimap(game, game->map, game->map->size);
	draw_player_minimap(game->minimap);
	mlx_image_to_window(game->win->mlx, game->minimap->img, 0, 0);
}
