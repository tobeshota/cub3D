/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/02/25 18:35:58 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# include <stdbool.h>
# include <stdlib.h>

# define DISPLAY_W 720
# define DISPLAY_H 480
# define MINIMAP_SIDE 8
# define TEX_W 64
# define TEX_H 64
# define RGBA 4
# define EIGHT 256
# define MINIMAP_WALL_COLOR 0x00D2B69A
# define MINIMAP_FLOOR_COLOR 0x00BDC6A0
# define MINIMAP_PLAYER_COLOR 0x00FF0000

# define ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_Q 113
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

# define LEFT 0
# define RIGHT 1
# define KEY_PRESS 2
# define DESTROY_NOTIFY 17
# define DPI_W DISPLAY_W
# define DPI_H DISPLAY_H
# define CAMERA 1.32
# define MOVE 0.1
# define ROTATE 4
# define CIRCLE 360
# define MAX_SIZE 40
# define VECTOR 1
# define X_SIDE 0
# define Y_SIDE 1
# define WALL '1'
# define FLOOR '0'
# define NORTH 'N'
# define SOUTH 'S'
# define WEST 'W'
# define EAST 'E'
# define NO "NO"
# define SO "SO"
# define WE "WE"
# define EA "EA"
# define N 90
# define S 270
# define W 180
# define E 0
# define FL "F"
# define CE "C"
# define MINIMAP_FLOOR_PATH	"texture/minimap/floor.xpm"
# define MINIMAP_WALL_PATH	"texture/minimap/wall.xpm"
# define MINIMAP_PLAYER_PATH	"texture/minimap/player.xpm"

typedef struct s_mark
{
	size_t		no;
	size_t		so;
	size_t		we;
	size_t		ea;
	size_t		fl;
	size_t		ce;
	size_t		map;
}				t_mark;

typedef struct s_bfs
{
	bool		flag;
	size_t		x;
	size_t		y;
}				t_bfs;

typedef struct s_map
{
	char		**map;
	char		*no_texture;
	char		*so_texture;
	char		*we_texture;
	char		*ea_texture;
	int			*ce_color;
	int			*fl_color;
	bool		does_minimap_put;
}				t_map;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct s_texture
{
	int			tex_w;
	int			tex_h;
	t_img		*north;
	t_img		*south;
	t_img		*west;
	t_img		*east;
	void		*minimap_floor;
	void		*minimap_wall;
	void		*minimap_player;
}				t_texture;

typedef struct s_ray
{
	int			hit;
	int			angle;
	int			side_dir;
	int			int_posx;
	int			int_posy;
	int			mouse_x;
	int			mouse_y;
	int			stepx;
	int			stepy;
	double		raydirx;
	double		raydiry;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	double		raydist;
	int			wall_h;
	int			surplus;
	int			drawstart;
	int			drawend;
}				t_ray;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		camx;
	double		camy;
	t_img		*img;
	t_texture	*texture;
	t_ray		*ray;
}				t_game;

typedef struct s_data
{
	int			window_width;
	int			window_height;
	t_map		*map;
	t_game		*game;
}				t_data;

#endif
