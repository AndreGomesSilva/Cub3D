/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_background.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:31:48 by iusantos          #+#    #+#             */
/*   Updated: 2024/06/13 16:33:49 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_background(t_game *game)
{
	draw_background(game->background_img);
	mlx_image_to_window(game->win->mlx, game->background_img, 0, 0);
}
