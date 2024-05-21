/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:38:28 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/20 18:47:23 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	put_image_to_window(mlx_image_t *img, t_window *win,
		int position_width, int position_height)
{
	mlx_image_to_window(win->mlx, img, position_width, position_height);
}

void	draw_minimap(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map->mtx[y])
	{
		x = 0;
		while (game->map->mtx[y][x])
		{
			if (game->map->mtx[y][x] == '1')
			{
				put_image_to_window(game->walls->sprite->img, game->win,
					game->walls->sprite->size.w * x, game->walls->sprite->size.h
					* y);
			}
			else if (game->map->mtx[y][x] == 'P')
			{
				put_image_to_window(game->player->sprite->img, game->win,
					game->player->sprite->size.w * x,
					game->player->sprite->size.h * y);
        get_player_position(game->player);
			}
			x++;
		}
		y++;
	}
}
