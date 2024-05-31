/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:24:08 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/31 19:01:14 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void draw_circle(mlx_image_t *img, t_vec vec, t_color color) {
    t_point p;
    int radius_x = (vec.end_p.x - vec.start_p.x) / 2; // Radius along x-axis
    int radius_y = (vec.end_p.y - vec.start_p.y) / 2; // Radius along y-axis
    int center_x = vec.start_p.x + radius_x; // Center x-coordinate
    int center_y = vec.start_p.y + radius_y; // Center y-coordinate

    p.y = vec.start_p.y;
    while (p.y < vec.end_p.y) {
        p.x = vec.start_p.x;
        while (p.x < vec.end_p.x) {
            // Calculate the squared distance from the center
            int dist_x = p.x - center_x;
            int dist_y = p.y - center_y;
            if ((dist_x * dist_x + dist_y * dist_y) < (radius_x * radius_x)) {
                mlx_put_pixel(img, p.x, p.y, color.hex);
            }
            p.x++;
        }
        p.y++;
    }
}

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
