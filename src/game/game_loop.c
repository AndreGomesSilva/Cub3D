/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 21:04:11 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/04 03:42:37 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	game_loop(t_game *game)
{
	game->walls->sprite.img = mlx_new_image(game->win->mlx, game->walls->size.w,
			game->walls->size.h);
  mlx_image_to_window(game->win->mlx, game->walls->sprite.img, 20, 20);
  draw_rect(game->win, 10, 10, 0xFF00FF);
	mlx_loop_hook(game->win->mlx, &hook_close_window, game->win);
	mlx_loop(game->win->mlx);
	return (E_OK);
}
