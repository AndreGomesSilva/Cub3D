/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:45:42 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/29 21:04:36 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	render_wall_minimap(t_minimap *minimap, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->size.h)
	{
		x = 0;
		while (x < map->size.w)
		{
			if (map->mtx[y][x] == '1')
				draw_rect_wall(minimap->img, x * minimap->walls.size.w, y * minimap->walls.size.h, &minimap->walls);
			x++;
		}
		y++;
	}
}
