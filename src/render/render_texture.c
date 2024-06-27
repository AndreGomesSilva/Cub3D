/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:46:51 by angomes-          #+#    #+#             */
/*   Updated: 2024/06/27 16:18:01 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	fill_buffer(t_ray *ray, int draw_start, int draw_end)
{
	int				row;
	mlx_texture_t	*tex_surface;

	tex_surface = ray->tex.texture[ray->side_wall];
	row = draw_start;
	ray->tex.step = 1.0 * tex_surface->height / ray->line_height;
	ray->tex.pos = (draw_start - WIN_HEIGHT / 2 + ray->line_height / 2)
		* ray->tex.step;
	while (row < draw_end)
	{
		ray->tex.tex_row = (int)ray->tex.pos & (tex_surface->height - 1);
		ray->tex.pos += ray->tex.step;
		ray->tex.rgb = *((unsigned int *)tex_surface->pixels
				+ (unsigned int)(ray->tex.tex_row * tex_surface->width
					+ ray->tex.tex_col));
		ray->tex.color.hex = ((ray->tex.rgb & 0xFF) << 24 |
								(ray->tex.rgb & 0xFF00) << 8 |
								(ray->tex.rgb & 0xFF0000) >> 8 |
								(ray->tex.rgb & 0xFF000000) >> 24);
		ray->tex.buffer[row] = ray->tex.color.hex;
		row++;
	}
}

static void	select_texture_col(t_ray *ray, t_point player_pos)
{
	if (ray->side_wall == NORTH || ray->side_wall == SOUTH)
		ray->tex.wall_x = player_pos.x + ray->perp_wall_dist * ray->dir.x;
	else
		ray->tex.wall_x = player_pos.y + ray->perp_wall_dist * ray->dir.y;
	ray->tex.wall_x -= floor(ray->tex.wall_x);
	ray->tex.tex_col = (int)(ray->tex.wall_x
			* (double)ray->tex.texture[ray->side_wall]->width);
	if ((ray->side_wall == NORTH || ray->side_wall == SOUTH) && ray->dir.x > 0)
		ray->tex.tex_col = ray->tex.texture[ray->side_wall]->width
			- ray->tex.tex_col - 1;
	if ((ray->side_wall == EAST || ray->side_wall == WEST) && ray->dir.y < 0)
		ray->tex.tex_col = ray->tex.texture[ray->side_wall]->width
			- ray->tex.tex_col - 1;
}

void	texture_pre_render(t_ray *ray, t_point player_pos, int draw_start,
		int draw_end)
{
	select_texture_col(ray, player_pos);
	fill_buffer(ray, draw_start, draw_end);
}
