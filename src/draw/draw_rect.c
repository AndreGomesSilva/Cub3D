/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 23:48:57 by angomes-          #+#    #+#             */
/*   Updated: 2024/06/03 14:27:19 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_rect(mlx_image_t *img, t_vec vec,
		unsigned int color)
{
	t_point	p;

	p.y = vec.start_p.y;
	while (p.y < (vec.end_p.y - 1))
	{
		p.x = vec.start_p.x;
		while (p.x < (vec.end_p.x - 1))
		{
			mlx_put_pixel(img, p.x, p.y, color);
			p.x++;
		}
		p.y++;
	}
}
