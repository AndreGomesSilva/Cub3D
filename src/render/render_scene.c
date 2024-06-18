/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:36:35 by iusantos          #+#    #+#             */
/*   Updated: 2024/06/18 18:02:11 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_scene(t_game *game)
{
	int x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		game->player->ray.camera_x = 2 * x / (double) WIN_WIDTH - 1;
		game->player->ray.dir.x = game->player->dir.x + game->player->plane.x * game->player->ray.camera_x;
		game->player->ray.dir.y = game->player->dir.y + game->player->plane.y * game->player->ray.camera_x;
	}
}
