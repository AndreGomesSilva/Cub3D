/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:11:22 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/31 18:32:36 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static t_vec	get_wall_vec(t_walls *wall, t_point p)
{
	t_vec	vec;

	vec.start_p.x = wall->size.w * p.x;
	vec.start_p.y = wall->size.h * p.y;
	vec.end_p.x = vec.start_p.x + wall->size.w;
	vec.end_p.y = vec.start_p.y + wall->size.h;
	return (vec);
}

void	draw_screen(t_screen *screen, t_vec vec, t_color color,
		void (*func)(mlx_image_t *img, t_vec vec, t_color color))
{
	func(screen->img, vec, color);
}

void	draw_minimap(t_game *game, t_map *map, t_dimension size)
{
	t_point	p;
  t_vec vec;

	p.y = 0;
	while (p.y < size.h)
	{
		p.x = 0;
		while (p.x < size.w)
		{
			if (map->mtx[p.y][p.x] == '1')
			{
				vec = get_wall_vec(&game->minimap->walls, p);
				draw_screen(game->minimap, vec, game->minimap->walls.color, draw_circle);
			}
			p.x++;
		}
		p.y++;
	}
}

int render_minimap(t_game *game)
{
  draw_minimap(game, game->map, game->map->size);
  mlx_image_to_window(game->win->mlx, game->minimap->img, 0, 0);
  return (TRUE);
}
