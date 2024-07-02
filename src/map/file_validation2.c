/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validation2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:18:26 by angomes-          #+#    #+#             */
/*   Updated: 2024/07/02 17:41:56 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
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

static int store_if_valid_line(t_game *game, char *line)
{
	char **words;

	words = ft_split(line, ' ');
	if (words[2] != NULL)
	{
		free_matrix(words);
		return (print_error("Badly formatted element line\n"));
	}
	if (words != NULL && words[0] != NULL && words[1] != NULL)
	{
		if (ft_strcmp(words[0], "NO") == 0 && game->wall_texture_path[NORTH] == NULL)
			game->wall_texture_path[NORTH] = ft_strdup(words[1]);
		else if (ft_strcmp(words[0], "SO") == 0 && game->wall_texture_path[SOUTH] == NULL)
			game->wall_texture_path[SOUTH] = ft_strdup(words[1]);
		else if (ft_strcmp(words[0], "EA") == 0 && game->wall_texture_path[EAST] == NULL)
			game->wall_texture_path[EAST] = ft_strdup(words[1]);
		else if (ft_strcmp(words[0], "WE") == 0 && game->wall_texture_path[WEST] == NULL)
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

int check_elements(t_game *game, char *file_name)
{
  int fd;
  char *line;

  fd = open(file_name, O_RDONLY);
  if (fd == - 1)
    return (print_error("Could not open map file\n"));
  while(TRUE)
  {
    line = get_next_line(fd);
    if (!line)
      break;
    if(store_if_valid_line(game, line) == E_FAIL)
		return (E_FAIL); 
  } 
  return (E_OK);
}
