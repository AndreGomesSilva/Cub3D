/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:11:50 by angomes-          #+#    #+#             */
/*   Updated: 2024/06/14 21:31:29 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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

static t_point	get_distance(double angle)
{
	t_point	dis;
	double	cosent;
	double	sinent;

	cosent = cos(degrees_to_radians(angle));
	sinent = sin(degrees_to_radians(angle));
	cosent = abs_double(cosent);
	sinent = abs_double(sinent);
	dis.y = cosent;
	dis.x = sinent;
	return (dis);
}

t_point get_quadrant_direction(double angle, t_move move)
{
  t_point dir;
  
  dir.x = 0;
  dir.y = 0;
  if ((move == UP && (angle < 90 || angle > 270)) || (move == DOWN && angle > 90 && angle < 270))
    dir.y = -1;
  else  if ((move == UP && angle > 90 && angle < 270) || (move == DOWN && (angle < 90 || angle > 270)))
    dir.y = 1;
  if ((move == UP && angle < 360 && angle > 180) || (move == DOWN && angle < 180 && angle > 0))
    dir.x = -1;
  else  if ((move == UP && angle < 180 && angle > 0) || (move == DOWN && angle < 360 && angle > 180))
    dir.x = 1;
  return (dir);
}

t_point	get_new_pos(t_point pos, t_point dist, t_point dir, double speed)
{
  t_point new_pos;
  
  new_pos.x = pos.x;
  new_pos.y = pos.y;
  if (dir.x == 1)
    new_pos.x = pos.x + speed * dist.x;
  else
    new_pos.x = pos.x - speed * dist.x;
  if (dir.y == 1)
    new_pos.y = pos.y + speed * dist.y;
  else 
    new_pos.y = pos.y - speed * dist.y;
	return (new_pos);
}

t_point	move_entity(t_point pos, double angle, t_move move, double speed)
{
	t_point		dist;
  t_point   dir;
	t_point		new_pos;

	dist = get_distance(angle);
  dir = get_quadrant_direction(angle, move);
  new_pos = get_new_pos(pos, dist, dir, speed);
	return (new_pos);
}
