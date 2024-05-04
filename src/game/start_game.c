/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:56:46 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/04 03:20:37 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	start_game(t_game *game)
{
	printf("Start game\n");
	if (init_data(game) != E_OK)
  {
    printf("Fail init data\n");
		return (E_FAIL);
  } 
	if (game_loop(game) != E_OK)
  {
    printf("Fail game loop\n");
    return (E_FAIL);
  }
	end_game(game);
  printf("End game\n");
	return (E_OK);
}
