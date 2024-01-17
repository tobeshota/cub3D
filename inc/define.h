/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/01/17 20:29:43 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# include <stdlib.h>
# include <stdbool.h>

# define WALL	'1'
# define FLOOR	'0'
# define NORTH	'N'
# define SOUTH	'S'
# define WEST	'W'
# define EAST	'E'
# define NO		"NO"
# define SO		"SO"
# define WE		"WE"
# define EA		"EA"
# define FL		"F"
# define CE		"C"

typedef struct s_mark{
	size_t	no;
	size_t	so;
	size_t	we;
	size_t	ea;
	size_t	fl;
	size_t	ce;
	size_t	map;
}				t_mark;

typedef struct s_map{
	char	**map;
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	int		*fl_color;
	int		*ce_color;
}				t_map;

typedef struct s_data{
	int		tmp;
	t_map	*map;
}				t_data;

#endif