/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:50:21 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/03 18:31:36 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	set_data(t_game *game)
{
  t_player *player;
  t_window *window;

  window = ft_calloc(1, sizeof(t_window));
  player = ft_calloc(1, sizeof(t_player));
  player->pos.x = 10;
  player->pos.y = 10;
  window->size.w = 800;
  window->size.h = 600;
  game->win = window;
  game->player = player;
  return (TRUE);
}
