/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:24:08 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/16 14:01:42 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"



mlx_image_t	*draw_circle(t_window *win, int w, int h, unsigned int color)
{
	mlx_image_t	*img;
	int			i;
	int			j;


	img = mlx_new_image(win->mlx, w, h);
	i = 0;
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			if (((j - w / 2) * (j - w / 2)) + ((i - h / 2) * (i - h / 2)) < (w
					/ 2) * (w / 2))
				mlx_put_pixel(img, j, i, color);
			j++;
		}
		i++;
	}
	return (img);
}
