/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:24:08 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/30 20:04:27 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// void	draw_circle(mlx_image_t *img, t_dimension init_dim, t_dimension final_dim, unsigned int color)
// {
// 	int	i;
// 	int	j;
// 	int	w;
// 	int	h;
//
// 	i = 0;
// 	w = img->width;
// 	h = img->height;
// 	while (i < h)
// 	{
// 		j = 0;
// 		while (j < w)
// 		{
// 			if (((j - w / 2) * (j - w / 2)) + ((i - h / 2) * (i - h / 2)) < (w
// 					/ 2) * (w / 2))
// 				mlx_put_pixel(img, j, i, color);
// 			j++;
// 		}
// 		i++;
// 	}
// }
