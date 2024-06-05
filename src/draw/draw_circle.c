/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:24:08 by angomes-          #+#    #+#             */
/*   Updated: 2024/06/04 19:07:34 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	drawHorizontalLine(mlx_image_t *img, int x1, int x2, int y,
		unsigned int color)
{
	for (int x = x1; x <= x2; x++)
	{
		mlx_put_pixel(img, x, y, color);
	}
}

// Function to plot and fill the points in all eight octants
void	fillCirclePoints(mlx_image_t *img, int xc, int yc, int x, int y,
		unsigned int color)
{
	drawHorizontalLine(img, xc - x, xc + x, yc + y, color);
	drawHorizontalLine(img, xc - x, xc + x, yc - y, color);
	drawHorizontalLine(img, xc - y, xc + y, yc + x, color);
	drawHorizontalLine(img, xc - y, xc + y, yc - x, color);
}

void	draw_circle(mlx_image_t *img, t_vec vec, unsigned int color)
{
	int	r;
	int	x;
	int	y;
	int	d;

	int radius_x = (vec.end_p.x - vec.start_p.x) / 2; // Radius along x-axis
	int radius_y = (vec.end_p.y - vec.start_p.y) / 2; // Radius along y-axis
	int center_x = vec.start_p.x;          // Center x-coordinate
	int center_y = vec.start_p.y;          // Center y-coordinate
	// Use the smaller radius for the circle (to maintain the aspect ratio)
	r = (radius_x < radius_y) ? radius_x : radius_y;
	x = 0;
	y = r;
	d = 3 - 2 * r;
	while (y >= x)
	{
		// Plot and fill the points in all eight octants
		fillCirclePoints(img, center_x, center_y, x, y, color);
		x++;
		if (d > 0)
		{
			y--;
			d = d + 4 * (x - y) + 10;
		}
		else
		{
			d = d + 4 * x + 6;
		}
	}
}

// void draw_circle(mlx_image_t *img, t_vec vec, unsigned int color) {
//     t_point p;
//     int radius_x = (vec.end_p.x - vec.start_p.x) / 2; // Radius along x-axis
//     int radius_y = (vec.end_p.y - vec.start_p.y) / 2; // Radius along y-axis
//     int center_x = vec.start_p.x + radius_x; // Center x-coordinate
//     int center_y = vec.start_p.y + radius_y; // Center y-coordinate
//
//     p.y = vec.start_p.y;
//     while (p.y < vec.end_p.y) {
//         p.x = vec.start_p.x;
//         while (p.x < vec.end_p.x) {
//             // Calculate the squared distance from the center
//             int dist_x = p.x - center_x;
//             int dist_y = p.y - center_y;
//             if ((dist_x * dist_x + dist_y * dist_y) < (radius_x
//                 mlx_put_pixel(img, p.x, p.y, color);
//             }
//             p.x++;
//         }
//         p.y++;
//     }
// }
//
// void	draw_circle(mlx_image_t *img, t_vec vec, t_color color)
// {
// 	t_point	p;
//
// 	p.y = vec.start_p.y;
// 	while (p.y < vec.end_p.y)
// 	{
// 		p.x = vec.start_p.x;
// 		while (p.x < vec.end_p.x)
// 		{
// 			if (((p.x - vec.end_p.x / 2) * (p.x - vec.end_p.x / 2)) + ((p.y
// 						- vec.end_p.y / 2) * (p.y - vec.end_p.y
// 						/ 2)) < (vec.end_p.x / 2) * (vec.end_p.x / 2))
// 				mlx_put_pixel(img, p.x, p.y, color.hex);
// 			p.x++;
// 		}
// 		p.y++;
// 	}
// }
