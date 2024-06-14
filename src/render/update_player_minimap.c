/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_minimap.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:27:46 by angomes-          #+#    #+#             */
/*   Updated: 2024/06/14 11:34:41 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	update_dir_line(t_screen *minimap, t_player *player)
{
	player->dir_line.start.x = player->origin.x;
	player->dir_line.start.y = player->origin.y;
	player->dir_line.end.x = player->origin.x;
	player->dir_line.end.y = player->origin.y - 10;
	player->dir_line = rotate_line(player->dir_line, player->angle);
	printf("finish rotate \n");
	draw_screen(minimap, player->dir_line, player->dir_line.color.hex,
		draw_line);
}

void	update_player_minimap(t_screen *minimap)
{
	t_line	line;

	update_player_origin(&minimap->player);
	line.start.x = minimap->player.origin.x;
	line.start.y = minimap->player.origin.y;
	line.end.x = line.start.x + 5;
	line.end.y = line.start.y + 5;
	draw_screen(minimap, line, minimap->player.color.hex, draw_circle);
	update_dir_line(minimap, &minimap->player);
}

void	update_minimap(t_game *game)
{
	cover_screen(game->minimap, game->minimap->size, BLACK);
	draw_minimap(game, game->map, game->map->size);
	update_player_minimap(game->minimap);
	mlx_image_to_window(game->win->mlx, game->minimap->img, 0, 0);
	game->minimap->player.is_moving = FALSE;
}
