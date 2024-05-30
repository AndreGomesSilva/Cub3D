/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 21:20:48 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/29 21:26:58 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void loop_mtx(char **mtx, char delimiter, void (* func)(char *, t_point))
{
  int x;
  int y;

  y = 0;
  while (y < WIN_HEIGHT)
  {
    x = 0;
    while (x < WIN_WIDTH)
    {
      if (mtx[y][x] == delimiter)
        func(mtx[y], (t_point){x, y});
      x++;
    }
    y++;
  }
}
