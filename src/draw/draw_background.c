/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:55:53 by iusantos          #+#    #+#             */
/*   Updated: 2024/06/13 17:23:45 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_floor(mlx_image_t *img)
{
	int i;
	int j;

	j = WIN_HEIGHT / 2;
	while (j < WIN_HEIGHT)
	{
		i = 0;
		while (i < WIN_WIDTH)
		{
			mlx_put_pixel(img, i, j, FLOOR_COLOR); 
			i++;
		}
		j++;
	}
}

static void draw_ceiling(mlx_image_t *img)
{
	int i;
	int j;

	j = 0;
	while (j < WIN_HEIGHT / 2)
	{
		i = 0;
		while (i < WIN_WIDTH)
		{
			mlx_put_pixel(img, i, j, CEILING_COLOR); 
			i++;
		}
		j++;
	}

}

void	draw_background(mlx_image_t *img)
{
	draw_floor(img);
	draw_ceiling(img);
}
