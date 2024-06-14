/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keymaps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 21:27:07 by angomes-          #+#    #+#             */
/*   Updated: 2024/06/14 11:07:00 by angomes-         ###   ########.fr       */
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
    handle_player_movement(&game->minimap->player, UP);
	if (keydatam.key == MLX_KEY_A)
    handle_player_movement(&game->minimap->player, LEFT);
	if (keydatam.key == MLX_KEY_D)
    handle_player_movement(&game->minimap->player, RIGHT);
	if (keydatam.key == MLX_KEY_S)
    handle_player_movement(&game->minimap->player, DOWN);
}
