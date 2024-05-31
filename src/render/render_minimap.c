/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:11:22 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/30 21:17:01 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int render_minimap(t_game *game)
{
  // render_wall_minimap(game->minimap ,game->map);
  draw_img(game->minimap->img, game, T_WALL, &draw_rect);
  mlx_image_to_window(game->win->mlx, game->minimap->img, 0, 0);
  return (TRUE);
}
