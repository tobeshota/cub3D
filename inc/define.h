/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/01/13 17:06:52 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# include <stdlib.h>
# include <stdbool.h>

typedef struct s_map{
	char	**map;
	char	*no_texture;
	char	*so_texture;
	char	*ew_texture;
	char	*ea_texture;
	char	*fl_texture;
	char	*ce_texture;
}				t_map;

typedef struct s_data{
	int		tmp;
	t_map	*map;
}				t_data;

#endif