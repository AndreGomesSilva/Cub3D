/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:11:22 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/27 18:14:13 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/cub3d.h"

static void draw_minimap(t_window *win, mlx_image_t *img)
{
  mlx_image_to_window(win->mlx, img, 0, 0);
}

int render_minimap(t_game *game)
{
  draw_minimap(game->win, game->minimap);
  return (TRUE);
}
