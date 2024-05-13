/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keymaps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 21:27:07 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/13 17:50:07 by angomes-         ###   ########.fr       */
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
    move_up(game->player, game->map);
	if (keydatam.key == MLX_KEY_A)
		printf("keydatam.key == MLX_KEY_A\n");
	if (keydatam.key == MLX_KEY_D)
		printf("keydatam.key == MLX_KEY_D\n");
	if (keydatam.key == MLX_KEY_S)
		printf("keydatam.key == MLX_KEY_LEFT\n");
}
