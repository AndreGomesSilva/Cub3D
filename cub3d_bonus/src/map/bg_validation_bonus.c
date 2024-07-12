/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bg_validation_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:31:03 by angomes-          #+#    #+#             */
/*   Updated: 2024/07/12 15:48:38 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	has_two_commas(char *line)
{
	int	i;
	int	number_of_commas;

	i = 0;
	number_of_commas = 0;
	while (line[i])
	{
		if (line[i] == ',')
			number_of_commas++;
		if (number_of_commas > 2)
			return (print_error("badly formatted background colors\n"));
		i++;
	}
	return (E_OK);
}

static int	set_floor_color(char *floor_content, t_color *floor)
{
	char	**rgb;

	if (has_two_commas(floor_content) != E_OK)
		return (E_FAIL);
	rgb = ft_split(floor_content, ',');
	if (rgb[0] != NULL && rgb[1] != NULL && rgb[2] != NULL && rgb[3] == NULL)
	{
		if (parse_colors(floor, rgb) != E_OK)
		{
			free_matrix(rgb);
			return (E_FAIL);
		}
	}
	else
	{
		free_matrix(rgb);
		return (print_error("Badly formatted floor color \n"));
	}
	free_matrix(rgb);
	return (E_OK);
}

static int	set_ceiling_color(char *ceiling_content, t_color *ceiling)
{
	char	**rgb;

	if (has_two_commas(ceiling_content) != E_OK)
		return (E_FAIL);
	rgb = ft_split(ceiling_content, ',');
	if (rgb[0] != NULL && rgb[1] != NULL && rgb[2] != NULL && rgb[3] == NULL)
	{
		if (parse_colors(ceiling, rgb) != E_OK)
		{
			free_matrix(rgb);
			return (E_FAIL);
		}
	}
	else
	{
		free_matrix(rgb);
		return (print_error("Badly formatted ceiling color \n"));
	}
	free_matrix(rgb);
	return (E_OK);
}

int	set_bg_colors(t_game *game)
{
	if (set_ceiling_color(game->file_content[C], &game->ceiling) != E_OK)
		return (E_FAIL);
	if (set_floor_color(game->file_content[F], &game->floor) != E_OK)
		return (E_FAIL);
	return (E_OK);
}
