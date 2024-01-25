/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/01/25 11:13:20 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

static bool	empty_map_check(t_map *map)
{
	if (!*(map->map))
		return (print_error_msg("There is no map."), true);
	return (false);
}

bool	check_map(t_map *map)
{
	if (empty_map_check(map))
		return (false);
	if (bfs_map_check(map))
		return (false);
	for (int i = 0; map->map[i]; i++)
		printf("%s\n", map->map[i]);
	retrun_bfs_map(map);
	return (true);
}
