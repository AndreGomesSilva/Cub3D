/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:59:27 by angomes-          #+#    #+#             */
/*   Updated: 2024/06/17 19:03:18 by iusantos         ###   ########.fr       */
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

static void set_player_direction(t_player *player, char dir)
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


static int init_player(t_player *player, t_map *map)
{
  t_point p;
  char dir;

	player->size.w = MIN_WIDTH / map->size.w;
	player->color.hex = get_hex_color(&player->color, 170, 150, 220);
	player->size.h = MIN_HEIGHT / map->size.h;
  p.y = 0;
  while (p.y < map->size.h)
  {
    p.x = 0;
    while (p.x < map->size.w)
    {
      if (map->mtx[(int)p.y][(int)p.x] == 'N' || map->mtx[(int)p.y][(int)p.x] == 'S' || map->mtx[(int)p.y][(int)p.x] == 'W' || map->mtx[(int)p.y][(int)p.x] == 'E')
      {
        set_player_position(player, p) ;
        dir = map->mtx[(int)p.y][(int)p.x];
        set_player_direction(player, dir);
      }
      p.x++;
    }
    p.y++;
  }
	printf("player dir pos x %f, y %f\n", player->dir.x, player->dir.y);
  printf("player pos x %f, y %f\n", player->pix_pos.x, player->pix_pos.y);
  printf("player origin x %f, y %f\n", player->origin.x, player->origin.y);
  return (0);
}

t_player	*create_player(t_map *map)
{
	t_player	*player;

	player = ft_calloc(1, sizeof(t_player));
	init_player(player, map);
	return (player);
}

void	update_player_origin(t_player *player)
{
	player->origin.x = player->pix_pos.x + (double)player->size.w / 2;
	player->origin.y = player->pix_pos.y + (double)player->size.h / 2;
}

