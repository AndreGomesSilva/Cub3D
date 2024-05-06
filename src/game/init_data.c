/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:50:21 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/06 18:08:02 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static t_walls	*create_walls_default_values(void)
{
	t_walls	*walls;

	walls = ft_calloc(1, sizeof(t_walls));
  if (!walls)
    return (NULL);
	walls->color.r = 255;
	walls->color.g = 0;
	walls->color.b = 128;
	walls->color.a = 128;
	walls->color.hex = rgb_to_hex(walls->color.r, walls->color.g,
			walls->color.b, walls->color.a);
	walls->size.w = 32;
	walls->size.h = 32;
	walls->sprite.path = WALL;
	return (walls);
}

static t_window	*create_window_default_values(void)
{
	t_window	*window;

	window = ft_calloc(1, sizeof(t_window));
	window->size.w = WIDTH;
	window->size.h = HEIGHT;
	window->mlx = mlx_init(window->size.w, window->size.h, "Cub3D", TRUE);
	if (!window->mlx)
		return (NULL);
	return (window);
}

static t_player	*create_player_default_values(void)
{
	t_player	*player;

	player = ft_calloc(1, sizeof(t_player));
  if (!player)
    return (NULL);
	return (player);
}

static t_map	*create_map_default_values(char *str)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (!map || !str)
		return (NULL);
	map->path = str;
	map->mtx = get_map(map->path);
  if (!map->mtx)
    return (NULL);
	return (map);
}

t_game	*init_data(char *str)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	game->map = create_map_default_values(str);
	game->win = create_window_default_values();
	game->walls = create_walls_default_values();
	game->player = create_player_default_values();
	if (!game || !game->map || !game->win || !game->walls || !game->player)
		return (NULL);
	return (game);
}
