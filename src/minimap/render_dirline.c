/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_dirline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:51:15 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/20 20:20:46 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void  set_player_dirline(t_player *player)
{
  player->dir_line.start.x = 25; 
  player->dir_line.start.y = 0;
  player->dir_line.end.x = 25;
  player->dir_line.end.y = 50;
  player->dir_line.sprite = add_sprite(player->dir_line.sprite);
  set_color(&player->dir_line.sprite->color , 250, 240, 120);
}

void	render_dirline(t_window *win, t_player *player)
{
  set_player_dirline(player);
  player->dir_line.sprite->img = create_line(win, &player->dir_line);
  if (!player->dir_line.sprite->img)
  {
    printf( "Error\n" );
    return ;
  }
  mlx_image_to_window(win->mlx, player->dir_line.sprite->img, player->pos_pix.x, player->pos_pix.y);
}

