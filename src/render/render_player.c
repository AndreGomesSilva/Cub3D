/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 21:07:37 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/29 21:19:45 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_point get_player_pix_pos(t_map *map)
{
  t_point pix_pos;

  pix_pos.x = map->player.pos.x * map->size.w;
  pix_pos.y = map->player.pos.y * map->size.h;
  return (pix_pos);
}
