/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 20:20:36 by angomes-          #+#    #+#             */
/*   Updated: 2024/06/13 17:22:58 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	put_line_screen(mlx_image_t *img, t_line *line, int sx, int sy)
{
	int	dx;
	int	dy;
	int	err;
	int	temp_err;

	dx = abs((int)round(line->end.x - line->start.x));
	dy = abs((int)round(line->end.y - line->start.y));
	err = dx - dy;
	while ((int)line->start.x < MIN_WIDTH && (int)line->start.y < MIN_HEIGHT &&
			(line->start.x != line->end.x || line->start.y != line->end.y))
	{
		mlx_put_pixel(img, (int)line->start.x, (int)line->start.y,
				line->color.hex);
		temp_err = 2 * err;
		if (temp_err > -dy)
		{
			err -= dy;
			line->start.x += sx;
		}
		if (temp_err < dx)
		{
			err += dx;
			line->start.y += sy;
		}
	}
	mlx_put_pixel(img, line->start.x, line->start.y, line->color.hex);
}

void	draw_line(mlx_image_t *img, t_line line, unsigned int color)
{
	t_point	s;

	line.color.hex = color;
	if (line.start.x < line.end.x)
		s.x = 1;
	else
		s.x = -1;
	if (line.start.y < line.end.y)
		s.y = 1;
	else
		s.y = -1;
	put_line_screen(img, &line, s.x, s.y);
}
