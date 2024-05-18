/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 20:20:36 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/17 22:00:51 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

mlx_image_t	*draw_line(mlx_image_t *img, int x0, int y0, int x1, int y1,
		unsigned int color)
{
	int	dx;
	int	dy;
	int	x;
	int	y;
	int	p;

	dx = x1 - x0;
	dy = y1 - y0;
	x = x0;
	y = y0;
	p = 2 * dy - dx;
	while (x < x1)
	{
		if (p >= 0)
		{
			mlx_put_pixel(img, x, y, color);
			y = y + 1;
			p = p + 2 * dy - 2 * dx;
		}
		else
		{
      mlx_put_pixel(img, x, y, color);
      p = p + 2 * dy;
		}
		x = x + 1;
	}
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
