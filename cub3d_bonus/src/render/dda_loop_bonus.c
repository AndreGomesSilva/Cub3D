/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_loop_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 11:38:24 by angomes-          #+#    #+#             */
/*   Updated: 2024/07/12 15:50:12 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	update_ray_x(t_ray *ray)
{
	ray->side_dist.x += ray->delta_dist.x;
	ray->map.x += ray->step.x;
	if (ray->dir.x < 0)
		ray->side_wall = WEST;
	else
		ray->side_wall = EAST;
}

static void	update_ray_y(t_ray *ray)
{
	ray->side_dist.y += ray->delta_dist.y;
	ray->map.y += ray->step.y;
	if (ray->dir.y < 0)
		ray->side_wall = NORTH;
	else
		ray->side_wall = SOUTH;
}

void	dda_loop(t_ray *ray, t_map *map)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->side_dist.x < ray->side_dist.y)
			update_ray_x(ray);
		else
			update_ray_y(ray);
		if (map->mtx[(int)ray->map.y][(int)ray->map.x] == '1')
			hit = 1;
	}
}
