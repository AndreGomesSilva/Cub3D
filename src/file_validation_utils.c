/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validation_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:49:15 by angomes-          #+#    #+#             */
/*   Updated: 2024/07/06 15:03:05 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*gnl_wo_nl(int fd)
{
	char	*line;
	char	*s;

	line = get_next_line(fd);
	if (line)
	{
		s = ft_strtrim(line, "\n");
		free(line);
		return (s);
	}
	return (NULL);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	flood_fill(t_map *map, char **mtx, int y, int x)
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
