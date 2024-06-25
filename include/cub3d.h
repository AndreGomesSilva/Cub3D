/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:37:37 by angomes-          #+#    #+#             */
/*   Updated: 2024/06/25 18:43:03 by angomes-         ###   ########.fr       */
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

# define WIN_WIDTH 860
# define WIN_HEIGHT 640
# define MIN_WIDTH 480
# define MIN_HEIGHT 270
# define FOV M_PI / 3
# define TILE_SIZE 30
# define MOVEMENT_SPEED 0.4
# define ROTATION_SPEED 0.05

// Some colors
# define CEILING_COLOR 0x2986ccFF
# define FLOOR_COLOR 0x999999FF
# define WHITE 0xFFFFFF
# define RED 0xFF0000FF
# define GREEN 0x00FF00FF
# define BLUE 0x0000FFFF
# define BLACK 0x000000FF
# define YELLOW 0xFEE020FF
# define PURPLE 0x674EA7FF

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

/** component move
 * enum that represents the move in some cardinal direction
 * @param UP -> up
 * @param LEFT -> left
 * @param DOWN -> down
 * @param RIGHT -> right
 */
typedef enum e_move
{
	FORWARD,
	LEFT,
	BACKWARD,
	RIGHT,
	R_LEFT,
	R_RIGHT
}					t_move;

typedef enum e_wall
{
	NORTH,
	SOUTH,
	WEST,
	EAST
}					t_wall;

/** component type
 * enum that represents the type
 * @param T_PLAYER -> player
 * @param T_WALL -> wall
 * @param T_FLOOR -> floor
 * @param T_CEILING -> ceiling
 */
typedef enum e_type
{
	T_FLOOR = 0,
	T_WALL = 1,
	T_PLAYER = 2,
	T_CEILING = 3
}					t_type;

/** component point
 * struct with reference to x and y
 *
 * @param x -> (double) x
 * @param y -> (double) y
 */
typedef struct s_point
{
	double			x;
	double			y;
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
 * @param a -> alpha
 * @param h -> hexadecimal
 */
typedef struct s_color
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	unsigned int	a;
	unsigned int	hex;
}					t_color;

/** component ray
 *
 *
 * @param dir-> point with direction of ray
 * @param side_dist
        -> point with distance that ray must travel between grid lines (vertical
 and horizontal)
 * @param delta_dist
        -> point with distance that ray must travel until first grid line
 (vertical and horziontal)
 * @param perp_wall_dist
        -> perpendicular distance between where ray hit and projection plane
 * @param map_x -> which map column the ray is in
 * @param map_y -> which map row the ray is in
 * @param step_x -> right or left?
 * @param step_y -> up or down?
 * @param camera_x -> lame name
 */
typedef struct s_ray
{
	t_point			dir;
	t_point			side_dist;
	t_point			delta_dist;
	t_point			map;
	t_point			step;
	double			perp_wall_dist;
	t_wall				side_wall;
	unsigned int	color;
	double			camera_x;
}					t_ray;

/** entity line
 * struct that holds the line
 *
 * @param start -> start of the line
 * @param end -> end of the line
 * @param color -> color of the line
 */

typedef struct s_line
{
	t_point			start;
	t_point			end;
	t_color			color;
}					t_line;

typedef struct s_texture
{
	int				buffer[WIN_HEIGHT];
	double			step;
	double			pos;
	t_point			tex;
	double			wall_x;
	t_color			color;
}					t_texture;
/* --------------------------------------------------------------*/

/*                            ENTITYS                           */

/** entity fov
 * struct that holds the fov
 *
 * @param angle -> angle of the fov
 * @param l_line -> line of the fov
 * @param r_line -> line of the fov
 */
typedef struct s_fov
{
	t_line			l_line;
	t_line			r_line;
}					t_fov;

/** entity player
 * struct that represents the player
 * @param grid_pos -> grid position of the player
 * @param pix_pos -> pixel position of the player (oh the map file)
 * @param origin -> origin of the player (inside the grid block)
 * @param size -> size of the player
 * @param dir -> direction of the player
 * @param dir_line -> line of the player
 * @param plane -> camera plane of the player
 * @param fov -> field of view of the player
 * @param color -> color of the player
 */
