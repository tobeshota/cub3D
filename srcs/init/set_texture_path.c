/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/01/16 15:50:22 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/init.h"

static char	*set_direction_texture(char *map_src, char *direction)
{
	size_t	position;
	char	*result;

	position = 0;
	result = NULL;
	if (check_input_nbrs(map_src, direction, &position) != 1)
		return (NULL);
	result = input_texture_path(map_src, position);
	// printf("%s position:%ld\n", direction, position);
	return (result);
}

static int	*set_rgb_color(char *map_src, char *updown)
{
	size_t	position;
	int		*rgb_color;


	position = 0;
	rgb_color = NULL;
	if (check_input_nbrs(map_src, updown, &position) != 1)
		return (NULL);
	rgb_color = input_texture_rgb(map_src, position);
	// printf("%s position:%ld\n", updown, position);
	return (rgb_color);
}

void	set_texture_path(t_map *map, char *map_src)
{
	map->no_texture = set_direction_texture(map_src, NO);
	map->so_texture = set_direction_texture(map_src, SO);
	map->we_texture = set_direction_texture(map_src, WE);
	map->ea_texture = set_direction_texture(map_src, EA);
	map->fl_color = set_rgb_color(map_src, FL);
	map->ce_color = set_rgb_color(map_src, CE);
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
