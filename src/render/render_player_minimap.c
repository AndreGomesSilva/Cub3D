/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player_minimap.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:00:55 by angomes-          #+#    #+#             */
/*   Updated: 2024/06/29 19:09:32 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void draw_dir_line(t_minimap *minimap, t_player *player) {

  minimap->dir_line.start.x =  minimap->player_pos.x;
  minimap->dir_line.start.y =  minimap->player_pos.y;
  minimap->dir_line.end.x = minimap->player_pos.x;
  minimap->dir_line.end.y = minimap->player_pos.y - 10;
  minimap->dir_line = rotate_line(minimap->dir_line, radiants_to_degrees(player->angle));
  draw_screen(minimap->img, minimap->dir_line, minimap->dir_line_color.hex, draw_line);
}

void draw_player_minimap(t_minimap *minimap, t_player *player) {
  t_line line;
  
  minimap->player_pos.x = player->grid_pos.x * minimap->player_size.w;
  minimap->player_pos.y = player->grid_pos.y * minimap->player_size.h;
  line.start.x = minimap->player_pos.x;
  line.start.y = minimap->player_pos.y;
  line.end.x = line.start.x + 4;
  line.end.y = line.start.y + 4;
  draw_screen(minimap->img, line, minimap->player_color.hex, draw_circle);
  draw_dir_line(minimap, player);
}
