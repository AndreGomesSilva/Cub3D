/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:37:37 by angomes-          #+#    #+#             */
/*   Updated: 2024/05/28 17:37:28 by angomes-         ###   ########.fr       */
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

# define WIN_WIDTH 1024
# define WIN_HEIGHT 512
# define MIN_WIDTH 640
# define MIN_HEIGHT 480
# define PI 3.14159265358979323846
# define TILE_SIZE 30
# define MOVEMENT_SPEED 1

// texture paths for the sprites
# define WALL_PATH "./assets/textures/wall/tile118.png"
# define FLOOR ""
# define CEILING ""
# define PLAYER_PATH "./assets/textures/door/door0.png"

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
	T_FLOOR = 2,
	T_CEILING = 3
}					t_type;

typedef enum e_direction
{
	NORTH = 0,
	EAST = 1,
	SOUTH = 2,
	WEST = 3
}					t_direction;

/** component point
 * struct with reference to x and y
 *
 * @param x -> x
 * @param y -> y
 */
typedef struct s_point
{
	int				x;
	int				y;
}					t_point;

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
 * @param h -> hexadecimal
 */
typedef struct s_color
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	unsigned int	hex;
}					t_color;

/** component sprite
 * struct that hold the sprite of entity
 *
 * @param size -> size with width and height of the sprite
 * @param img -> image of the sprite
 * @param texture -> texture of the sprite
 * @param path -> path of the sprite
 * @param direct -> direction of the sprite
 * @param color -> color of the sprite
 * @param next -> next sprite
 */
// typedef struct s_sprite
// {
// 	t_dimension		size;
// 	mlx_image_t		*img;
// 	mlx_texture_t	*texture;
// 	char			*path;
// 	t_direction		dir;
// 	t_color			color;
// 	struct s_sprite	*next;
// }					t_sprite;

/* --------------------------------------------------------------*/

/*                            ENTITYS                           */

/** entity line
 * struct that holds the line
 *
 * @param start -> start of the line
 * @param end -> end of the line
 * @param sprite -> sprite of the line
 */
typedef struct s_line
{
	t_point			start;
	t_point			end;
	t_color			color;
}					t_line;

/** entity fov
 * struct that holds the fov
 *
 * @param angle -> angle of the fov
 * @param l_line -> line of the fov
 * @param r_line -> line of the fov
 */
typedef struct s_fov
{
	float			angle;
	t_line			l_line;
	t_line			r_line;
}					t_fov;

/** entity player
 * struct that represents the player
 * @param pos_map -> position of the player in map
 * @param pos_pix -> position of the player in pixel
 * @param sprite -> sprite of the player
 * @param dir -> direction of the player
 * @param dir_line -> line of the player
 */
typedef struct s_player
{
	t_point			pos_pix;
	t_point			pos_map;
	t_direction		dir;
	t_line			dir_line;
	t_line			plane;
	t_fov			fov;
}					t_player;

/** entity walls
 * struct that represents all walls
 *
 * @param id -> a integer number that represents the id
 * @param pos -> position of the wall
 * @param sprite -> sprite of the wall
 */
// typedef struct s_walls
// {
// 	t_vec			pos;
// 	t_sprite		*sprite;
// }					t_walls;
//
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
 * @param path -> path of the map
 * @param size -> size of the map
 */
typedef struct s_map
{
	char			**mtx;
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
	mlx_image_t		*minimap;
	t_player		player;
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
void				move_keyhook(mlx_key_data_t keydatam, void *param);

// movement
void				handle_movement(t_player *player, t_map *map,
						t_direction direct);
t_bool				check_hit_wall(t_map *map, int x, int y,
						t_direction direct);

// draw
void				draw_line(mlx_image_t *img, t_line *line);
void				draw_circle(mlx_image_t *img,
						unsigned int color);
void				draw_rect(t_window *win, mlx_image_t *img,
						unsigned int color);
unsigned int		rgb_to_hex(int r, int g, int b);
void				set_color(t_color *color, int r, int g, int b);

// map
char				**get_map(char *str);

//render
int					render_minimap(t_game *game);

// vectors
void				set_vector(t_point *point, int x, int y);

// free
void				handle_free(t_game *game);

#endif
