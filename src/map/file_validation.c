/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:27:34 by angomes-          #+#    #+#             */
/*   Updated: 2024/06/28 17:52:29 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int check_extension(char *file_name)
{
  char *extension;
  size_t len;

  len = ft_strlen(file_name);

  if (len < 5)
    return (E_FAIL);
  
  extension = file_name + len - 4;
  if (ft_strncmp(extension, ".cub", 4) == 0)
    return (E_OK);
  return (E_FAIL);
}

int	check_for_invalid_character(char **map_matrix)
{
	int row;
	int col;

	row = 0;
	while(map_matrix[row] != NULL)
	{
		col = 0;
		while(map_matrix[row][col] != '\0')
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

int validate_file(char *file_name)
{
  if (check_extension(file_name) != E_OK)
    return (print_error("Invalid extension\n"));

  return (E_OK);
}
