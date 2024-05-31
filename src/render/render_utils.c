/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 21:20:48 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/30 21:50:01 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_img(mlx_image_t *img, t_dimension size, t_type type,
		void (*func)(mlx_image_t *img, t_dimension init_dim,
			t_dimension final_dim, t_color color))
{
	t_point		p;
	void		*param;
	t_dimension	init_dim;
	t_dimension	final_dim;


	p.y = 0;
	while (p.y < size.h)
	{
		p.x = 0;
		while (p.x < size.w)
		{
			if (game->map->mtx[p.y][p.x] == '1')
			{
				init_dim.w = p.x * param->size.w;
				init_dim.h = p.y * game->minimap->walls.size.h;
				final_dim.w = init_dim.w + game->minimap->walls.size.w;
				final_dim.h = init_dim.h + game->minimap->walls.size.h;
				func(img, init_dim, final_dim, game->minimap->walls.color);
			}
			p.x++;
		}
		p.y++;
	}
}
