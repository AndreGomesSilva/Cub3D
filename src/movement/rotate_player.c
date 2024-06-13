/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:28:57 by angomes-          #+#    #+#             */
/*   Updated: 2024/06/12 17:17:21 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void rotate_player(t_player *player, double angle, t_direction dir)
{
  if (dir == LEFT)
  {
    if (player->angle == 0)
      player->angle = 360;
    else
      player->angle -= angle;
  }
  else if (dir == RIGHT)
  {
    if (player->angle == 360)
      player->angle = 0;
    else
      player->angle += angle;
  }
}
