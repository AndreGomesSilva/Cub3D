/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 20:20:36 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/22 20:35:38 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// mlx_image_t	*draw_line(mlx_image_t *img, int x0, int y0, int x1, int y1,
// 		unsigned int color)
// {
// 	int	dx;
// 	int	dy;
// 	int	x;
// 	int	y;
// 	int	p;
//
// 	dx = x1 - x0;
// 	dy = y1 - y0;
// 	x = x0;
// 	y = y0;
// 	p = 2 * dy - dx;
// 	while (x < x1)
// 	{
// 		if (p >= 0)
// 		{
// 			mlx_put_pixel(img, x, y, color);
// 			y = y + 1;
// 			p = p + 2 * dy - 2 * dx;
// 		}
// 		else
// 		{
//       mlx_put_pixel(img, x, y, color);
//       p = p + 2 * dy;
// 		}
// 		x = x + 1;
// 	}
// 	return (img);
// }

// mlx_image_t *draw_line(mlx_image_t *img, t_line *line) {
//     int dx, dy, sx, sy, err, e2;
//     int x0 = line->start.x;
//     int y0 = line->start.y;
//     int x1 = line->end.x;
//     int y1 = line->end.y;
//     unsigned int color = line->sprite->color.hex;
//
//     dx = abs(x1 - x0);
//     dy = abs(y1 - y0);
//     sx = x0 < x1 ? 1 : -1;
//     sy = y0 < y1 ? 1 : -1;
//     err = (dx > dy ? dx : -dy) / 2;
//
//     while (1) {
//         mlx_put_pixel(img, x0, y0, color);
//         if (x0 == x1 && y0 == y1) break;
//         e2 = err;
//         if (e2 > -dx) {
//             err -= dy;
//             x0 += sx;
//         }
//         if (e2 < dy) {
//             err += dx;
//             y0 += sy;
//         }
//     }
//     return img;
// } 

mlx_image_t	*draw_line(mlx_image_t *img, t_line *line)
{
  int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	temp_err;

	dx = abs(line->end.x - line->start.x);
	dy = abs(line->end.y - line->start.y);
	err = dx - dy;
	if (line->start.x < line->end.x)
		sx = 1;
	else
		sx = -1;
	if (line->start.y < line->end.y)
		sy = 1;
	else
		sy = -1;
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
	// mlx_put_pixel(img, line->end.x, line->end.y, line->sprite->color.hex);
	return (img);
}

mlx_image_t	*create_line(t_window *win, t_line *line)
{
	mlx_image_t	*img;

  img = mlx_new_image(win->mlx, 50, 50);
  draw_line(img, line); 
	// draw_line(img, line);
	return (img);
}