typedef struct s_player
{
	t_point			grid_pos;
	t_point			pix_pos;
	t_point			origin;
	t_point			plane;
	t_point			dir;
	t_ray			ray;
	t_dimension		size;
	t_line			dir_line;
	t_line			plane_pos;
	t_line			plane_neg;
	double			angle;
	t_fov			fov;
	t_color			color;
	t_bool			has_moved;
}					t_player;

/** entity walls
 * struct that holds the walls
 *
 * @param size -> size of the walls
 * @param color -> color of the walls
 */
typedef struct s_walls
{
	t_dimension		size;
	t_color			color;
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
 * @param path -> path of the map
 * @param size -> size of the map
 */
typedef struct s_map
{
	char			**mtx;
	t_dimension		size;
}					t_map;

/** entity minimap
 * struct that holds the minimap
 *
 * @param img -> image of the minimap
 * @param walls -> walls of the minimap
 */
typedef struct s_screen
{
	mlx_image_t		*img;
	t_dimension		size;
	t_walls			walls;
	t_player		player;
}					t_screen;

/** system game
 * struct that holds the game main data
 *
 * @param map -> pointer to map
 * @param win -> pointer to window
 * @param player -> pointer to player
 * @param walls -> pointer to walls
 * @param error -> hold the error value if 0 then no error
 *
 */
typedef struct s_game
{
	t_map			*map;
	t_window		*win;
	t_player		*player;
	t_screen		*minimap;
	mlx_image_t		*minimap_img;
	mlx_image_t		*main_img;
	mlx_image_t		*background_img;
	mlx_texture_t	*wall_texture[4];
	t_err			error;
}					t_game;

/* --------------------------------------------------------------*/

/*                            SYSTEMS                           */

// game
int					start_game(char *str);
t_game				*init_data(char *str);
void				end_game(t_game *game);
int					game_loop(t_game *game);

// hook
void				hook_close_window(void *param);
void				move_keyhook(mlx_key_data_t keydatam, void *param);

// movement
void				handle_player_movement(t_player *player, t_map *map,
						t_move move);
double				rotate_entity(double prev_angle, double next_angle,
						t_move move);
t_point				move_entity(t_point pos, double angle, t_move move,
						double speed);

// draw

/**
 * Draws background (floor and ceiling) on img
 */
void				draw_background(mlx_image_t *img);
void				draw_line(mlx_image_t *img, t_line line,
						unsigned int color);
void				draw_circle(mlx_image_t *img, t_line line,
						unsigned int color);
unsigned int		rgb_to_hex(int r, int g, int b, int a);
void				draw_rect(mlx_image_t *img, t_line line,
						unsigned int color);
void				draw_minimap(t_game *game, t_map *map, t_dimension size);
void				draw_v_line(int col, int start, int end, unsigned int color,
						mlx_image_t *img);

// player
t_player			*create_player(t_map *map);

// map
char				**get_map(char *str);
int					get_num_col_map(char **map);
int					get_num_row_map(char **map);
void				set_transparent(t_color *color, int a);
unsigned int		get_hex_color(t_color *color, int r, int g, int b);
void				cover_screen(t_screen *screen, t_dimension size,
						unsigned int color);

// render

/**
 * Render background to game window (aka draws & put to window)
 */
void				render_background(t_game *game);
void				render_scene(t_game *game);
void				render_minimap(t_game *game);
void				update_minimap(t_game *game);
void				draw_screen(t_screen *screen, t_line line,
						unsigned int color, void (*func)(mlx_image_t *img,
							t_line line, unsigned int color));
void				update_player_origin(t_player *player);
t_line				get_line_grid_to_pix(t_point p, t_dimension size);
void				set_player_positions(t_player *player, t_point p);
void				update_player_minimap(t_screen *minimap);
void				draw_player_minimap(t_screen *minimap, t_player *player);
void				draw_minimap(t_game *game, t_map *map, t_dimension size);
void				update_minimap(t_game *game);

// math
t_line				rotate_line(t_line line, double angle_radians);
double				degrees_to_radians(double degrees);
double				radiants_to_degrees(double radians);
double				abs_double(double number);

// free
void				handle_free(t_game *game);

#endif
