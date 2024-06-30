/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:59:27 by angomes-          #+#    #+#             */
/*   Updated: 2024/06/30 17:21:22 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_player_direction(t_player *player, char dir)
{
	if (dir == 'N')
	{
		player->rad_angle = 0;
		player->dir.x = 0;
		player->dir.y = -1;
	}
	else if (dir == 'S')
	{
		player->rad_angle = M_PI;
		player->dir.x = 0;
		player->dir.y = 1;
	}
	else if (dir == 'W')
	{
		player->rad_angle = M_PI * 3 / 2;
		player->dir.x = -1;
		player->dir.y = 0;
	}
	else if (dir == 'E')
	{
		player->rad_angle = M_PI / 2;
		player->dir.x = 1;
		player->dir.y = 0;
	}
}

static void	init_player_plane(t_player *player)
{
	double	tan_half_fov;

	tan_half_fov = tan(FOV / 2);
	if (player->dir.x == 0 && player->dir.y == -1)
	{
		player->plane.x = tan_half_fov;
		player->plane.y = 0;
	}
	else if (player->dir.x == 0 && player->dir.y == 1)
	{
		player->plane.x = -tan_half_fov;
		player->plane.y = 0;
	}
	else if (player->dir.x == 1 && player->dir.y == 0)
	{
		player->plane.x = 0;
		player->plane.y = tan_half_fov;
	}
	else if (player->dir.x == -1 && player->dir.y == 0)
	{
		player->plane.x = 0;
		player->plane.y = -tan_half_fov;
	}
}

static void	init_player(t_player *player, t_map *map)
{
	int col;
  int row;
	char	dir;

	row = 0;
	while (map->mtx[row] != NULL)
	{
		col = 0;
		while (map->mtx[row][col] != '\0')
		{
			if (ft_strchr("NSEW", map->mtx[row][col]) != NULL)
			{
				player->grid_pos.x = col + 0.5;
				player->grid_pos.y = row + 0.5;
				dir = map->mtx[row][col];
				set_player_direction(player, dir);
        return ;
			}
			col++;
		}
		row++;
	}
}

t_player	*create_player(t_map *map)
{
	t_player	*player;

	player = ft_calloc(1, sizeof(t_player));
	init_player(player, map);
	init_player_plane(player);
	return (player);
}



