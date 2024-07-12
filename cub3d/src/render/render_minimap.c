/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:11:22 by angomes-          #+#    #+#             */
/*   Updated: 2024/07/10 11:20:47 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_line	get_position_to_draw(int row, int col, t_dimension size)
{
	t_line	line;

	line.start.x = col * size.w;
	line.start.y = row * size.h;
	line.end.x = line.start.x + size.w;
	line.end.y = line.start.y + size.h;
	return (line);
}

void	draw_minimap(t_minimap *minimap, t_map *map, t_dimension size)
{
	int	row;
	int	col;

	row = 0;
	while (row < size.h)
	{
		col = 0;
		while (col < map->max_cols)
		{
			if (map->mtx[row][col] == '1')
				draw_screen(minimap->img, get_position_to_draw(row, col,
						minimap->entity_size), minimap->wall_color.hex,
					draw_rect);
			else if (ft_strchr("0NSWE", map->mtx[row][col]) != NULL)
				draw_screen(minimap->img, get_position_to_draw(row, col,
						minimap->entity_size), minimap->floor_color.hex,
					draw_rect);
			col++;
		}
		row++;
	}
}

void	first_render_minimap(t_game *game)
{
	draw_minimap(game->minimap, game->map, game->map->size);
	draw_player_minimap(game->minimap, game->player);
	mlx_image_to_window(game->win->mlx, game->minimap->img, 0, 0);
}

void	re_render_minimap(t_game *game)
{
	game->minimap->img->enabled = false;
	clear_image(game->minimap->img, game->minimap->size.h,
		game->minimap->size.w);
	draw_minimap(game->minimap, game->map, game->map->size);
	draw_player_minimap(game->minimap, game->player);
	game->minimap->img->enabled = true;
}
