/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:02:18 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/07 21:02:34 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void set_player_
t_sprite	*create_player_sprite(t_game *game)
{
  t_sprite *sprite;

  sprite = add_sprite(game->player->sprite);
  if (!sprite)
    return (NULL);
  sprite = game->player->sprite;
  sprite->path = PLAYER_PATH;
  sprite->size.w = 32;
	sprite->size.h = 32;
  sprite->texture = NULL;
  sprite->img = draw_rect(game->win, sprite->size.w, sprite->size.h, game->player->color.hex);
  sprite->next = NULL;
  return (sprite);
}
