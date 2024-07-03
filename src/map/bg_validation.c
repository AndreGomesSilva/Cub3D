/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bg_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:31:03 by angomes-          #+#    #+#             */
/*   Updated: 2024/07/03 19:19:43 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	rgb_is_number(char **rgb)
{
	int	i;
	int	j;

	i = 0;
	while (rgb[i] != NULL)
	{
		j = 0;
		while (rgb[i][j])
		{
			if (ft_isdigit(rgb[i][j]) == FALSE)
				return (print_error("Color must be a non negative number\n"));
			j++;
		}
		i++;
	}
	return (E_OK);
}

static int	parse_colors(t_color *bg_element, char **rgb)
{
	int	r;
	int	g;
	int	b;

	if (rgb_is_number(rgb) == E_FAIL)
		return (E_FAIL);
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if ((r < 0 || g < 0 || b < 0) || (r > 255 || g > 255 || b > 255))
		return (print_error("Color must be a number between 0 and 255\n"));
	bg_element->hex = get_hex_color(bg_element, r, g, b);
	return (E_OK);
}

static int has_two_commas(char *line)
{
  int i;
  int number_of_commas;

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
