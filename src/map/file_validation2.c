/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validation2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:18:26 by angomes-          #+#    #+#             */
/*   Updated: 2024/07/06 10:55:47 by angomes-         ###   ########.fr       */
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

static int	store_elements(t_game *game, char **words)
{
	if (ft_strcmp(words[0], "NO") == 0 && game->file_content[NO] == NULL)
		game->file_content[NO] = ft_strdup(words[1]);
	else if (ft_strcmp(words[0], "SO") == 0 && game->file_content[SO] == NULL)
		game->file_content[SO] = ft_strdup(words[1]);
	else if (ft_strcmp(words[0], "EA") == 0 && game->file_content[EA] == NULL)
		game->file_content[EA] = ft_strdup(words[1]);
	else if (ft_strcmp(words[0], "WE") == 0 && game->file_content[WE] == NULL)
		game->file_content[WE] = ft_strdup(words[1]);
	else if (ft_strcmp(words[0], "F") == 0 && game->file_content[F] == NULL)
		game->file_content[F] = ft_strdup(words[1]);
	else if (ft_strcmp(words[0], "C") == 0 && game->file_content[C] == NULL)
		game->file_content[C] = ft_strdup(words[1]);
	else
		return (print_error("Duplicated element type in file.\n"));
	return (E_OK);
}

static int	handle_elements(t_game *game, char *line)
{
	char	**words;

	words = ft_split(line, ' ');
	if (words != NULL && words[0] != NULL && words[1] != NULL
		&& words[2] != NULL)
	{
		free_matrix(words);
		return (print_error("Badly formatted element line\n"));
	}
	if (words != NULL && words[0] != NULL && words[1] != NULL)
	{
		if (store_elements(game, words) != E_OK)
		{
			free_matrix(words);
			return (E_FAIL);
		}
	}
	free_matrix(words);
	return (E_OK);
}

static int	file_contents_is_set(char **file_contents)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (file_contents[i] == NULL)
			return (E_FAIL);
		i++;
	}
	return (E_OK);
}

int	check_elements(t_game *game, char *file_name)
{
	char	*line;

	game->fd = open(file_name, O_RDONLY);
	if (game->fd == -1)
		return (print_error("Could not open map file\n"));
	while (TRUE)
	{
		line = gnl_wo_nl(game->fd);
		if (!line)
			return (print_error("Not all elements were found in file.\n"));
		if (handle_elements(game, line) == E_FAIL)
		{
			free(line);
			close(game->fd);
			return (E_FAIL);
		}
		free(line);
		if (file_contents_is_set(game->file_content) == E_OK)
			return (E_OK);
	}
	return (E_OK);
}
