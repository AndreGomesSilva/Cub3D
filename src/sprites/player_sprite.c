/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:02:18 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/10 18:08:21 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_sprite	*create_player_sprite(t_window  *win, t_player *player)
{
  t_sprite *sprite;

  sprite = add_sprite(player->sprite);
  if (!sprite)
    return (NULL);
  sprite->path = PLAYER_PATH;
  sprite->size.w = 32;
	sprite->size.h = 32;
  sprite->texture = NULL;
  set_color(&sprite->color, 255, 180, 255);
  sprite->img = draw_rect(win, sprite->size.w, sprite->size.h, player->sprite->color.hex);
  sprite->next = NULL;
  return (sprite);
}
