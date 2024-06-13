/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 20:20:36 by angomes-          #+#    #+#             */
/*   Updated: 2024/06/12 20:44:02 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	put_line_screen(mlx_image_t *img, t_line *line, int sx, int sy)
{
	int	dx;
	int	dy;
	int	err;
	int	temp_err;
  t_line *temp_line;

  temp_line = line;
	dx = abs((int)(line->end.x - line->start.x));
	dy = abs((int)(line->end.y - line->start.y));
	printf("dx: %d, dy: %d\n", dx, dy);
	err = dx - dy;
	while (temp_line->start.x != temp_line->end.x ||
			temp_line->start.y != temp_line->end.y)
	{
    printf("x: %f, y: %f\n", temp_line->start.x, temp_line->start.y);
		mlx_put_pixel(img, line->start.x, temp_line->start.y, temp_line->color.hex);
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
