/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 09:28:46 by angomes-          #+#    #+#             */
/*   Updated: 2024/07/12 15:49:26 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

double	degrees_to_radians(double degrees)
{
	double	result;

	result = ((degrees * M_PI) / 180.0);
	return (result);
}

double	radiants_to_degrees(double radians)
{
	double	result;

	result = ((radians * 180.0) / M_PI);
	return (result);
}

double	abs_double(double number)
{
	if (number < 0)
		return (-number);
	else
		return (number);
}
