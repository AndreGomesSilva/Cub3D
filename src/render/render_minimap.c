/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:11:22 by angomes-          #+#    #+#             */
/*   Updated: 2024/06/04 21:21:20 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_vec	get_vec_grid_to_pix(t_point p, t_dimension size)
{
	t_vec	vec;

	vec.start_p.x = p.x * size.w;
	vec.start_p.y = p.y * size.h;
	vec.end_p.x = vec.start_p.x + size.w;
	vec.end_p.y = vec.start_p.y + size.h;
	return (vec);
}

void update_player_origin(t_player *player)
{
  player->origin.x = player->pix_pos.x + player->size.w / 2;
  player->origin.y = player->pix_pos.y + player->size.h / 2;
}

void	set_player_positions(t_player *player, t_point p)
{
	player->grid_pos.x = p.x;
	player->grid_pos.y = p.y;
	player->pix_pos.x = p.x * player->size.w;
	player->pix_pos.y = p.y * player->size.h;
	player->origin.x = player->pix_pos.x + player->size.w / 2;
	player->origin.y = player->pix_pos.y + player->size.h / 2;
}

void	draw_screen(t_screen *screen, t_vec vec, unsigned int color,
		void (*func)(mlx_image_t *img, t_vec vec, unsigned int color))
{
	func(screen->img, vec, color);
}

void draw_plane_line(t_screen *screen, t_player *player)
{
  t_vec plane_pos;
  t_vec plane_neg;

  plane_pos.start_p.x = player->dir_line.vec.end_p.x;
  plane_pos.start_p.y = player->dir_line.vec.end_p.y;
  plane_pos.end_p.x = player->dir_line.vec.end_p.x + player->size.w;
  plane_pos.end_p.y = player->dir_line.vec.end_p.y;
  plane_neg.start_p.x = player->dir_line.vec.end_p.x;
  plane_neg.start_p.y = player->dir_line.vec.end_p.y;
  plane_neg.end_p.x = player->dir_line.vec.end_p.x - player->size.w;
  plane_neg.end_p.y = player->dir_line.vec.end_p.y;
  player->plane_pos.vec = plane_pos;
  player->plane_neg.vec = plane_neg;
  draw_screen(screen, plane_pos, player->color.hex, draw_line);
  draw_screen(screen, plane_neg, player->color.hex, draw_line);
}

void draw_fov_line(t_screen *screen, t_player *player)
{
  t_vec fov_left;
  t_vec fov_right;

  fov_left = rotate_vector(player->dir_line.vec, -0.66);
  fov_right = rotate_vector(player->dir_line.vec, 0.66);
  player->fov.l_line.vec = fov_left;
  player->fov.r_line.vec = fov_right;
  draw_screen(screen, fov_left, player->color.hex, draw_line);
  draw_screen(screen, fov_right, player->color.hex, draw_line);
}

void	draw_dir_line(t_screen *screen, t_player *player)
{
 t_vec vec;

  update_player_origin(player);
  vec.start_p.x = player->origin.x;
  vec.start_p.y = player->origin.y;
  vec.end_p.x = player->origin.x;
  vec.end_p.y = player->origin.y - player->size.h;
  player->dir_line.vec = vec;
  player->dir_line.color.hex = get_hex_color(&player->dir_line.color, 20, 160, 180);
  draw_screen(screen, player->dir_line.vec , player->dir_line.color.hex, draw_line);
}

void	draw_player_minimap(t_screen *minimap, t_dimension size)
{
	t_player	*player;
	t_vec		vec;

  (void)size;
	player = &minimap->player;
	vec.start_p.x = player->origin.x;
	vec.start_p.y = player->origin.y;
	vec.end_p.x = vec.start_p.x + 6;
	vec.end_p.y = vec.start_p.y + 6;
	draw_screen(minimap, vec, player->color.hex, draw_circle);
  draw_dir_line(minimap, player);
  draw_plane_line(minimap, player);
  draw_fov_line(minimap, player);
}

void	cover_screen(t_screen *screen, t_dimension size, unsigned int color)
{
	t_vec	vec;

	vec.start_p.x = 0;
	vec.start_p.y = 0;
	vec.end_p.x = size.w;
	vec.end_p.y = size.h;
	draw_screen(screen, vec, color, draw_rect);
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
				draw_screen(game->minimap,
							get_vec_grid_to_pix(p, game->minimap->walls.size),
							game->minimap->walls.color.hex,
							draw_rect);
			else
				draw_screen(game->minimap,
							get_vec_grid_to_pix(p, game->minimap->walls.size),
							0xFFEEBBFF,
							draw_rect);
			if (game->minimap->player.grid_pos.x == 0 &&
				game->minimap->player.grid_pos.y == 0)
			{
				if (map->mtx[p.y][p.x] == 'P')
					set_player_positions(&game->minimap->player, p);
			}
			p.x++;
		}
		p.y++;
	}
}

int	render_minimap(t_game *game)
{
	cover_screen(game->minimap, game->minimap->size, BLACK);
	draw_minimap(game, game->map, game->map->size);
	draw_player_minimap(game->minimap, game->map->size);
	mlx_image_to_window(game->win->mlx, game->minimap->img, 0, 0);
	return (TRUE);
}
