/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bg_validation_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:46:36 by angomes-          #+#    #+#             */
/*   Updated: 2024/07/06 14:58:52 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	rgb_is_number(char **rgb)
{
	int	i;
	int	j;

	i = 0;
	while (rgb[i] != NULL)
	{
		j = 0;
		while (rgb[i][j])
		{
			if (ft_isdigit(rgb[i][j]) == FALSE)
				return (print_error("Color must be a non negative number\n"));
			j++;
		}
		i++;
	}
	return (E_OK);
}

int	parse_colors(t_color *bg_element, char **rgb)
{
	int	r;
	int	g;
	int	b;

	if (rgb_is_number(rgb) == E_FAIL)
		return (E_FAIL);
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if ((r < 0 || g < 0 || b < 0) || (r > 255 || g > 255 || b > 255))
		return (print_error("Color must be a number between 0 and 255\n"));
	bg_element->hex = get_hex_color(bg_element, r, g, b);
	return (E_OK);
}
