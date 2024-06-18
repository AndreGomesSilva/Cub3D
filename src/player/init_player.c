/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:59:27 by angomes-          #+#    #+#             */
/*   Updated: 2024/06/18 16:37:43 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	set_player_position(t_player *player, t_point p)
{
	player->grid_pos.x = p.x;
	player->grid_pos.y = p.y;
	player->pix_pos.x = p.x * player->size.w;
	player->pix_pos.y = p.y * player->size.h;
	update_player_origin(player);
}

static void	set_player_direction(t_player *player, char dir)
{
	if (dir == 'N')
	{
		player->angle = 0;
		player->dir.x = 0;
		player->dir.y = -1;
	}
	else if (dir == 'S')
	{
		player->angle = 180;
		player->dir.x = 0;
		player->dir.y = 1;
	}
	else if (dir == 'W')
	{
		player->angle = 270;
		player->dir.x = -1;
		player->dir.y = 0;
	}
	else if (dir == 'E')
	{
		player->angle = 90;
		player->dir.x = 1;
		player->dir.y = 0;
	}
}

static void	init_player_size_and_color(t_player *player, t_map *map)
{
	player->size.w = MIN_WIDTH / map->size.w;
	player->size.h = MIN_HEIGHT / map->size.h;
	player->color.hex = get_hex_color(&player->color, 170, 150, 220);
}

static void init_player_plane(t_player *player)
{
  double tan_half_fov;

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

static int	init_player(t_player *player, t_map *map)
{
	t_point	p;
	char	dir;

	p.y = 0;
	while (p.y < map->size.h)
	{
		p.x = 0;
		while (p.x < map->size.w)
		{
			if (map->mtx[(int)p.y][(int)p.x] == 'N'
				|| map->mtx[(int)p.y][(int)p.x] == 'S'
				|| map->mtx[(int)p.y][(int)p.x] == 'W'
				|| map->mtx[(int)p.y][(int)p.x] == 'E')
			{
				set_player_position(player, p);
				dir = map->mtx[(int)p.y][(int)p.x];
				set_player_direction(player, dir);
			}
			p.x++;
		}
		p.y++;
	}
	return (0);
}

t_player	*create_player(t_map *map)
{
	t_player	*player;

	player = ft_calloc(1, sizeof(t_player));
	init_player_size_and_color(player, map);
	init_player(player, map);
  init_player_plane(player);
  printf("player dir x: %f, y: %f\n", player->dir.x, player->dir.y);
  printf("player plane x: %f, y: %f\n", player->plane.x, player->plane.y);
	return (player);
}

void	update_player_origin(t_player *player)
{
	player->origin.x = player->pix_pos.x + (double)player->size.w / 2;
	player->origin.y = player->pix_pos.y + (double)player->size.h / 2;
}
