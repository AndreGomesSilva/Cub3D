/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:05:30 by angomes-          #+#    #+#             */
/*   Updated: 2024/06/19 18:04:59 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_line	get_line_grid_to_pix(t_point p, t_dimension size)
{
	t_line	line;

	line.start.x = p.x * size.w;
	line.start.y = p.y * size.h;
	line.end.x = line.start.x + size.w;
	line.end.y = line.start.y + size.h;
	return (line);
}

void	cover_screen(t_screen *screen, t_dimension size, unsigned int color)
{
	t_line	line;

	line.start.x = 0;
	line.start.y = 0;
	line.end.x = size.w;
	line.end.y = size.h;
	draw_screen(screen, line, color, draw_rect);
}
