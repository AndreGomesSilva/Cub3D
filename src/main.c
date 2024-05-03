/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:37:21 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/03 00:27:14 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(void)
{
  t_window *win;
  win = ft_calloc(1, sizeof(t_window));
  win->width = 800;
  win->height = 600;
  win->mlx = mlx_init(win->width, win->height, "Cub3D", TRUE);
  if (!win->mlx)
    perror("mlx init error");
  mlx_image_t *img = draw_rect(win, 100, 100, 0xFF0000FF);
  mlx_loop_hook(win->mlx, hook_close_window, win);
  mlx_loop(win->mlx);
  mlx_terminate(win->mlx);
  return (0);
}

