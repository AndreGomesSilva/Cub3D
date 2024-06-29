/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:25:39 by angomes-          #+#    #+#             */
/*   Updated: 2024/06/29 14:30:51 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	free_sprites(t_sprite *sprite)
// {
// 	t_sprite	*tmp;
// 	t_sprite	*next;
//
// 	tmp = sprite;
// 	while (tmp)
// 	{
// 		next = tmp->next;
// 		free(tmp);
// 		tmp = next;
// 	}
// }

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
  if (game->minimap)
    free(game->minimap);
	if (game->player)
  {
		free(game->player);
  }
	if (game)
		free(game);
}
