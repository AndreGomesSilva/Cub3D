/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:27:34 by angomes-          #+#    #+#             */
/*   Updated: 2024/07/06 09:50:09 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_extension(char *file_name)
{
	char	*extension;
	size_t	len;

	len = ft_strlen(file_name);
	if (len < 5)
		return (E_FAIL);
	extension = file_name + len - 4;
	if (ft_strncmp(extension, ".cub", 4) == 0)
		return (E_OK);
	return (E_FAIL);
}

int	check_number_of_players(char **map_matrix)
{
	int	player_count;
	int	row;
	int	col;

	player_count = 0;
	row = 0;
	while (map_matrix[row] != NULL)
	{
		col = 0;
		while (map_matrix[row][col] != '\0')
		{
			if (ft_strchr("NSEW", map_matrix[row][col]) != NULL)
			{
				player_count++;
				if (player_count > 1)
					return (print_error("Too many players on map\n"));
			}
			col++;
		}
		row++;
	}
	if (player_count == 0)
		return (print_error("No player found on map\n"));
	return (E_OK);
}

int	check_for_invalid_character(char **map_matrix)
{
	int	row;
	int	col;

	row = 0;
	while (map_matrix[row] != NULL)
	{
		col = 0;
		while (map_matrix[row][col] != '\0')
		{
			if (ft_strchr(" 01NSEW", map_matrix[row][col]) == NULL)
			{
				return (print_error("Invalid character found on map\n"));
			}
			col++;
		}
		row++;
	}
	return (E_OK);
}

int	validate_file(t_game *game, char *file_name)
{
	if (check_extension(file_name) != E_OK)
		return (print_error("Invalid extension\n"));
	if (check_elements(game, file_name) != E_OK)
		return (E_FAIL);
	return (E_OK);
}
