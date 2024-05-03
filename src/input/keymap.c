/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 21:27:07 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/02 21:29:20 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void hook_close_window(void *param)
{
  t_window *win = (t_window *)param;
  if (mlx_is_key_down(win->mlx, MLX_KEY_ESCAPE))
    mlx_close_window(win->mlx);
}
