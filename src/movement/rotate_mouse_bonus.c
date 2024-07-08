/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_mouse_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:54:58 by angomes-          #+#    #+#             */
/*   Updated: 2024/07/08 15:20:22 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_cursor(double x, double y, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (x < 0 || x > WIN_WIDTH || y < 0 || y > WIN_HEIGHT)
		return ;
	else
		mlx_set_cursor_mode(game->win->mlx, MLX_MOUSE_HIDDEN);
	if ((int)x < game->mouse_x)
		handle_player_movement(game->player, game->map, M_LEFT);
	else if ((int)x > game->mouse_x)
		handle_player_movement(game->player, game->map, M_RIGHT);
	game->mouse_x = (int)x;
}
