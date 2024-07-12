/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:36:35 by iusantos          #+#    #+#             */
/*   Updated: 2024/07/10 11:16:23 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_raydir_camera_deltadist(t_player *player, int x)
{
	player->ray.camera_x = 2 * x / (double)WIN_WIDTH - 1;
	player->ray.dir.x = player->dir.x + player->plane.x * player->ray.camera_x;
	player->ray.dir.y = player->dir.y + player->plane.y * player->ray.camera_x;
	if (player->ray.dir.x == 0)
		player->ray.delta_dist.x = 1e30;
	else
		player->ray.delta_dist.x = abs_double(1 / player->ray.dir.x);
	if (player->ray.dir.y == 0)
		player->ray.delta_dist.y = 1e30;
	else
		player->ray.delta_dist.y = abs_double(1 / player->ray.dir.y);
}

static void	set_raydir_step_sidedist_map(t_ray *ray, t_point player_pos)
{
	ray->map.x = (int)player_pos.x;
	ray->map.y = (int)player_pos.y;
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (player_pos.x - ray->map.x) * ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (ray->map.x + 1.0 - player_pos.x)
			* ray->delta_dist.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (player_pos.y - ray->map.y) * ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (ray->map.y + 1.0 - player_pos.y)
			* ray->delta_dist.y;
	}
}

void	first_render_scene(t_game *game)
{
	int	x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		set_raydir_camera_deltadist(game->player, x);
		set_raydir_step_sidedist_map(&game->player->ray,
			game->player->grid_pos);
		dda_loop(&game->player->ray, game->map);
		create_vertical_line(game, x);
		x++;
	}
	mlx_image_to_window(game->win->mlx, game->main_img, 0, 0);
}

void	re_render_scene(t_game *game)
{	
	int	x;

	game->main_img->enabled = false;
	clear_image(game->main_img, WIN_HEIGHT, WIN_WIDTH);
	x = 0;
	while (x < WIN_WIDTH)
	{
		set_raydir_camera_deltadist(game->player, x);
		set_raydir_step_sidedist_map(&game->player->ray,
			game->player->grid_pos);
		dda_loop(&game->player->ray, game->map);
		create_vertical_line(game, x);
		x++;
	}
	game->main_img->enabled = true;
}
