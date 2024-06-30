/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_player_movement.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:11:50 by angomes-          #+#    #+#             */
/*   Updated: 2024/06/30 16:59:07 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	rotate_minimap_player(double prev_angle, double next_angle, t_move move)
{
	double	new_angle;

	new_angle = prev_angle;
	if (move == R_LEFT)
	{
		if (prev_angle < 0)
			new_angle = 6.28;
		else
			new_angle = prev_angle - next_angle;
	}
	else if (move == R_RIGHT)
	{
		if (prev_angle > 6.28)
			new_angle = 0;
		else
			new_angle = prev_angle + next_angle;
	}
	return (new_angle);
}
