/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:56:46 by angomes-          #+#    #+#             */
/*   Updated: 2024/06/28 16:57:44 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	start_game(char *str)
{
  t_game game;

	printf("Start game\n");
  if (init_data(&game, str) != E_OK)
    return (E_FAIL);
	if (game_loop(&game) != E_OK)
  {
    printf("Fail game loop\n");
    return (E_FAIL);
  }
	end_game(&game);
  printf("End game\n");
	return (E_OK);
}
