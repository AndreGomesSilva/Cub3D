/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:48:27 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/13 17:56:21 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	get_player_position(t_player *player)
{
	player->pos.x = player->sprite->img->instances[0].x;
	player->pos.y = player->sprite->img->instances[0].y;
}

void	set_player_position(t_player *player, int x, int y)
{
	player->sprite->img->instances[0].x = x;
	player->sprite->img->instances[0].y = y;
}

t_bool	check_hit_wall(t_map *map, int x, int y)
{
	if (map->mtx[y][x] == '1')
		return (TRUE);
	return (FALSE);
}
