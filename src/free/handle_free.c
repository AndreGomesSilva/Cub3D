/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:25:39 by angomes-          #+#    #+#             */
/*   Updated: 2024/07/06 09:52:46 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_matrix(char **matrix)
{
	int	i;

	if (matrix == NULL)
		return ;
	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

static void	free_file_content(char **file_content)
{
	if (file_content[NO] != NULL)
		free(file_content[NO]);
	if (file_content[SO] != NULL)
		free(file_content[SO]);
	if (file_content[EA] != NULL)
		free(file_content[EA]);
	if (file_content[WE] != NULL)
		free(file_content[WE]);
	if (file_content[F] != NULL)
		free(file_content[F]);
	if (file_content[C] != NULL)
		free(file_content[C]);
}

void	free_textures(mlx_texture_t **wall_texture)
{
	if (wall_texture[NORTH] != NULL)
		mlx_delete_texture(wall_texture[NORTH]);
	if (wall_texture[SOUTH] != NULL)
		mlx_delete_texture(wall_texture[SOUTH]);
	if (wall_texture[EAST] != NULL)
		mlx_delete_texture(wall_texture[EAST]);
	if (wall_texture[WEST] != NULL)
		mlx_delete_texture(wall_texture[WEST]);
}

void	handle_free(t_game *game)
{
	if (game->win)
		free(game->win);
	if (game->map)
	{
		free_matrix(game->map->mtx);
		free(game->map);
	}
	free_file_content(game->file_content);
	free_textures(game->wall_texture);
	if (game->minimap)
		free(game->minimap);
	if (game->player)
	{
		free(game->player);
	}
}
