/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:50:21 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/10 23:24:50 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static t_walls	*create_walls_default_values(t_window *win)
{
	t_walls	*walls;

	walls = ft_calloc(1, sizeof(t_walls));
  if (!walls)
    return (NULL);
  walls->sprite = create_wall_sprite(win, walls);
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

static t_player	*create_player_default_values(t_window *win)
{
	t_player	*player;

	player = ft_calloc(1, sizeof(t_player));
  if (!player)
    return (NULL);
  player->sprite = create_player_sprite(win, player);
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
	game->walls = create_walls_default_values(game->win);
	game->player = create_player_default_values(game->win);
	if (!game || !game->map || !game->win || !game->walls)
		return (NULL);
	return (game);
} 
