/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 23:48:57 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/29 20:55:48 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void draw_rect_wall(mlx_image_t *img, int init_w, int init_h, t_walls *walls)
{
  int final_w;
  int final_h;
  int i;
  int j;
  
  final_w = init_w + walls->size.w;
  final_h = init_h + walls->size.h;
  i = init_h;
	while (i < (final_h - 1))
	{
    j = init_w;
		while (j < (final_w - 1))
		{
			mlx_put_pixel(img, j, i, walls->color.hex);
			j++;
		}
		i++;
	}
}
