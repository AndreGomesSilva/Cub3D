/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 23:48:57 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/30 18:22:41 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_rect(mlx_image_t *img, t_dimension init_dim, t_dimension final_dim,
		t_color color)
{
	t_point	p;

	p.y = init_dim.h;
	while (p.y < (final_dim.h - 1))
	{
		p.x = init_dim.w;
		while (p.x < (final_dim.w - 1))
		{
			mlx_put_pixel(img, p.x, p.y, color.hex);
			p.x++;
		}
		p.y++;
	}
}
