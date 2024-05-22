/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keymaps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 21:27:07 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/15 19:08:40 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	hook_close_window(void *param)
{
	t_window	*win;

	win = (t_window *)param;
	(void)win;
	printf("Close window\n");
}

void	move_keyhook(mlx_key_data_t keydatam, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydatam.key == MLX_KEY_ESCAPE)
		mlx_close_window(game->win->mlx);
	if (keydatam.key == MLX_KEY_W)
    handle_movement(game->player, game->map, NORTH);
	if (keydatam.key == MLX_KEY_A)
    handle_movement(game->player, game->map, WEST);
	if (keydatam.key == MLX_KEY_D)
    handle_movement(game->player, game->map, EAST);
	if (keydatam.key == MLX_KEY_S)
    handle_movement(game->player, game->map, SOUTH);
}