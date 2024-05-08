/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:50:53 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/07 21:08:45 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"



int	init_sprites(t_game *game, enum e_type type)
{
	if (type == T_PLAYER)
	{
		game->player->sprite = create_player_sprite(game);
	}
}
