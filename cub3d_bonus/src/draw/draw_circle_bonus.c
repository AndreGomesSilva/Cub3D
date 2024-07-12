/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:24:08 by angomes-          #+#    #+#             */
/*   Updated: 2024/07/12 15:47:31 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	draw_horizontal_line(mlx_image_t *img, int x1, t_point pos,
		unsigned int color)
{
	while (x1 <= pos.x)
	{
		mlx_put_pixel(img, x1, pos.y, color);
		x1++;
	}
}

static void	fill_circle_points(mlx_image_t *img, t_point center, t_point offset,
		unsigned int color)
{
	t_point	position;
	int		start_draw;

	start_draw = center.x - offset.x;
	position.x = center.x + offset.x;
	position.y = center.y + offset.y;
	draw_horizontal_line(img, start_draw, position, color);
	position.y = center.y - offset.y;
	draw_horizontal_line(img, start_draw, position, color);
	start_draw = center.x - offset.y;
	position.x = center.x + offset.y;
	position.y = center.y + offset.x;
	draw_horizontal_line(img, start_draw, position, color);
	position.y = center.y - offset.x;
	draw_horizontal_line(img, start_draw, position, color);
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
		fill_circle_points(img, center, offset, color);
		offset.x++;
		if (decision > 0)
		{
			offset.y--;
			decision = decision + 4 * (offset.x - offset.y) + 10;
		}
		else
			decision = decision + 4 * offset.x + 6;
	}
}
