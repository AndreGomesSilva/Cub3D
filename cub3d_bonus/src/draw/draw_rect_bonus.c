/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 23:48:57 by angomes-          #+#    #+#             */
/*   Updated: 2024/07/12 15:47:41 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_rect(mlx_image_t *img, t_line line, unsigned int color)
{
	t_point	p;

	p.y = line.start.y;
	while (p.y < (line.end.y))
	{
		p.x = line.start.x;
		while (p.x < (line.end.x))
		{
			mlx_put_pixel(img, (int)p.x, (int)p.y, color);
			p.x++;
		}
		p.y++;
	}
}
