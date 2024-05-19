/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 20:20:36 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/18 14:09:32 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

mlx_image_t	*draw_line(mlx_image_t *img, int x0, int y0, int x1, int y1,
		unsigned int color)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
  int err;
  int temp_err;

	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
  err = dx - dy;
  if (x0 < x1)
    sx = 1;
  else
    sx = -1;
  if (y0 < y1)
    sy = 1;
  else
    sy = -1;

  while(x0 != x1 || y0 != y1)
  {
    mlx_put_pixel(img, x0, y0, color);
    temp_err = 2 * err;
    if (temp_err > -dy)
    {
      err -= dy;
      x0 += sx;
    }
    if (temp_err < dx)
    {
      err += dx;
      y0 += sy;
    }
  }
  mlx_put_pixel(img, x1, y1, color);
	return (img);
}

mlx_image_t	*create_line(t_window *win, int w, int h, int x0, int y0, int x1,
		int y1, unsigned int color)
{
	mlx_image_t	*new_img;
	mlx_image_t	*img;

	img = mlx_new_image(win->mlx, w, h);
	new_img = draw_line(img, x0, y0, x1, y1, color);
	return (new_img);
}
