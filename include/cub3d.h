/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:37:37 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/07 21:37:05 by angomes-         ###   ########.fr       */
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
# define PI 3.14159265358979323846

// texture paths for the sprites
# define WALL_PATH "./assets/textures/wall/tile118.png"
# define FLOOR ""
# define CEILING ""
# define PLAYER_PATH ""

/*                            COMPONENTS                          */

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

typedef enum e_type
{
	T_PLAYER = 0,
	T_WALL = 1,
	T_IMG_FLOOR = 2,
	T_IMG_CEILING = 3
}					t_type;

typedef enum e_direction
{
	NORTH = 0,
	EAST = 1,
	SOUTH = 2,
	WEST = 3
}					t_direction;

/** component position
 * struct with reference to x, y and z in a 2D space
 *
 * @param x -> x position
 * @param y -> y position
 * @param z -> z position
 */
typedef struct s_position
{
	int				x;
	int				y;
	int				z;
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
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	unsigned int	a;
	unsigned int	hex;
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
	char			*path;
	t_direction		direct;
	t_color			color;
	struct s_sprite	*next;
}					t_sprite;

/* --------------------------------------------------------------*/

/*                            ENTITYS                           */

/** entity player
 * struct that represents the player
 *
 * @param pos -> position of the player
 * @param sprite -> sprite of the player
 * @param direct -> direction of the player
 * @param color -> color of the player
 */
typedef struct s_player
{
	t_position		pos;
	t_sprite		*sprite;
	t_direction		direct;
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
	t_sprite		*sprite;
}					t_walls;

/** entity window
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

/** entity map
 * struct that holds the map
 *
 * @param mtx -> matrix of the map
 * @param size -> size of the map
 */
typedef struct s_map
{
	char			**mtx;
	char			*path;
	t_dimension		size;
}					t_map;

/** system game
 * struct that holds the game main data
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

/*                            SYSTEMS                           */

// game
int					start_game(char *str);
t_game				*init_data(char *str);
void				end_game(t_game *game);
int					game_loop(t_game *game);

// input
void				hook_close_window(void *param);

// draw
mlx_image_t			*draw_rect(t_window *win, int w, int h, unsigned int color);
unsigned int		rgb_to_hex(int r, int g, int b, int a);
void				set_color(t_color *color, int rgb[4]);

// map
char				**get_map(char *str);

//minimap
void				draw_minimap(t_game *game);

//sprite
t_sprite			*add_sprite(t_sprite *sprite);

// free
void				handle_free(t_game *game);

#endif
