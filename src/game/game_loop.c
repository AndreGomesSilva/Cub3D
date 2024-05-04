/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 21:04:11 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/03 22:07:32 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	game_loop(t_game *game)
{
	game->walls->sprite.img = mlx_new_image(game->win->mlx, game->walls->size.w,
			game->walls->size.h);
	mlx_put_pixel(game->walls->sprite.img, game->walls->size.w,
			game->walls->size.h, game->walls->color.hex);
  mlx_image_to_window(game->win->mlx, game->walls->sprite.img, 0, 0);
		mlx_loop_hook(game->win->mlx, &hook_close_window, game->win);
	mlx_loop(game->win->mlx);
	return (E_SUCCESS);
}
