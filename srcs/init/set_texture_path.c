/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/01/20 16:05:11 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

static char	*set_direction_texture(char *map_src, size_t *mark, char *direction)
{
	size_t	position;
	char	*result;

	position = 0;
	result = NULL;
	if (check_input_nbrs(map_src, direction, &position) != 1)
		return (NULL);
	*mark = position;
	result = input_texture_path(map_src, position);
	return (result);
}

static int	*set_rgb_color(char *map_src, size_t *mark, char *updown)
{
	size_t	position;
	int		*rgb_color;

	position = 0;
	rgb_color = NULL;
	if (check_input_nbrs(map_src, updown, &position) != 1)
		return (NULL);
	*mark = position;
	rgb_color = input_texture_rgb(map_src, position);
	return (rgb_color);
}

void	set_texture_path(t_map *map, t_mark *mark, char *map_src)
{
	map->no_texture = set_direction_texture(map_src, &(mark->no), NO);
	map->so_texture = set_direction_texture(map_src, &(mark->so), SO);
	map->we_texture = set_direction_texture(map_src, &(mark->we), WE);
	map->ea_texture = set_direction_texture(map_src, &(mark->ea), EA);
	map->fl_color = set_rgb_color(map_src, &(mark->fl), FL);
	map->ce_color = set_rgb_color(map_src, &(mark->ce), CE);
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
