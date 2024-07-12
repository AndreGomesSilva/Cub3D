/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_line_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 20:37:39 by angomes-          #+#    #+#             */
/*   Updated: 2024/07/12 13:17:28 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_point	rotate_point(t_point p, double angle_radians)
{
	t_point	result;
	double	cos_theta;
	double	sin_theta;

	cos_theta = cos(angle_radians);
	sin_theta = sin(angle_radians);
	result.x = round(p.x * cos_theta - p.y * sin_theta);
	result.y = round(p.x * sin_theta + p.y * cos_theta);
	return (result);
}

t_line	rotate_line(t_line line, double angle_radians)
{
	t_line	result;
	t_point	translated_end_p;
	t_point	rotated_end_p;

	result.start = line.start;
	translated_end_p.x = line.end.x - line.start.x;
	translated_end_p.y = line.end.y - line.start.y;
	rotated_end_p = rotate_point(translated_end_p, angle_radians);
	result.end.x = rotated_end_p.x + line.start.x;
	result.end.y = rotated_end_p.y + line.start.y;
	return (result);
}
