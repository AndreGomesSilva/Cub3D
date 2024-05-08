/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:08:52 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/07 21:53:47 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"



static void	set_wall_sprite_values(t_game *game, t_sprite *sprite, int type)
{
  int color[3];

	sprite->path = WALL_PATH;
	sprite->size.w = 32;
	sprite->size.h = 32;
	sprite->texture = NULL;
	if (type == NORTH)
	{

	  sprite->color = 	
		sprite->img = draw_rect(game->win, sprite->size.w, sprite->size.h,
				sprite->color.hex);
	}
}

t_sprite	*create_wall_sprite(t_game *game)
{
	t_sprite	*sprite;
	t_sprite	*first_sprite;
	int			type_of_walls;

	type_of_walls = 0;
	sprite = add_sprite(game->walls->sprite);
	first_sprite = sprite;
	while (sprite && type_of_walls < 4)
	{
		set_wall_sprite_values(game, sprite, type_of_walls);
		add_sprite(game->walls->sprite);
		sprite = sprite->next;
		type_of_walls++;
	}
	return (first_sprite);
}
