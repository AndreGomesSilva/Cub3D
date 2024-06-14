/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:11:50 by angomes-          #+#    #+#             */
/*   Updated: 2024/06/14 11:53:25 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_cardinal	get_cardinal(double angle)
{
	if (angle == 270)
		return (W);
	else if (angle == 180)
		return (S);
	else if (angle == 90)
		return (E);
	else if (angle > 0 && angle < 90)
		return (NE);
	else if (angle > 90 && angle < 180)
		return (SE);
	else if (angle > 180 && angle < 270)
		return (SW);
	else if (angle > 270 && angle < 360)
		return (NW);
	return (N);
}

double	rotate_entity(double prev_angle, double next_angle, t_move move)
{
	double	new_angle;

	if (move == LEFT)
	{
		if (prev_angle == 0)
			new_angle = 360;
		else
			new_angle = prev_angle - next_angle;
	}
	else if (move == RIGHT)
	{
		if (prev_angle == 360)
			new_angle = 0;
		else
			new_angle = prev_angle + next_angle;
	}
	return (new_angle);
}

static t_point	get_new_pos(double angle)
{
	t_point	pos;
	double	cosent;
	double	sinent;

	cosent = cos(degrees_to_radians(angle));
	sinent = sin(degrees_to_radians(angle));
	if (cosent < 0)
		cosent *= -1;
	if (sinent < 0)
		sinent *= -1;
	pos.y = cosent;
	pos.x = sinent;
	return (pos);
}

t_point	move_entity(t_point pos, double angle, t_move move, double speed)
{
	t_point		new_end_point;
  t_point   new_pos;
	t_cardinal	card;

	new_end_point = get_new_pos(angle);
	card = get_cardinal(angle);
	if ((move == UP && card == N) || (move == DOWN && card == S))
		pos.y -= speed;
	else if ((move == UP && card == NE) || (move == DOWN && card == SW))
	{
		pos.y -= speed * new_end_point.y;
		pos.x += speed * new_end_point.x;
	}
	else if ((move == UP && card == E) || (move == DOWN && card == W))
		pos.x += speed;
	else if ((move == UP && card == SE) || (move == DOWN && card == NW))
	{
		pos.y += speed * new_end_point.y;
		pos.x += speed * new_end_point.x;
	}
	else if ((move == UP && card == S) || (move == DOWN && card == N))
		pos.y += speed;
	else if ((move == UP && card == SW) || (move == DOWN && card == NE))
	{
		pos.y += speed * new_end_point.y;
		pos.x -= speed * new_end_point.x;
	}
	else if ((move == UP && card == W) || (move == DOWN && card == E))
		pos.x -= speed;
	else if ((move == UP && card == NW) || (move == DOWN && card == SE))
	{
		pos.y -= speed * new_end_point.y;
		pos.x -= speed * new_end_point.x;
	}
	else if ((move == UP && card == N) || (move == DOWN && card == S))
		pos.y -= speed;
	new_pos = pos;
	return (new_pos);
}
