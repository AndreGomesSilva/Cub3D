/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 21:04:11 by angomes-          #+#    #+#             */
/*   Updated: 2024/06/24 15:17:29 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void init_loop(void *param) {
  t_game *game;

  game = (t_game *)param;
  if (game->player->has_moved) {
    render_scene(game);
    // update_minimap(game);
  }
}

int game_loop(t_game *game) {
  render_background(game);
  render_scene(game);
  // render_minimap(game);
  mlx_loop_hook(game->win->mlx, &init_loop, game);
  mlx_key_hook(game->win->mlx, &move_keyhook, game);
  mlx_close_hook(game->win->mlx, &hook_close_window,
                 game->win); // when close with the cross on title window
  mlx_loop(game->win->mlx);
  return (E_OK);
}
