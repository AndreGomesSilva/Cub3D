/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 21:04:11 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/27 15:12:27 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void render_lines(t_window *win, t_player *player)
{
  render_dirline(win, player);
  render_plane(win, player);
}

int	game_loop(t_game *game)
{
  draw_minimap(game);
  render_lines(game->win, game->player);
  // mlx_loop_hook(game->win->mlx, &loop, game);
  mlx_key_hook(game->win->mlx, &move_keyhook, game);
  mlx_close_hook(game->win->mlx, &hook_close_window, game->win); //when close with the cross on title window
	mlx_loop(game->win->mlx);
	return (E_OK);
}
