/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:50:21 by angomes-          #+#    #+#             */
/*   Updated: 2024/06/25 17:20:59 by iusantos         ###   ########.fr       */
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
  map->size.w = get_num_col_map(map->mtx);
  map->size.h = get_num_row_map(map->mtx);
  return (map);
}

t_screen *create_minimap(t_window *win, t_map *map)
{
  t_screen *minimap;

  minimap = ft_calloc(1, sizeof(t_screen));
  if (!minimap)
    return (NULL);
  minimap->img = mlx_new_image(win->mlx, MIN_WIDTH, MIN_HEIGHT);
  if (!minimap->img)
    return (NULL);
  minimap->size.w = MIN_WIDTH;
  minimap->size.h = MIN_HEIGHT;
  minimap->walls.color.hex = get_hex_color(&minimap->walls.color, 255, 255, 255);
  minimap->walls.size.w = MIN_WIDTH / map->size.w;
  minimap->walls.size.h = MIN_HEIGHT / map->size.h;
  return (minimap);
}

int load_textures(mlx_texture_t **wall_texture)
{
  wall_texture[NORTH] = mlx_load_png("./assets/textures/wall_textures/tile066.png");
  wall_texture[SOUTH] = mlx_load_png("./assets/textures/wall_textures/tile106.png");
  wall_texture[EAST] = mlx_load_png("./assets/textures/wall_textures/tile118.png");
  wall_texture[WEST] = mlx_load_png("./assets/textures/wall_textures/tile120.png");
  if (!wall_texture[NORTH] || !wall_texture[SOUTH] || !wall_texture[EAST] || !wall_texture[WEST])
    return (E_FAIL);
  return (E_OK);
}

t_game	*init_data(char *str)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
  game->map = create_map(str);
  game->win = create_window();
	game->player = create_player(game->map);
  load_textures(game->wall_texture);
	game->background_img = mlx_new_image(game->win->mlx, WIN_WIDTH, WIN_HEIGHT);
	game->main_img = mlx_new_image(game->win->mlx, WIN_WIDTH, WIN_HEIGHT);
  game->minimap = create_minimap(game->win, game->map);
	if (!game || !game->map || !game->win || !game->minimap)
		return (NULL);
	return (game);
} 
