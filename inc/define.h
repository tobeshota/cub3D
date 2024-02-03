/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/02/03 20:03:22 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# include <stdlib.h>
# include <stdbool.h>


# define DISPLAY_W		1920
# define DISPLAY_H		1080
# define ESC			65307
# define KEY_A			97
# define KEY_W			119
# define KEY_S			115
# define KEY_D			100
# define KEY_LEFT		65361
# define KEY_RIGHT		65363
# define KEY_PRESS		2
# define DESTROY_NOTIFY	17
# define DPI_W			1920
# define DPI_H			1080
# define CAMERA			1.32
# define MOVE			0.05
# define X_SIDE			0
# define Y_SIDE			1
# define WALL			'1'
# define FLOOR			'0'
# define NORTH			'N'
# define SOUTH			'S'
# define WEST			'W'
# define EAST			'E'
# define NO				"NO"
# define SO				"SO"
# define WE				"WE"
# define EA				"EA"
# define FL				"F"
# define CE				"C"
# define RED			0x00FF0000
# define GREEN			0x0000FF00
# define BLUE			0x000000FF

typedef struct s_mark{
	size_t	no;
	size_t	so;
	size_t	we;
	size_t	ea;
	size_t	fl;
	size_t	ce;
	size_t	map;
}				t_mark;

typedef struct s_bfs{
	bool	flag;
	size_t	x;
	size_t	y;
}				t_bfs;

typedef struct s_map{
	char	**map;
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	int		*fl_color;
	int		*ce_color;
}				t_map;

typedef struct s_ray{
	int		hit;
	int		side_dir;
	int		int_posx;
	int		int_posy;
	int		stepx;
	int		stepy;
	double	raydirx;
	double	raydiry;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	raydist;
	int		wall_h;
	int		drawstart;
	int		drawend;
}				t_ray;

typedef struct s_img{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_game{
	void	*mlx_ptr;
	void	*win_ptr;
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	camx;
	double	camy;
	t_img	*img;
	t_ray	*ray;
}				t_game;

typedef struct s_data{
	int		window_width;
	int		window_height;
	t_map	*map;
	t_game	*game;
}				t_data;

#endif