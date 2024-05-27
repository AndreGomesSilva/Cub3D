/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 20:20:36 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/27 15:34:25 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

mlx_image_t *put_line_screen(mlx_image_t *img, t_line *line, int sx, int sy)
{
  int	dx;
	int	dy;
	int	err;
	int	temp_err;

	dx = abs(line->end.x - line->start.x);
	dy = abs(line->end.y - line->start.y);
	err = dx - dy;

  while (line->start.x != line->end.x || line->start.y != line->end.y)
	{
		mlx_put_pixel(img, line->start.x, line->start.y, line->sprite->color.hex);
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
  return (img);
}

mlx_image_t	*draw_line(mlx_image_t *img, t_line *line)
{
	int	sx;
	int	sy;

	if (line->start.x < line->end.x)
		sx = 1;
	else
		sx = -1;
	if (line->start.y < line->end.y)
		sy = 1;
	else
		sy = -1;
	return (put_line_screen(img, line, sx, sy));
}

mlx_image_t	*create_line(t_window *win, t_line *line, int x, int y)
{
	mlx_image_t	*img;

  img = mlx_new_image(win->mlx, x, y);
  draw_line(img, line); 
	return (img);
}
