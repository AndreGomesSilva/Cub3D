/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 20:37:39 by angomes-          #+#    #+#             */
/*   Updated: 2024/06/04 21:08:30 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_point	rotate_point(t_point p, double angle_radians)
{
	t_point	result;
	double	cos_theta;
	double	sin_theta;

	cos_theta = cos(angle_radians);
	sin_theta = sin(angle_radians);
	result.x = (int)round(p.x * cos_theta - p.y * sin_theta);
	result.y = (int)round(p.x * sin_theta + p.y * cos_theta);
	return (result);
}

t_vec	rotate_vector(t_vec vec, double angle_radians)
{
	t_vec	result;
	t_point	translated_end_p;
	t_point	rotated_end_p;

	result.start_p = vec.start_p; 
	translated_end_p.x = vec.end_p.x - vec.start_p.x;
	translated_end_p.y = vec.end_p.y - vec.start_p.y;
	rotated_end_p = rotate_point(translated_end_p, angle_radians);
	result.end_p.x = rotated_end_p.x + vec.start_p.x;
	result.end_p.y = rotated_end_p.y + vec.start_p.y;
	return (result);
}
