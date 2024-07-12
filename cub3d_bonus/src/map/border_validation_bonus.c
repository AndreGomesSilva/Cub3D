/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border_validation_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:22:05 by iusantos          #+#    #+#             */
/*   Updated: 2024/07/12 15:48:49 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static char	**init_rectangular_mtx(t_map *map)
{
	char	**rectangular_mtx;
	int		i;
	int		j;

	rectangular_mtx = ft_calloc(map->size.h + 1, sizeof(char *));
	i = 0;
	while (i < map->size.h)
	{
		rectangular_mtx[i] = ft_calloc(map->max_cols + 1, sizeof(char));
		i++;
	}
	i = 0;
	while (i < map->size.h)
	{
		j = 0;
		while (j < map->max_cols)
		{
			rectangular_mtx[i][j] = '0';
			j++;
		}
		rectangular_mtx[i][j] = '\0';
		i++;
	}
	return (rectangular_mtx);
}

static void	embed_matrix(char **small_mtx, char **big_mtx)
{
	int	row;
	int	col;

	row = 0;
	while (small_mtx[row] != NULL)
	{
		col = 0;
		while (small_mtx[row][col] != '\0')
		{
			big_mtx[row][col] = small_mtx[row][col];
			col++;
		}
		row++;
	}
}

static int	check_leak_borders(t_map *map, char **mtx)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (mtx[row][col] != '\0')
	{
		if (mtx[row][col] == '#')
			return (E_FAIL);
		col++;
	}
	row = map->size.h - 1;
	col = -1;
	while (mtx[row][++col] != '\0')
	{
		if (mtx[row][col] == '#')
			return (E_FAIL);
	}
	row = 0;
	while (++row < map->size.h)
	{
		if (mtx[row][0] == '#' || mtx[row][map->max_cols - 1] == '#')
			return (E_FAIL);
	}
	return (E_OK);
}

int	check_map_border(t_game *game)
{
	char	**rec_mtx;

	rec_mtx = init_rectangular_mtx(game->map);
	embed_matrix(game->map->mtx, rec_mtx);
	flood_fill(game->map, rec_mtx, (int)game->player->grid_pos.y,
		(int)game->player->grid_pos.x);
	if (check_leak_borders(game->map, rec_mtx) != E_OK)
	{
		free_matrix(rec_mtx);
		return (print_error("Leaky borders on map\n"));
	}
	free_matrix(rec_mtx);
	return (E_OK);
}
