/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:50:21 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/27 18:42:45 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_window *create_window()
{
  t_window *win;

  win = ft_calloc(1, sizeof(t_window));
  if (!win)
    return (NULL);
  win->mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "Cub3D", true);
  if (!win->mlx)
    return (NULL);
  return (win);
}

t_map *create_map(char *str)
{
  t_map *map;

  map = ft_calloc(1, sizeof(t_map));
  if (!map)
    return (NULL);
  map->mtx = get_map(str);
  if (!map->mtx)
    return (NULL);
  return (map);
}

t_game	*init_data(char *str)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
  game->map = create_map(str);
  game->win = create_window();
  game->minimap = mlx_new_image(game->win->mlx, MIN_WIDTH, MIN_HEIGHT);
	if (!game || !game->map || !game->win)
		return (NULL);
	return (game);
} 
