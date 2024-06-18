/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:36:35 by iusantos          #+#    #+#             */
/*   Updated: 2024/06/18 18:42:03 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void set_raydir_camera_deltadist(t_player *player, int x)
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


void	render_scene(t_game *game)
{
	int	x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		set_raydir_camera_deltadist(game->player, x);
    printf("x: %d | camera: %f | ray_dir x: %f | ray_dir y : %f \n", x, game->player->ray.camera_x, game->player->ray.dir.x, game->player->ray.dir.y);
		x++;
	}
}
