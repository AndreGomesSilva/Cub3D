/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validation2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:18:26 by angomes-          #+#    #+#             */
/*   Updated: 2024/07/02 16:53:07 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static store_if_valid_line(t_game *game, char *line)
// {
//     
// }

int check_elements(t_game *game, char *file_name)
{
  int fd;
  char *line;

  fd = open(file_name, O_RDONLY);
  if (fd == - 1)
    return (print_error("Could not open map file\n"));
  while(TRUE)
  {
    line = get_next_line(fd);
    if (!line)
      break;
    // store_if_valid_line(game, line); 
  } 
  return (E_OK);
}
