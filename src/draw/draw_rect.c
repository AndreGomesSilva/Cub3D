/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 23:48:57 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/16 13:55:30 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

mlx_image_t	*draw_rect(t_window *win, int w, int h, unsigned int color)
{
	mlx_image_t	*img;
	int			i;
	int			j;

	img = mlx_new_image(win->mlx, w, h);
	i = 0;
	while (i < (h - 1))
	{
		j = 0;
		while (j < (w - 1))
		{
			mlx_put_pixel(img, j, i, color);
			j++;
		}
		i++;
	}
	return (img);
}