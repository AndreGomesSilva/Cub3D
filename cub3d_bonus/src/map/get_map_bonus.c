/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:04:01 by angomes-          #+#    #+#             */
/*   Updated: 2024/07/12 15:49:11 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static char	*ft_join(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
	{
		if (s1)
			free(s1);
		if (s2)
			free(s2);
		return (NULL);
	}
	ft_strlcpy(str, s1, s1_len + 1);
	ft_strlcat(str, s2, s1_len + s2_len + 1);
	free(s1);
	free(s2);
	return (str);
}

char	**get_map(int fd)
{
	char	*line;
	char	*all_lines;
	char	**mtx;

	all_lines = (char *)ft_calloc(1, sizeof(char));
	while (TRUE)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		all_lines = ft_join(all_lines, line);
	}
	close(fd);
	mtx = ft_split(all_lines, '\n');
	free(all_lines);
	return (mtx);
}
