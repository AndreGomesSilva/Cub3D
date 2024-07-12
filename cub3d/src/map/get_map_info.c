/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 18:26:27 by angomes-          #+#    #+#             */
/*   Updated: 2024/07/12 16:02:38 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_num_row_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	get_num_col_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		i++;
	}
	return (j);
}

int	get_max_col(char **mtx)
{
	int	i;
	int	j;
	int	max_cols;

	max_cols = 0;
	i = 0;
	while (mtx[i] != NULL)
	{
		j = 0;
		while (mtx[i][j])
		{
			if (j > max_cols)
				max_cols = j;
			j++;
		}
		i++;
	}
	return (max_cols + 1);
}
