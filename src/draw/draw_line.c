/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 20:20:36 by angomes-          #+#    #+#             */
/*   Updated: 2024/07/06 10:51:50 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	put_line_screen(mlx_image_t *img, t_line *line, t_point step)
{
	t_point	delta;
	double	err;
	double	temp_err;

	delta.x = abs_double(round(line->end.x - line->start.x));
	delta.y = abs_double(round(line->end.y - line->start.y));
	err = delta.x - delta.y;
	while (line->start.x < img->width && line->start.y < img->height
		&& (line->start.x != line->end.x || line->start.y != line->end.y))
	{
		mlx_put_pixel(img, (int)line->start.x, (int)line->start.y,
			line->color.hex);
		temp_err = 2 * err;
		if (temp_err > -delta.y)
		{
			err -= delta.y;
			line->start.x += step.x;
		}
		if (temp_err < delta.x)
		{
			err += delta.x;
			line->start.y += step.y;
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
	put_line_screen(img, &line, dir_step);
}

void	draw_v_line(t_game *game, int col, int start, int end)
{
	int	row;

	row = start;
	while (row < end)
	{
		mlx_put_pixel(game->main_img, col, row,
			game->player->ray.tex.buffer[row]);
		row++;
	}
}
