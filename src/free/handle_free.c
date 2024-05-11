/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:25:39 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/10 23:04:14 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	free_sprites(t_sprite *sprite)
{
	t_sprite	*tmp;
	t_sprite	*next;

	tmp = sprite;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
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
	if (game->player)
		free(game->player);
	if (game->walls)
	{
		free_sprites(game->walls->sprite);
		free(game->walls);
	}
	if (game)
		free(game);
}
