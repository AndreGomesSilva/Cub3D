/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:11:22 by angomes-          #+#    #+#             */
/*   Updated: 2024/06/03 18:16:20 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_vec	get_player_vec(t_player *player, t_point p)
{
	t_vec	vec;

	player->grid_pos.x = p.x;
	player->grid_pos.y = p.y;
	player->pix_pos.x = p.x * player->size.w;
	player->pix_pos.y = p.y * player->size.h;
	vec.start_p.x = player->size.w * p.x;
	vec.start_p.y = player->size.h * p.y;
	vec.end_p.x = vec.start_p.x + player->size.w;
	vec.end_p.y = vec.start_p.y + player->size.h;
	return (vec);
}

static t_vec	get_wall_vec(t_walls *wall, t_point p)
{
	t_vec	vec;

	vec.start_p.x = wall->size.w * p.x;
	vec.start_p.y = wall->size.h * p.y;
	vec.end_p.x = vec.start_p.x + wall->size.w;
	vec.end_p.y = vec.start_p.y + wall->size.h;
	return (vec);
}

void	draw_screen(t_screen *screen, t_vec vec, unsigned int color,
		void (*func)(mlx_image_t *img, t_vec vec, unsigned int color))
{
	func(screen->img, vec, color);
}

void	draw_player_minimap(t_screen *minimap, t_dimension size)
{
	t_player	*player;
  t_vec   vec;


	player = &minimap->player;
  vec.start_p.x = player->pix_pos.x;
  vec.start_p.y = player->pix_pos.y;
  vec.end_p.x = vec.start_p.x + size.w;
  vec.end_p.y = vec.start_p.y + size.h;
  draw_screen(minimap, vec, player->color.hex, draw_circle);
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
			if (map->mtx[p.y][p.x] == '1')
				draw_screen(game->minimap, get_wall_vec(&game->minimap->walls,
							p), game->minimap->walls.color.hex, draw_rect);
			else
				draw_screen(game->minimap,
							get_wall_vec(&game->minimap->walls, p),
							0xFFEEBBFF,
							draw_rect);
			if (game->minimap->player.grid_pos.x == 0
				&& game->minimap->player.grid_pos.y == 0)
			{
				if (map->mtx[p.y][p.x] == 'P')
					get_player_vec(&game->minimap->player, p);
			}
			p.x++;
		}
		p.y++;
	}
}

int	render_minimap(t_game *game)
{
	draw_minimap(game, game->map, game->map->size);
	draw_player_minimap(game->minimap, game->map->size);
	mlx_image_to_window(game->win->mlx, game->minimap->img, 0, 0);
	return (TRUE);
}
