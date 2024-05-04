/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:25:39 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/03 21:54:11 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void handle_free(t_game *game)
{
  if (game->win)
    free(game->win);
  if (game->map)
    free(game->map);
  if (game->player)
    free(game->player);
  if (game->walls)
    free(game->walls);
  if (game)
    free(game);
}
