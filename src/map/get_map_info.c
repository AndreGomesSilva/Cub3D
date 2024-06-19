/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 18:26:27 by angomes-          #+#    #+#             */
/*   Updated: 2024/06/19 17:32:16 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int get_num_row_map(char **map)
{
  int i;

  i = 0;
  while (map[i])
    i++;
  return (i);
}

int get_num_col_map(char **map)
{
  int i;
  int j;

  i = 0;
  while (map[i])
  {
    j = 0;
    while (map[i][j])
      j++;
    i++;
  }
  return (j);
}
