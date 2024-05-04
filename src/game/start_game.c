/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:56:46 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/03 21:23:07 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	start_game(t_game *game)
{
	printf("Start game\n");
	if (!init_data(game))
		return (E_FAIL);
	if (!game_loop(game))
    return (E_FAIL);
	end_game(game);
  printf("End game\n");
	return (E_SUCCESS);
}
