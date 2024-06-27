/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:36:35 by iusantos          #+#    #+#             */
/*   Updated: 2024/06/27 15:13:02 by iusantos         ###   ########.fr       */
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
	player->ray.map.x = (int)player->grid_pos.x;
	player->ray.map.y = (int)player->grid_pos.y;
	if (player->ray.dir.x < 0)
	{
		player->ray.step.x = -1;
		player->ray.side_dist.x = (player->grid_pos.x - player->ray.map.x)
			* player->ray.delta_dist.x;
	}
	else
	{
		player->ray.step.x = 1;
		player->ray.side_dist.x = (player->ray.map.x + 1.0 - player->grid_pos.x)
			* player->ray.delta_dist.x;
	}
	if (player->ray.dir.y < 0)
	{
		player->ray.step.y = -1;
		player->ray.side_dist.y = (player->grid_pos.y - player->ray.map.y)
			* player->ray.delta_dist.y;
	}
	else
	{
		player->ray.step.y = 1;
		player->ray.side_dist.y = (player->ray.map.y + 1.0 - player->grid_pos.y)
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
			ray->map.x += ray->step.x;
			if (ray->dir.x < 0)
				ray->side_wall = WEST;
			else
				ray->side_wall = EAST;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->map.y += ray->step.y;
			if (ray->dir.y < 0)
				ray->side_wall = NORTH;
			else
				ray->side_wall = SOUTH;
		}
		if (map->mtx[(int)ray->map.y][(int)ray->map.x] == '1')
		{
			hit = 1;
			if (ray->side_wall == NORTH)
				ray->color = RED;
			else if (ray->side_wall == SOUTH)
				ray->color = GREEN;
			else if (ray->side_wall == EAST)
				ray->color = BLUE;
			else
				ray->color = YELLOW;
		}
	}
	// printf("map hit: %c\n", map->mtx[ray->map_x][ray->map_y]);
}

static void	calculate_perp_wall_dist(t_ray *ray)
{
	if (ray->side_wall == WEST || ray->side_wall == EAST)
		ray->perp_wall_dist = ray->side_dist.x - ray->delta_dist.x;
	else
		ray->perp_wall_dist = ray->side_dist.y - ray->delta_dist.y;
}

static void	create_vertical_line(t_ray *ray, int col, t_point player_pos,
		mlx_image_t *img)
{
	int	draw_start;
	int	draw_end;

	ray->line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	draw_start = WIN_HEIGHT / 2 - ray->line_height / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = WIN_HEIGHT / 2 + ray->line_height / 2;
	if (draw_end >= WIN_HEIGHT)
		draw_end = WIN_HEIGHT - 1;
	texture_pre_render(ray, player_pos, draw_start, draw_end);
	draw_v_line(col, draw_start, draw_end, ray->tex.buffer, img);
	// ft_bzero(ray->tex.buffer, WIN_HEIGHT);
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
		calculate_perp_wall_dist(&game->player->ray);
		create_vertical_line(&game->player->ray, x, game->player->grid_pos,
				game->main_img);
		// printf("x: %d | camera: %f | ray_dir x:
									// %f | ray_dir y :					%f \n | ray map x:
									// %f | ray map y: %f \n", x,
		// 	game->player->ray.camera_x, game->player->ray.dir.x,
		// 	game->player->ray.dir.y, game->player->ray.map.x,
		// 		game->player->ray.map.y);
		x++;
	}
	mlx_image_to_window(game->win->mlx, game->main_img, 0, 0);
}
