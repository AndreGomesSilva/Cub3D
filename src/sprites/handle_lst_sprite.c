/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_lst_sprite.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:58:56 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/13 16:38:36 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_sprite *add_sprite(t_sprite *sprite)
{
  t_sprite *new;
  t_sprite *current;

  new = ft_calloc(1, sizeof(t_sprite)); 
  if (!new)
    return (NULL);
  new->next = NULL;
  current = sprite;
  if (!current)
    return (new);
  while (current->next)
    current = current->next;
  current->next = new;
  return (sprite);
}
