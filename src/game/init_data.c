/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:50:21 by angomes-          #+#    #+#             */
/*   Updated: 2024/07/10 12:05:07 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	create_window(t_game *game)
{
	game->win = ft_calloc(1, sizeof(t_window));
	if (game->win == NULL)
		return (E_FAIL);
	game->win->mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "Cub3D", true);
	if (game->win->mlx == NULL)
		return (print_error("Could not create window\n"));
	game->win->size.h = WIN_HEIGHT;
	game->win->size.w = WIN_WIDTH;
	return (E_OK);
}

int	create_map(t_game *game)
{
	game->map = ft_calloc(1, sizeof(t_map));
	if (game->map == NULL)
		return (print_error("Could not allocate map\n"));
	game->map->mtx = get_map(game->fd);
	if (game->map->mtx == NULL)
		return (print_error("Problem creating map matrix\n"));
	if (check_for_invalid_character(game->map->mtx) != E_OK)
		return (E_FAIL);
	if (check_number_of_players(game->map->mtx) != E_OK)
		return (E_FAIL);
	game->map->size.w = get_num_col_map(game->map->mtx);
	game->map->size.h = get_num_row_map(game->map->mtx);
	game->map->max_cols = get_max_col(game->map->mtx);
	return (E_OK);
}

static int	create_minimap(t_game *game)
{
	game->minimap = ft_calloc(1, sizeof(t_minimap));
	if (game->minimap == NULL)
		return (E_FAIL);
	game->minimap->size.h = game->win->size.h * 0.09;
	game->minimap->size.w = game->win->size.w * 0.18;
	if (game->minimap->size.h < 20 || game->minimap->size.w < 20)
	{
		game->minimap->size.h = 20;
		game->minimap->size.w = 20;
	}
	game->minimap->img = mlx_new_image(game->win->mlx, game->minimap->size.w,
			game->minimap->size.h);
	if (game->minimap->img == NULL)
		return (print_error("Could not create minimap image\n"));
	game->minimap->entity_size.h = (game->minimap->size.h / game->map->size.h);
	game->minimap->entity_size.w = (game->minimap->size.w
			/ game->map->max_cols);
	game->minimap->floor_color.hex = MIN_FLOOR_COLOR;
	game->minimap->wall_color.hex = MIN_WALL_COLOR;
	game->minimap->dir_line_color.hex = MIN_DIR_LINE_COLOR;
	game->minimap->player_color.hex = MIN_PLAYER_COLOR;
	return (E_OK);
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
	if (load_gun_textures(game->gun_texture) != E_OK)
		return (E_FAIL);
	if (set_bg_colors(game) != E_OK)
		return (E_FAIL);
	if (create_map(game) != E_OK)
		return (E_FAIL);
	if (create_player(game) != E_OK)
		return (E_FAIL);
	if (check_map_border(game) != E_OK)
		return (E_FAIL);
	if (create_window(game) != E_OK)
		return (E_FAIL);
	game->player->ray.tex.texture = game->wall_texture;
	game->background_img = mlx_new_image(game->win->mlx, WIN_WIDTH, WIN_HEIGHT);
	game->main_img = mlx_new_image(game->win->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (create_minimap(game) != E_OK)
		return (E_FAIL);
	return (E_OK);
}
