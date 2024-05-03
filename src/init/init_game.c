/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:56:46 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/03 18:39:59 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include <stdio.h>

int init_game(t_game *game)
{
  if (!set_data(game))  
    return (1);
  printf("Start game\n");
  game->win->mlx = mlx_init(game->win->size.w, game->win->size.h, "Cub3D", TRUE);
  if (!game->win->mlx)
    return (FALSE);
  mlx_loop_hook(game->win->mlx, &hook_close_window, game->win);
  mlx_loop(game->win->mlx);
  mlx_terminate(game->win->mlx);
  printf("End game\n");
  return (TRUE);
}
