/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 21:04:11 by angomes-          #+#    #+#             */
/*   Updated: 2024/07/10 11:21:14 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_loop(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (game->player->has_moved)
	{
		re_render_scene(game);
		re_render_minimap(game);
		game->player->has_moved = FALSE;
	}
}

int	game_loop(t_game *game)
{
	render_background(game);
	first_render_scene(game);
	first_render_minimap(game);
	mlx_loop_hook(game->win->mlx, &init_loop, game);
	mlx_key_hook(game->win->mlx, &move_keyhook, game);
	mlx_get_mouse_pos(game->win->mlx, &game->mouse_x, &game->mouse_y);
	mlx_cursor_hook(game->win->mlx, &handle_cursor, game);
	mlx_close_hook(game->win->mlx, &hook_close_window, game);
	mlx_loop(game->win->mlx);
	return (E_OK);
}
