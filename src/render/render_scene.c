/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:36:35 by iusantos          #+#    #+#             */
/*   Updated: 2024/06/19 17:41:42 by angomes-         ###   ########.fr       */
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

static void	set_raydir_step_sidedist_map(t_player *player)
{
	player->ray.map_x = (int)player->grid_pos.x;
	player->ray.map_y = (int)player->grid_pos.y;
	if (player->ray.dir.x < 0)
	{
		player->ray.step_x = -1;
		player->ray.side_dist.x = (player->grid_pos.x - player->ray.map_x)
			* player->ray.delta_dist.x;
	}
	else
	{
		player->ray.step_x = 1;
		player->ray.side_dist.x = (player->ray.map_x + 1.0 - player->grid_pos.x)
			* player->ray.delta_dist.x;
	}
	if (player->ray.dir.y < 0)
	{
		player->ray.step_y = -1;
		player->ray.side_dist.y = (player->grid_pos.y - player->ray.map_y)
			* player->ray.delta_dist.y;
	}
	else
	{
		player->ray.step_y = 1;
		player->ray.side_dist.y = (player->ray.map_y + 1.0 - player->grid_pos.y)
			* player->ray.delta_dist.y;
	}
}

static void	dda_loop(t_ray *ray, t_map *map)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
      ray->side_dist.y += ray->delta_dist.y;
      ray->map_y += ray->step_y;
      ray->side = 1;
		}
    if (map->mtx[ray->map_x][ray->map_y] == '1')
      hit = 1;
	}
}

void	render_scene(t_game *game)
{
	int	x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		set_raydir_camera_deltadist(game->player, x);
		set_raydir_step_sidedist_map(game->player);
    dda_loop(&game->player->ray, game->map);
		// printf("x: %d | camera: %f | ray_dir x: %f | ray_dir y : %f \n | ray map x: %d | ray map y: %d \n", x,
				// game->player->ray.camera_x, game->player->ray.dir.x,
				// game->player->ray.dir.y, game->player->ray.map_x, game->player->ray.map_y);

		x++;
	}
}
