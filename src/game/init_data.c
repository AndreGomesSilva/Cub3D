/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:50:21 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/03 22:08:32 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static t_walls	*create_walls_default_values()
{
	t_walls	*walls;

	walls = ft_calloc(1, sizeof(t_walls));
	walls->color.r = 255;
	walls->color.g = 0;
	walls->color.b = 128;
	walls->color.a = 0;
	walls->color.hex = rgb_to_hex(walls->color.r, walls->color.g,
			walls->color.b, walls->color.a);
  walls->size.w = 20;
  walls->size.h = 20;
	return (walls);
}

static t_window	*create_window_default_values()
{
	t_window	*window;

	window = ft_calloc(1, sizeof(t_window));
	window->size.w = WIDTH;
	window->size.h = HEIGHT;
  window->mlx = mlx_init(window->size.w, window->size.h, "Cub3D", TRUE);
  if (!window->mlx)
    return (NULL);
	return (window);
}

static t_player	*create_player_default_values()
{
	t_player	*player;

	player = ft_calloc(1, sizeof(t_player));
	return (player);
}

int	init_data(t_game *game)
{
	game->win = create_window_default_values();
  game->walls = create_walls_default_values();
  game->player = create_player_default_values();
	return (E_SUCCESS);
}
