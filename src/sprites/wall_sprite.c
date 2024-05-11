/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:08:52 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/10 23:23:44 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	set_wall_sprite_values(t_window *win, t_sprite *sprite, int type)
{
	sprite->path = WALL_PATH;
	sprite->size.w = 32;
	sprite->size.h = 32;
	sprite->texture = NULL;
	if (type == NORTH)
	{
		set_color(&sprite->color, 255, 255, 255);
		sprite->img = draw_rect(win, sprite->size.w, sprite->size.h,
				sprite->color.hex);
	}
	else if (type == SOUTH)
	{
		set_color(&sprite->color, 0, 255, 0);
		sprite->img = draw_rect(win, sprite->size.w, sprite->size.h,
				sprite->color.hex);
	}
	else if (type == WEST)
	{
		set_color(&sprite->color, 0, 0, 255);
		sprite->img = draw_rect(win, sprite->size.w, sprite->size.h,
				sprite->color.hex);
	}
	else if (type == EAST)
	{
		set_color(&sprite->color, 255, 255, 0);
		sprite->img = draw_rect(win, sprite->size.w, sprite->size.h,
				sprite->color.hex);
	}
}

t_sprite	*create_wall_sprite(t_window *win, t_walls *walls)
{
	t_sprite	*sprite;
	t_sprite	*first_sprite;
	int			type_of_walls;

	type_of_walls = 0;
	sprite = add_sprite(walls->sprite);
	first_sprite = sprite;
	while (sprite && type_of_walls < 4)
	{
		set_wall_sprite_values(win, sprite, type_of_walls);
		add_sprite(walls->sprite);
		sprite = sprite->next;
		type_of_walls++;
	}
	return (first_sprite);
}
