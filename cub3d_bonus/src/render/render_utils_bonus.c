/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:05:30 by angomes-          #+#    #+#             */
/*   Updated: 2024/07/12 15:50:46 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_screen(mlx_image_t *img, t_line line, unsigned int color,
		void (*func)(mlx_image_t *img, t_line line, unsigned int color))
{
	func(img, line, color);
}

void	clear_image(mlx_image_t *img, int height, int width)
{
	ft_memset(img->pixels, 0, height * width * 4);
}
