/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 21:46:48 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/16 13:51:27 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

unsigned int	rgb_to_hex(int r, int g, int b)
{
	unsigned int	hex_color;

	if (r < 0)
		r = 0;
	else if (r > 255)
		r = 255;
	if (g < 0)
		g = 0;
	else if (g > 255)
		g = 255;
	if (b < 0)
		b = 0;
	else if (b > 255)
		b = 255;
	hex_color = (r << 24) | (g << 16) | b << 8| (255 << 0);
	return (hex_color);
}

void set_color(t_color *color, int r, int g, int b)
{
  color->r = r;
  color->g = g;
  color->b = b;
  color->hex = rgb_to_hex(color->r, color->g, color->b);
}
