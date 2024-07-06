/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:22:05 by iusantos          #+#    #+#             */
/*   Updated: 2024/07/06 09:50:37 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			printf("%c ", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

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

static int	flood_fill(t_map *map, char **mtx, int y, int x)
{
	if (y < 0 || y >= map->size.h || x < 0 || x >= map->max_cols
		|| mtx[y][x] == '1' || mtx[y][x] == '#')
		return (E_FAIL);
	mtx[y][x] = '#';
	flood_fill(map, mtx, y - 1, x);
	flood_fill(map, mtx, y + 1, x);
	flood_fill(map, mtx, y, x - 1);
	flood_fill(map, mtx, y, x + 1);
	return (E_OK);
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
	printf("\n");
	print_map(rec_mtx);
	embed_matrix(game->map->mtx, rec_mtx);
	printf("\n");
	print_map(rec_mtx);
	flood_fill(game->map, rec_mtx, (int)game->player->grid_pos.y,
		(int)game->player->grid_pos.x);
	printf("\n");
	print_map(rec_mtx);
	if (check_leak_borders(game->map, rec_mtx) != E_OK)
	{
		free_matrix(rec_mtx);
		return (print_error("Leaky borders on map\n"));
	}
	free_matrix(rec_mtx);
	return (E_OK);
}
