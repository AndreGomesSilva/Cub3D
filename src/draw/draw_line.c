/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 20:20:36 by angomes-          #+#    #+#             */
/*   Updated: 2024/06/04 18:43:08 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	put_line_screen(mlx_image_t *img, t_line *line, int sx, int sy)
{
	int	dx;
	int	dy;
	int	err;
	int	temp_err;

	dx = abs(line->vec.end_p.x - line->vec.start_p.x);
	dy = abs(line->vec.end_p.y - line->vec.start_p.y);
	err = dx - dy;
	while (line->vec.start_p.x != line->vec.end_p.x ||
			line->vec.start_p.y != line->vec.end_p.y)
	{
		mlx_put_pixel(img, line->vec.start_p.x, line->vec.start_p.y,
				line->color.hex);
		temp_err = 2 * err;
		if (temp_err > -dy)
		{
			err -= dy;
			line->vec.start_p.x += sx;
		}
		if (temp_err < dx)
		{
			err += dx;
			line->vec.start_p.y += sy;
		}
	}
}

void	draw_line(mlx_image_t *img, t_vec vec, unsigned int color)
{
	t_point	s;
  t_line line;

  line.vec = vec;
  line.color.hex = color;
	if (vec.start_p.x < vec.end_p.x)
		s.x = 1;
	else
		s.x = -1;
	if (vec.start_p.y < vec.end_p.y)
		s.y = 1;
	else
		s.y = -1;
	put_line_screen(img, &line, s.x, s.y);
}
