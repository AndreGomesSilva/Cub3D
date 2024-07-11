/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:56:46 by angomes-          #+#    #+#             */
/*   Updated: 2024/07/11 18:31:46 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	start_game(char *str)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	printf("Start game\n");
	if (init_data(&game, str) != E_OK)
	{
		handle_free(&game);
		return (print_error("Could not initializing data structure\n"));
	}
	game_loop(&game);
	end_game(&game);
	printf("End game\n");
	return (E_OK);
}
