/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:37:37 by angomes-          #+#    #+#             */
/*   Updated: 2024/07/09 19:03:23 by angomes-         ###   ########.fr       */
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

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define FOV 1.0471975512
# define MOVEMENT_SPEED 0.2
# define ROTATION_SPEED 0.05
# define MOUSE_ROTATION_SPEED 0.01

// Some colors
# define MIN_FLOOR_COLOR 0x9CA9B199
# define MIN_WALL_COLOR 0x25252599
# define MIN_PLAYER_COLOR 0x81573DFF
# define MIN_DIR_LINE_COLOR 0xF44E40FF

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
 * @param UP -> up (move with W)
 * @param LEFT -> left (move with A)
 * @param DOWN -> down (move with S)
 * @param RIGHT -> right (move with D)
 * @param A_LEFT -> arrow left
 * @param A_RIGHT -> arrow right
 * @param M_LEFT -> mouse left move
 * @param M_RIGHT -> mouse right move
 */
typedef enum e_move
{
	FORWARD,
	LEFT,
	BACKWARD,
	RIGHT,
	A_LEFT,
	A_RIGHT,
	M_LEFT,
	M_RIGHT
}					t_move;

/** component wall
 * enum that represents the wall
 * @param NORTH -> north
 * @param SOUTH -> south
 * @param WEST -> west
 * @param EAST -> east
 */
typedef enum e_cardinal
{
	NORTH,
	SOUTH,
	WEST,
	EAST
}					t_cardinal;

/** component elements
 * enum that represents the elements
 * @param NO -> north
 * @param SO -> south
 * @param WE -> west
 * @param EA -> east
 * @param F -> floor
 * @param C -> ceiling
 */
typedef enum e_elements
{
	NO,
	SO,
	WE,
	EA,
	F,
	C
}					t_elements;

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
 * @param w -> (int) width
 * @param h -> (int) height
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

/** component texture
 * struct with reference to texture
 *
 * @param buffer -> pointer to buffer with texture column
 * @param step
 * @param pos
 * @param tex_col -> position of texture column
 * @param tex_row -> position of texture row
 * @param wall_x -> position of wall in the x axis
 * @param rgb -> color of the texture in rgb
 * @param color -> color of the texture converted to hexadecimal
 * @param texture  -> pointer of pointer to texture
 */
typedef struct s_texture
{
	int				buffer[WIN_HEIGHT];
	double			step;
	double			pos;
	int				tex_col;
	int				tex_row;
	double			wall_x;
	unsigned int	rgb;
	t_color			color;
	mlx_texture_t	**texture;
}					t_texture;

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
	int				line_height;
	t_cardinal		side_wall;
	t_texture		tex;
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

/* --------------------------------------------------------------*/

/*                            ENTITYS                           */

/** entity player
 * struct that represents the player_pos
 *
 * @param grid_pos -> grid position of the player
 * @param plane -> plane of the player
 * @param dir -> direction of the player
 * @param ray -> ray of the player
 * @param angle -> angle of the player
 * @param has_moved -> has the player moved
 */
typedef struct s_player
{
	t_point			grid_pos;
	t_point			plane;
	t_point			dir;
	t_ray			ray;
	double			rad_angle;
	t_bool			has_moved;
}					t_player;

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
 * @param max_cols -> maximum number of columns
 */
typedef struct s_map
{
	char			**mtx;
	t_dimension		size;
	int				max_cols;
}					t_map;

/** entity minimap
 * struct that holds the minimap
 *
 * @param img -> pointer to image
 * @param dir_line -> player direction line
 * @param player_pos -> position of the player in pixels
 * @param wall_color -> color of the wall
 * @param floor_color -> color of the floor
 * @param player_color -> color of the player
 * @param dir_line_color -> color of the direction line of the player
 * @param entity_size -> size of the entity
 * @param size -> size of the minimap (width and height)
 */
typedef struct s_minimap
{
	mlx_image_t		*img;
	int				dir_line;
	t_point			player_pos;
	t_color			wall_color;
	t_color			floor_color;
	t_color			player_color;
	t_color			dir_line_color;
	t_dimension		entity_size;
	t_dimension		size;
}					t_minimap;

