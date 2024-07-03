/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:50:21 by angomes-          #+#    #+#             */
/*   Updated: 2024/07/03 17:59:57 by angomes-         ###   ########.fr       */
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
	win->size.h = WIN_HEIGHT;
	win->size.w = WIN_WIDTH;
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
	minimap->size.h = win->size.h * 0.21;
	minimap->size.w = win->size.w * 0.21;
	if (minimap->size.h < 10 || minimap->size.w < 20)
	{
		minimap->size.h = 10;
		minimap->size.w = 20;
	}
	minimap->img = mlx_new_image(win->mlx, minimap->size.w, minimap->size.h);
	if (!minimap->img)
		return (NULL);
	minimap->entity_size.h = minimap->size.h / map->size.h;
	minimap->entity_size.w = minimap->size.w / map->size.w;
	minimap->floor_color.hex = WHITE;
	minimap->wall_color.hex = BLACK;
	minimap->dir_line_color.hex = BLUE;
	minimap->player_color.hex = RED;
	return (minimap);
}

int	load_textures(mlx_texture_t **wall_texture, char **file_content)
{
	wall_texture[NORTH] = mlx_load_png(file_content[NO]);
	wall_texture[SOUTH] = mlx_load_png(file_content[SO]);
	wall_texture[EAST] = mlx_load_png(file_content[EA]);
	wall_texture[WEST] = mlx_load_png(file_content[WE]);
	if (!wall_texture[NORTH] || !wall_texture[SOUTH] || !wall_texture[EAST]
		|| !wall_texture[WEST])
		return (print_error("Could not load texture from provided path\n"));
	return (E_OK);
}

int	init_data(t_game *game, char *str)
{
	if (validate_file(game, str) != E_OK)
		return (E_FAIL);
	if (load_textures(game->wall_texture, game->file_content) != E_OK)
		return (E_FAIL);
	if (set_bg_colors(game) != E_OK)
		return (E_FAIL);
	game->map = create_map(str);
	if (!game->map)
		return (E_FAIL);
	game->win = create_window();
	game->player = create_player(game->map);
	game->player->ray.tex.texture = game->wall_texture;
	game->background_img = mlx_new_image(game->win->mlx, WIN_WIDTH, WIN_HEIGHT);
	game->main_img = mlx_new_image(game->win->mlx, WIN_WIDTH, WIN_HEIGHT);
	game->minimap = create_minimap(game->win, game->map);
	if (!game || !game->map || !game->win || !game->minimap || !game->player)
		return (E_FAIL);
	return (E_OK);
}
