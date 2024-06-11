/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:11:22 by angomes-          #+#    #+#             */
/*   Updated: 2024/06/10 20:45:19 by angomes-         ###   ########.fr       */
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
	player->origin.x = player->pix_pos.x + (double)player->size.w / 2;
	player->origin.y = player->pix_pos.y + (double)player->size.h / 2;
}

void	draw_screen(t_screen *screen, t_line line, unsigned int color,
		void (*func)(mlx_image_t *img, t_line line, unsigned int color))
{
	func(screen->img, line, color);
}

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
	if (player->dir == NORTH)
	{
		fov_left.end.x = player->origin.x;
		fov_left.end.y = player->origin.y - player->size.h - 50;
		fov_right.end.x = player->origin.x;
		fov_right.end.y = player->origin.y - player->size.h - 50;
	}
	fov_left = rotate_line(fov_left, -(FOV_ANGLE / 2));
	fov_right = rotate_line(fov_right, FOV_ANGLE / 2);
	player->fov.l_line = fov_left;
	player->fov.r_line = fov_right;
	// int j;
	// j = FOV_ANGLE;
	// while (j > 0) {
	//   fov_left = rotate_line(fov_left, 1);
	//   fov_right = rotate_line(fov_right, -1);
	//   draw_screen(screen, fov_left, player->color.hex, draw_line);
	//   draw_screen(screen, fov_right, player->color.hex, draw_line);
	//   j--;
	// }
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
	line.end.y = player->origin.y - player->size.h;
	player->dir_line = line;
	player->dir_line.color.hex =
		get_hex_color(&player->dir_line.color, 20, 160, 180);
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
	// draw_fov_line(minimap, player);
}

void update_dir_line(t_screen *minimap, t_player *player)
{
  player->dir_line.start.x = player->origin.x;
  player->dir_line.start.y = player->origin.y;
  player->dir_line.end.x = player->origin.x;
  player->dir_line.end.y = player->origin.y - player->size.h;
  player->dir_line = rotate_line(player->dir_line, player->angle);
  draw_screen(minimap, player->dir_line, player->dir_line.color.hex, draw_line);
}

void update_player_minimap(t_screen *minimap)
{
  t_line line;

  update_player_origin(&minimap->player);
  line.start.x = minimap->player.origin.x;
  line.start.y = minimap->player.origin.y;
  line.end.x = line.start.x + 7;
  line.end.y = line.start.y + 7;
  draw_screen(minimap, line, minimap->player.color.hex, draw_circle);
  update_dir_line(minimap, &minimap->player);
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

void update_minimap(t_game *game)
{
	cover_screen(game->minimap, game->minimap->size, BLACK);
	draw_minimap(game, game->map, game->map->size);
  update_player_minimap(game->minimap);
	mlx_image_to_window(game->win->mlx, game->minimap->img, 0, 0);
	game->minimap->player.is_moving = FALSE;
}

void	render_minimap(t_game *game)
{
	draw_minimap(game, game->map, game->map->size);
	draw_player_minimap(game->minimap);
	mlx_image_to_window(game->win->mlx, game->minimap->img, 0, 0);
}
