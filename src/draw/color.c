/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 21:46:48 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/03 21:48:37 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

unsigned int	rgb_to_hex(int r, int g, int b, int a)
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
  if (a < 0)
    a = 0;
  else if (a > 255)
    a = 255;
	hex_color = (r << 16) | (g << 8) | b;
	return (hex_color);
}
