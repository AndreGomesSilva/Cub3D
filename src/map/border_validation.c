/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:22:05 by iusantos          #+#    #+#             */
/*   Updated: 2024/07/05 17:27:40 by angomes-         ###   ########.fr       */
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

static char **init_rectangular_mtx(t_map *map)
{
	char **rectangular_mtx;
	int i;
	int j;

	rectangular_mtx = ft_calloc(map->size.h + 1, sizeof(char*));
	i = 0;
	while(i < map->size.h)
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

static void embed_matrix(char **small_mtx, char **big_mtx)
{
  int row;
  int col;

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

int check_map_border(t_game *game)
{
	char **rec_mtx;

	rec_mtx = init_rectangular_mtx(game->map);
	printf("\n");
	print_map(rec_mtx);
  embed_matrix(game->map->mtx, rec_mtx);
	printf("\n");
	print_map(rec_mtx);
	//copy map->mtx to rec_mtx;
	//run flood_fill;
	//check_folld_fill;
	
	return 1;
}
