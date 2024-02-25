/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/02/25 16:01:39 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

static bool	empty_map_check(t_map *map)
{
	if (!*(map->map))
		return (print_error_msg("There is no map."), true);
	return (false);
}

bool	player_check(char **map)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (judge_directon_chara(map[y][x]))
				count++;
			x++;
		}
		y++;
	}
	if (count != 1)
		return (print_error_msg("Invalid map."), true);
	return (false);
}

bool	check_map(t_map *map)
{
	if (empty_map_check(map))
		return (false);
	if (bfs_map_check(map))
		return (false);
	retrun_bfs_map(map);
	if (player_check(map->map))
		return (false);
	return (true);
}
