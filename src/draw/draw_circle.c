/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:24:08 by angomes-          #+#    #+#             */
/*   Updated: 2024/06/15 21:14:41 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	drawHorizontalLine(mlx_image_t *img, int x1, int x2, int y,
		unsigned int color)
{
  int x;

  x = 0;
  while (x1 <= x2)
  {
    mlx_put_pixel(img, x, y, color);
    x1++;
  }
}

void	fillCirclePoints(mlx_image_t *img, t_point center, t_point offset,
		unsigned int color)
{
	drawHorizontalLine(img, center.x - offset.x, center.x + offset.x, center.y
			+ offset.y, color);
	drawHorizontalLine(img, center.x - offset.x, center.x + offset.x, center.y
			- offset.y, color);
	drawHorizontalLine(img, center.x - offset.y, center.x + offset.y, center.y
			+ offset.x, color);
	drawHorizontalLine(img, center.x - offset.y, center.x + offset.y, center.y
			- offset.x, color);
}

double	get_radius(t_line line)
{
	t_point	radius;
	double	result;

	radius.x = (line.end.x - line.start.x) / 2;
	radius.y = (line.end.y - line.start.y) / 2;
	if (radius.x < radius.y)
		result = radius.x;
	else
		result = radius.y;
	return (result);
}

void	draw_circle(mlx_image_t *img, t_line line, unsigned int color)
{
	double	radius;
	t_point	offset;
	double	decision;
	t_point	center;

	center.x = line.start.x;
	center.y = line.start.y;
	radius = get_radius(line);
	offset.x = 0;
	offset.y = radius;
	decision = 3 - 2 * radius;
	while (offset.y >= offset.x)
	{
		fillCirclePoints(img, center, offset, color);
		offset.x++;
		if (decision > 0)
		{
			offset.y--;
			decision = decision + 4 * (offset.x - offset.y) + 10;
		}
		else
		{
			decision = decision + 4 * offset.x + 6;
		}
	}
}
