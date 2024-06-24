/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keymaps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:51:43 by angomes-          #+#    #+#             */
/*   Updated: 2024/06/24 17:24:48 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void hook_close_window(void *param) {
  t_window *win;

  win = (t_window *)param;
  (void)win;
  printf("Close window\n");
}

void move_keyhook(mlx_key_data_t keydatam, void *param)
{
	t_game *game;

	game = (t_game *)param;
	if (keydatam.key == MLX_KEY_ESCAPE)
		mlx_close_window(game->win->mlx);
	else if (keydatam.key == MLX_KEY_W)
		handle_player_movement(game->player, game->map, FORWARD);
	else if (keydatam.key == MLX_KEY_A)
		handle_player_movement(game->player, game->map, LEFT);
	else if (keydatam.key == MLX_KEY_D)
		handle_player_movement(game->player, game->map, RIGHT);
	else if (keydatam.key == MLX_KEY_S)
		handle_player_movement(game->player, game->map, BACKWARD);
	else if (keydatam.key == MLX_KEY_LEFT)
		handle_player_movement(game->player, game->map, R_LEFT);
	else if (keydatam.key == MLX_KEY_RIGHT)
		handle_player_movement(game->player, game->map, R_RIGHT);
}
