/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:50:21 by angomes-          #+#    #+#             */
/*   Updated: 2024/06/29 16:58:34 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_window	*create_window(void)
{
	t_window	*win;

	win = ft_calloc(1, sizeof(t_window));
	if (!win)
		return (NULL);
	win->mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "Cub3D", true);
	if (!win->mlx)
		return (NULL);
	return (win);
}

t_map	*create_map(char *str)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	map->mtx = get_map(str);
	if (!map->mtx)
		return (NULL);
	if (check_for_invalid_character(map->mtx) != E_OK)
		return (NULL);
	if (check_number_of_players(map->mtx) != E_OK)
		return (NULL);
	map->size.w = get_num_col_map(map->mtx);
	map->size.h = get_num_row_map(map->mtx);
	return (map);
}

static t_minimap	*create_minimap(t_window *win, t_map *map)
{
	t_minimap	*minimap;

	minimap = ft_calloc(1, sizeof(t_minimap));
	if (!minimap)
		return (NULL);
	minimap->img = mlx_new_image(win->mlx, MIN_WIDTH, MIN_HEIGHT);
	if (!minimap->img)
		return (NULL);
	minimap->size.h = MIN_HEIGHT;
	minimap->size.w = MIN_WIDTH;
	minimap->wall_size.w = MIN_WIDTH / map->size.w;
	minimap->wall_size.h = MIN_HEIGHT / map->size.h;
	minimap->floor_size.w = MIN_WIDTH / map->size.w;
	minimap->floor_size.h = MIN_HEIGHT / map->size.h;
	minimap->player_size.w = MIN_WIDTH / map->size.w;
	minimap->player_size.h = MIN_HEIGHT / map->size.h;
	minimap->floor_color.hex = get_hex_color(&minimap->floor_color, 233, 234,
			153);
	minimap->wall_color.hex = get_hex_color(&minimap->wall_color, 255, 255,
			255);
	minimap->dir_line_color.hex = get_hex_color(&minimap->dir_line_color, 20,
			160, 180);
	minimap->player_color.hex = get_hex_color(&minimap->player_color, 255, 255,
			173);
	return (minimap);
}

int	load_textures(mlx_texture_t **wall_texture)
{
	wall_texture[NORTH] = mlx_load_png("./assets/textures/wall_textures/tile066.png");
	wall_texture[SOUTH] = mlx_load_png("./assets/textures/wall_textures/tile106.png");
	wall_texture[EAST] = mlx_load_png("./assets/textures/wall_textures/tile118.png");
	wall_texture[WEST] = mlx_load_png("./assets/textures/wall_textures/tile120.png");
	if (!wall_texture[NORTH] || !wall_texture[SOUTH] || !wall_texture[EAST]
		|| !wall_texture[WEST])
		return (E_FAIL);
	return (E_OK);
}

int	init_data(t_game *game, char *str)
{
	if (validate_file(str) != E_OK)
		return (E_FAIL);
	game->map = create_map(str);
	if (!game->map)
		return (E_FAIL);
	game->win = create_window();
	game->player = create_player(game->map);
	if (load_textures(game->wall_texture) == E_FAIL)
		return (E_FAIL);
	game->player->ray.tex.texture = game->wall_texture;
	game->background_img = mlx_new_image(game->win->mlx, WIN_WIDTH, WIN_HEIGHT);
	game->main_img = mlx_new_image(game->win->mlx, WIN_WIDTH, WIN_HEIGHT);
	game->minimap = create_minimap(game->win, game->map);
	if (!game || !game->map || !game->win || !game->minimap || !game->player)
		return (E_FAIL);
	return (E_OK);
}
