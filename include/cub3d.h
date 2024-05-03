/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:37:37 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/03 00:24:55 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/include/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define TRUE 1
# define FALSE 0

// struct of window
typedef struct s_window
{
	mlx_t	*mlx;
	unsigned int width;  //width of the window
	unsigned int height; //height of the window
}			t_window;

// input
void		hook_close_window(void *param);

// draw
mlx_image_t	*draw_rect(t_window *win, int w, int h, unsigned int color);

#endif