/** system game
 * struct that holds the game main data
 *
 * @param map -> pointer to struct t_map
 * @param win -> pointer to window
 * @param player -> pointer to player
 * @param walls -> pointer to walls
 * @param minimap -> pointer to minimap
 * @param main_img -> pointer to main image
 * @param background_img -> pointer to background image
 * @param wall_texture -> pointer to wall
 * @param fd -> file descriptor
 * @param file_content
	-> array of string with texture and color ceiling and floor get from file input
 * @param floor -> floor color (already parsed)
 * @param ceiling -> ceiling color (already parsed)
 * @param mouse_x -> mouse x position
 * @param mouse_y -> mouse y position
 */
typedef struct s_game
{
	t_map			*map;
	t_window		*win;
	t_player		*player;
	int				mouse_x;
	int				mouse_y;
	t_minimap		*minimap;
	mlx_image_t		*main_img;
	mlx_image_t		*background_img;
	int				fd;
	char			*file_content[6];
	t_color			floor;
	t_color			ceiling;
	mlx_texture_t	*wall_texture[4];
}					t_game;

/* --------------------------------------------------------------*/

/*                            SYSTEMS                           */

// game
int					start_game(char *str);
int					init_data(t_game *game, char *str);
void				end_game(t_game *game);
int					game_loop(t_game *game);

// hook
void				hook_close_window(void *param);
void				move_keyhook(mlx_key_data_t keydatam, void *param);
void				handle_cursor(double x, double y, void *param);

// movement
void				handle_player_movement(t_player *player, t_map *map,
						t_move move);
double				rotate_minimap_player(double prev_angle, double next_angle,
						t_move move);

// draw

/**
 * Draws background (floor and ceiling) on img
 */
void				draw_background(t_game *game);
void				draw_line(mlx_image_t *img, t_line line,
						unsigned int color);
void				draw_circle(mlx_image_t *img, t_line line,
						unsigned int color);
unsigned int		rgb_to_hex(int r, int g, int b, int a);
unsigned int		get_hex_color(t_color *color, int r, int g, int b);
void				set_transparent(t_color *color, int a);
void				draw_rect(mlx_image_t *img, t_line line,
						unsigned int color);
void				draw_v_line(t_game *game, int col, int start, int end);

// player
int					create_player(t_game *game);

// map
int					validate_file(t_game *game, char *file_name);
int					check_for_invalid_character(char **map_matrix);
int					check_elements(t_game *game, char *file_name);
int					check_number_of_players(char **map_matrix);
char				**get_map(int fd);
int					get_num_col_map(char **map);
int					get_num_row_map(char **map);
int					get_max_col(char **mtx);
int					print_error(char *str);
int					set_bg_colors(t_game *game);
int					check_map_border(t_game *game);
int					parse_colors(t_color *bg_element, char **rgb);
int					ft_strcmp(const char *s1, const char *s2);
char				*gnl_wo_nl(int fd);
int					flood_fill(t_map *map, char **mtx, int y, int x);

// render
/**
 * Render background to game window (aka draws & put to window)
 */
void				render_background(t_game *game);
void				render_scene(t_game *game);
void				render_minimap(t_game *game);
void				draw_screen(mlx_image_t *img, t_line line,
						unsigned int color, void (*func)(mlx_image_t *img,
							t_line line, unsigned int color));
void				draw_player_minimap(t_minimap *minimap, t_player *player);
void				draw_minimap(t_minimap *minimap, t_map *map,
						t_dimension size);
void				texture_pre_render(t_ray *ray, t_point player_pos,
						int draw_start, int draw_end);
void				clear_image(mlx_image_t *img, int height, int width);
void				dda_loop(t_ray *ray, t_map *map);
void				create_vertical_line(t_game *game, int col);

// math
t_line				rotate_line(t_line line, double angle_radians);
double				degrees_to_radians(double degrees);
double				radiants_to_degrees(double radians);
double				abs_double(double number);

// free
void				handle_free(t_game *game);
void				free_matrix(char **matrix);

#endif
