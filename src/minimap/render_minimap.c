/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:38:28 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/06 18:58:26 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
        mlx_image_to_window(game->win->mlx, game->walls->sprite.img, x * game->walls->sprite.img->width, y * game->walls->sprite.img->height);
			}
			x++;
		}
		y++;
	}
}
