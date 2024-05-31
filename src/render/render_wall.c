/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:45:42 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/30 20:10:40 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	render_wall_minimap(t_minimap *minimap, t_map *map)
{
  t_point p;
  t_dimension init_dim;
  t_dimension final_dim;

  p.y = 0;
	while (p.y < map->size.h)
	{
		p.x = 0;
		while (p.x < map->size.w)
		{
			if (map->mtx[p.y][p.x] == '1')
      {
        init_dim.w = p.x * minimap->walls.size.w;
        init_dim.h = p.y * minimap->walls.size.h;
        final_dim.w = init_dim.w + minimap->walls.size.w;
        final_dim.h = init_dim.h + minimap->walls.size.h;
				draw_rect(minimap->img, init_dim, final_dim, minimap->walls.color);
      }
			p.x++;
		}
		p.y++;
	}
}
