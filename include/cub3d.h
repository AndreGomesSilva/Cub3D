/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:37:37 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/04 03:20:09 by angomes-         ###   ########.fr       */
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

# define WIDTH 800
# define HEIGHT 600

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}					t_bool;

typedef enum e_err
{
	E_FAIL = -1,
	E_OK = 0
}					t_err;

/*                            COMPONENT                           */

/** component position
 * struct with reference to x and y in a 2D space
 *
 * @param x -> x position
 * @param y -> y position
 */
typedef struct s_position
{
	int				x;
	int				y;
}					t_position;

/** component dimension
 * struct with reference to width and height
 *
 * @param w -> width
 * @param h -> height
 */
typedef struct s_dimension
{
	int				w;
	int				h;
}					t_dimension;

/** component color
 * struct with reference to red, green, blue and alpha
 *
 * @param r -> red
 * @param g -> green
 * @param b -> blue
 * @param a -> alpha
 */
typedef struct s_color
{
	unsigned int				r;
	unsigned int				g;
	unsigned int				b;
	unsigned int				a;
  unsigned int				hex;
}					t_color;

/** component sprite
 * struct that hold the sprite of entity
 *
 * @param size -> size with width and height of the sprite
 * @param img -> image of the sprite
 * @param texture -> texture of the sprite
 */
typedef struct s_sprite
{
	t_dimension		size;
	mlx_image_t		*img;
	mlx_texture_t	*texture;
}					t_sprite;

/* --------------------------------------------------------------*/

/*                            ENTITY                           */

/** entity player
 * struct that represents the player
 *
 * @param pos -> position of the player
 * @param sprite -> sprite of the player
 */
typedef struct s_player
{
	t_position pos;  //x and y
	t_sprite sprite; //sprite
}					t_player;

/** entity walls
 * struct that represents all walls
 *
 * @param id -> a integer number that represents the id
 * @param pos -> position of the wall 
 * @param size -> size of the wall 
 * @param color -> color of the wall 
 * @param sprite -> sprite of the wall
 */
typedef struct s_walls
{
	int				id;
	t_position		pos;
	t_dimension		size;
	t_color			color;
	t_sprite		sprite;
}					t_walls;

/* --------------------------------------------------------------*/

/*                            SYSTEM                           */

/** system window
 * struct that holds the window
 *
 * @param mlx -> pointer to the mlx window
 * @param size -> size of the window
 */
typedef struct s_window
{
	mlx_t			*mlx;
	t_dimension		size;
}					t_window;

/** system map
 * struct that holds the map
 *
 * @param map -> matrix of the map
 * @param size -> size of the map
 */
typedef struct s_map
{
	char			**map;
	t_dimension		size;
}					t_map;

/** system game
 * struc that holds the game main data
 *
 * @param map -> pointer to map
 * @param win -> pointer to window
 * @param player -> pointer to player
 * @param walls -> pointer to walls
 * @param error -> hold the error value if 0 then no error
 */
typedef struct s_game
{
	t_map			*map;
	t_window		*win;
	t_player		*player;
	t_walls			*walls;
	t_err			error;
}					t_game;

/* --------------------------------------------------------------*/

/*                            FUNCTION                           */

// game
int					start_game(t_game *game);
int					init_data(t_game *game);
void				end_game(t_game *game);
int					game_loop(t_game *game);

// input
void				hook_close_window(void *param);

// draw
mlx_image_t			*draw_rect(t_window *win, int w, int h, unsigned int color);
unsigned int		rgb_to_hex(int r, int g, int b, int a);

//map

//free
void				handle_free(t_game *game);

#endif
