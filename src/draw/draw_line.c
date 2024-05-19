/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 20:20:36 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/19 20:23:33 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_line	*new_line(t_window *win, t_player *player, t_vector start, t_vector end)
{
	t_line	*line;

	line = ft_calloc(1, sizeof(t_line));
	if (!line)
		return (NULL);
	line->start = start;
	line->end = end;
	line->img = draw_line(win->img, start.x, start.y, end.x, end.y,
			player->color.hex);
	line->next = NULL;
	return (line);
}

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
	if (line->start.y <   line->end.y)
		sy = 1;
	else
		sy = -1;
	while (line->start.x != line->end.x || line->start.y != line->end.y)
	{
		mlx_put_pixel(img, line->start.x, line->start.y, line->color);
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
	mlx_put_pixel(img, line->end.x, line->end.y, color);
	return (img);
}

mlx_image_t	*create_line(t_window *win, t_line *line)
{
	mlx_image_t	*new_img;
	mlx_image_t	*img;

	img = mlx_new_image(win->mlx, win->mlx->width, win->mlx->height);
	new_img = draw_line(img, line);
	return (new_img);
}
