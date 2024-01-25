/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bfs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/01/25 13:13:01 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

static bool	judge_bfs_map_chara(char **map, size_t x, size_t y)
{
	if (map[y][x] == '1'
		|| map[y][x] == '0'
		|| map[y][x] == '0' - 1
		|| map[y][x] == NORTH - 1
		|| map[y][x] == SOUTH - 1
		|| map[y][x] == WEST - 1
		|| map[y][x] == EAST - 1
		|| judge_directon_chara(map[y][x]))
		return (true);
	return (false);
}

static void	bfs_loop(char **map, size_t x, size_t y, bool *flag)
{
	if (x == 0 || y == 0 || !map[y][x + 1] || !map[y + 1])
	{
		*flag = true;
		return (print_error_msg("Invalid map."));
	}
	if (!*flag)
	{
		if (!judge_bfs_map_chara(map, x, y - 1)
			|| !judge_bfs_map_chara(map, x, y + 1)
			|| !judge_bfs_map_chara(map, x - 1, y)
			|| !judge_bfs_map_chara(map, x + 1, y))
		{
			*flag = true;
			return (print_error_msg("Invalid map."));
		}
		map[y][x]--;
		if (map[y - 1][x] == '0' || judge_directon_chara(map[y - 1][x]))
			bfs_loop(map, x, y - 1, flag);
		if (map[y + 1][x] == '0' || judge_directon_chara(map[y + 1][x]))
			bfs_loop(map, x, y + 1, flag);
		if (map[y][x - 1] == '0' || judge_directon_chara(map[y][x - 1]))
			bfs_loop(map, x - 1, y, flag);
		if (map[y][x + 1] == '0' || judge_directon_chara(map[y][x + 1]))
			bfs_loop(map, x + 1, y, flag);
	}
}

bool	bfs_map_check(t_map *map)
{
	t_bfs	bfs;
	bool	exe;

	ft_memset(&bfs, 0, sizeof(t_bfs));
	while (map->map[bfs.y])
	{
		bfs.flag = false;
		exe = false;
		bfs.x = 0;
		while (map->map[bfs.y][bfs.x] != '\0')
		{
			if (map->map[bfs.y][bfs.x] == '0')
			{
				exe = true;
				bfs_loop(map->map, bfs.x, bfs.y, &bfs.flag);
			}
			bfs.x++;
		}
		if (exe == true && bfs.flag == true)
			return (true);
		bfs.y++;
	}
	return (false);
}

void	retrun_bfs_map(t_map *map)
{
	size_t	row;
	size_t	col;

	row = 0;
	while (map->map[row])
	{
		col = 0;
		while (map->map[row][col] != '\0')
		{
			if (map->map[row][col] == '0' - 1
			|| map->map[row][col] == NORTH - 1
			|| map->map[row][col] == SOUTH - 1
			|| map->map[row][col] == WEST - 1
			|| map->map[row][col] == EAST - 1)
				map->map[row][col]++;
			col++;
		}
		row++;
	}
	return ;
}
