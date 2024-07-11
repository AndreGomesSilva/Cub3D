/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 21:04:11 by angomes-          #+#    #+#             */
/*   Updated: 2024/07/11 11:57:14 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_loop(void *param)
{
	t_game	*game;
	static long long frame;
	static long long click_frame = -1;
	static long long i = -1;

	game = (t_game *)param;
	if (game->player->has_moved)
	{
		re_render_scene(game);
		re_render_minimap(game);
		game->player->has_moved = FALSE;
	}
	if (game->player->has_shot == TRUE)
	{
		click_frame = frame;
		game->gun_img[0]->enabled = false;
		game->gun_img[1]->enabled = true;
		game->player->has_shot = FALSE;
	}
	if (click_frame != -1)
		i = frame - click_frame;
	shoot(game, &i, &click_frame);
	frame++;
}

int	game_loop(t_game *game)
{
	render_background(game);
	first_render_scene(game);
	first_render_minimap(game);
	first_render_gun(game);
	mlx_key_hook(game->win->mlx, &move_keyhook, game);
	mlx_mouse_hook(game->win->mlx, &mouse_keyhook, game);
	mlx_get_mouse_pos(game->win->mlx, &game->mouse_x, &game->mouse_y);
	mlx_cursor_hook(game->win->mlx, &handle_cursor, game);
	mlx_close_hook(game->win->mlx, &hook_close_window, game);
	mlx_loop_hook(game->win->mlx, &init_loop, game);
	mlx_loop(game->win->mlx);
	return (E_OK);
}
