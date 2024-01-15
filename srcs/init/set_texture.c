/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/01/15 15:55:37 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/init.h"

static char	*set_direction_texture(char *map_src, int direction)
{
	char	*result;

	(void) map_src;
	(void) direction;
	result = NULL;
	return (result);
}

static int	*set_rgb_color(char *map_src)
{
	int	*rgb_color;


	(void) map_src;
	rgb_color = NULL;
	return (rgb_color);
}

void	set_texture_path(t_map *map, char *map_src)
{
	map->no_texture = set_direction_texture(map_src, NO);
	map->so_texture = set_direction_texture(map_src, SO);
	map->we_texture = set_direction_texture(map_src, WE);
	map->ea_texture = set_direction_texture(map_src, EA);
	map->fl_color = set_rgb_color(map_src);
	map->ce_color = set_rgb_color(map_src);
	if (
		!map->no_texture
		|| !map->so_texture
		|| !map->we_texture
		|| !map->ea_texture
		|| !map->fl_color
		|| !map->ce_color
	)
		return (exit(EXIT_FAILURE));
	return ;
}
