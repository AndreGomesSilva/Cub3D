/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 21:04:11 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/10 21:00:43 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	game_loop(t_game *game)
{
  // game->walls->sprite->texture = mlx_load_png(WALL_PATH);
  // game->walls->sprite->img = mlx_texture_to_image(game->win->mlx, game->walls->sprite->texture);
  //
  // mlx_put_pixel(game->walls->sprite.img, 0, 0, game->walls->color.hex);
  draw_minimap(game);
	mlx_loop_hook(game->win->mlx, &hook_close_window, game->win);
	mlx_loop(game->win->mlx);
	return (E_OK);
}
