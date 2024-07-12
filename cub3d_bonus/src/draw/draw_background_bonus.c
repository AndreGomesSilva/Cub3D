/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:55:53 by iusantos          #+#    #+#             */
/*   Updated: 2024/07/12 15:47:19 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	draw_floor(mlx_image_t *img, t_color *floor)
{
	int	i;
	int	j;

	j = WIN_HEIGHT / 2;
	while (j < WIN_HEIGHT)
	{
		i = 0;
		while (i < WIN_WIDTH)
		{
			mlx_put_pixel(img, i, j, floor->hex);
			i++;
		}
		j++;
	}
}

static void	draw_ceiling(mlx_image_t *img, t_color *ceiling)
{
	int	i;
	int	j;

	j = 0;
	while (j < WIN_HEIGHT / 2)
	{
		i = 0;
		while (i < WIN_WIDTH)
		{
			mlx_put_pixel(img, i, j, ceiling->hex);
			i++;
		}
		j++;
	}
}

void	draw_background(t_game *game)
{
	draw_floor(game->background_img, &game->floor);
	draw_ceiling(game->background_img, &game->ceiling);
}
