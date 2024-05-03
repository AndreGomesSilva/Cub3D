/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:37:37 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/03 18:25:42 by angomes-         ###   ########.fr       */
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

/*                            COMPONENT                           */

// struct of position
typedef struct s_position
{
	int x; //x position
	int y; //y position
}			t_position;

typedef struct s_dimension
{
	int w; //width
	int h; //height
}			t_dimension;

typedef struct s_color
{
	int r; //red
	int g; //green
	int b; //blue
}			t_color;

// struct of sprite
typedef struct s_sprite
{
	t_position pos;   //x and y
	t_dimension size; //width and height
}			t_sprite;

/* --------------------------------------------------------------*/

/*                            ENTITY                           */

// struct of player
typedef struct s_player
{
	t_position pos;  //x and y
	t_sprite sprite; //sprite
}			t_player;

// struct of wall
typedef struct s_wall
{
	t_position pos;   //x and y
	t_dimension size; //width and height
	t_color color;    //color
	t_sprite sprite;  //sprite
}			t_wall;

/* --------------------------------------------------------------*/

/*                            SYSTEM                           */

// struct of window
typedef struct s_window
{
	mlx_t *mlx;       //pointer to mlx
	t_dimension size; //width and height
}			t_window;

// struct of map
typedef struct s_map
{
	char **map;       //matrix of map
	t_dimension size; //size of map
}			t_map;

// struct of game
typedef struct s_game
{
	t_map *map;       //pointer to map
	t_window *win;    //pointer to window
	t_player *player; //pointer to player
	int error;        //hold the error value if 0 then no error
}			t_game;

/* --------------------------------------------------------------*/

// init
int			init_game(t_game *game);
int			set_data(t_game *game);

// input
void		hook_close_window(void *param);

// draw
mlx_image_t	*draw_rect(t_window *win, int w, int h, unsigned int color);

//map

#endif
