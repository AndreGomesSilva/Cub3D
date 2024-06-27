/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 20:20:36 by angomes-          #+#    #+#             */
/*   Updated: 2024/06/26 17:11:06 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	put_line_screen(mlx_image_t *img, t_line *line, int step_x, int step_y)
{
	t_point delta;
	double err;
	double	temp_err;

	delta.x = abs_double(round(line->end.x - line->start.x));
	delta.y = abs_double(round(line->end.y - line->start.y));
	err = delta.x - delta.y;
	while ((int)line->start.x < MIN_WIDTH && (int)line->start.y < MIN_HEIGHT &&
			(line->start.x != line->end.x || line->start.y != line->end.y))
	{
		mlx_put_pixel(img, (int)line->start.x, (int)line->start.y,
				line->color.hex);
		temp_err = 2 * err;
		if (temp_err > -delta.y)
		{
			err -= delta.y;
			line->start.x += step_x;
		}
		if (temp_err < delta.x)
		{
			err += delta.x;
			line->start.y += step_y;
		}
	}
	mlx_put_pixel(img, line->start.x, line->start.y, line->color.hex);
}

void	draw_line(mlx_image_t *img, t_line line, unsigned int color)
{
	t_point	dir_step;

	line.color.hex = color;
	if (line.start.x < line.end.x)
		dir_step.x = 1;
	else
		dir_step.x = -1;
	if (line.start.y < line.end.y)
		dir_step.y = 1;
	else
		dir_step.y = -1;
	put_line_screen(img, &line, dir_step.x, dir_step.y);
}

void	draw_v_line(int col, int start, int end, int *buffer, mlx_image_t *img)
{
	int i;

	i = start;
	while (i < end)
	{
		mlx_put_pixel(img, col, i, buffer[i]);
		i++;
	}
}
