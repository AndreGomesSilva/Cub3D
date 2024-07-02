/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validation2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:18:26 by angomes-          #+#    #+#             */
/*   Updated: 2024/07/02 19:38:11 by iusantos         ###   ########.fr       */
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

static int	ft_strcmp(const char *s1, const char *s2)
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

static int parse_colors(t_game *game, char **rgb, char C_or_F)
{
  int r;
  int g;
  int b;

  r = ft_atoi(rgb[0]);
  g = ft_atoi(rgb[1]);
  b = ft_atoi(rgb[2]);
  if ((r < 0 || g < 0 || b < 0) || (r > 255 || g > 255 || b > 255))
    return (print_error("Invalid color\n"));
  if (C_or_F == 'C' && game->ceiling.a != 255)
    game->ceiling.hex = get_hex_color(&game->ceiling, r, g, b);
  else if (C_or_F == 'F' && game->floor.a != 255)
    game->floor.hex = get_hex_color(&game->floor, r, g, b);
  else 
	return (print_error("Floor or Ceiling setted more than once.\n"));
  return (E_OK);
}

static int	split_colors(t_game *game, char** words)
{
	char **rgb;

	rgb = ft_split(words[1], ',');
	if (rgb == NULL)
	{
		return (E_FAIL);
	}
	if (rgb[0] != NULL && rgb[1] != NULL && rgb[2] != NULL && rgb[3] == NULL)
	{
		if (parse_colors(game, rgb, words[0][0]) == E_FAIL)
		{
			free_matrix(rgb);
			return (E_FAIL);
		}
		free_matrix(rgb);
	}
	return (E_OK);
}

static int  store_if_valid_ceiling_floor_line(t_game *game, char *line)
{
   char **words;

  words = ft_split(line, ' ');
  if (words != NULL && words[2] != NULL)
  {
    free_matrix(words);
    return (print_error("Badly formatted element line\n"));
  }
  if (words != NULL && words[0] != NULL && words[1] != NULL)
  { 
    if (ft_strcmp(words[0], "F") == 0 || ft_strcmp(words[0], "C") == 0)
    {
		if (split_colors(game, words) == E_FAIL)
			{
				free_matrix(words);
				return (E_FAIL);
			}
	}
	free_matrix(words);
  }
	return (E_OK);
}

static int	store_if_valid_texture_line(t_game *game, char *line)
{
	char	**words;

	words = ft_split(line, ' ');
	if (words[2] != NULL)
	{
		free_matrix(words);
		return (print_error("Badly formatted element line\n"));
	}
	if (words != NULL && words[0] != NULL && words[1] != NULL)
	{
		if (ft_strcmp(words[0], "NO") == 0
			&& game->wall_texture_path[NORTH] == NULL)
			game->wall_texture_path[NORTH] = ft_strdup(words[1]);
		else if (ft_strcmp(words[0], "SO") == 0
				&& game->wall_texture_path[SOUTH] == NULL)
			game->wall_texture_path[SOUTH] = ft_strdup(words[1]);
		else if (ft_strcmp(words[0], "EA") == 0
				&& game->wall_texture_path[EAST] == NULL)
			game->wall_texture_path[EAST] = ft_strdup(words[1]);
		else if (ft_strcmp(words[0], "WE") == 0
				&& game->wall_texture_path[WEST] == NULL)
			game->wall_texture_path[WEST] = ft_strdup(words[1]);
		else
		{
			free_matrix(words);
			return (print_error("Duplicated texture element in file.\n"));
		}
	}
	free_matrix(words);
	return (E_OK);
}

int	check_elements(t_game *game, char *file_name)
{
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (print_error("Could not open map file\n"));
	while (TRUE)
	{
		line = gnl_wo_nl(fd);
		if (!line)
			break ;
		if (store_if_valid_texture_line(game, line) == E_FAIL)
			return (E_FAIL);
		if (store_if_valid_ceiling_floor_line( game, line) == E_FAIL)
			return (E_FAIL);

	}
	return (E_OK);
}
