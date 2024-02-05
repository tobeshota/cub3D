/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/02/05 14:34:05 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

static void	get_player_direction(t_game *game, char chara)
{
	if (chara == NORTH)
	{
		game->diry = -1;
		game->camx = CAMERA / 2;
	}
	else if (chara == SOUTH)
	{
		game->diry = 1;
		game->camx = CAMERA / 2;
	}
	else if (chara == WEST)
	{
		game->dirx = -1;
		game->camy = CAMERA / 2;
	}
	else if (chara == EAST)
	{
		game->dirx = 1;
		game->camy = CAMERA / 2;
	}
	return ;
}

static void	serch_player(t_game *game, t_map *map)
{
	int		row;
	int		col;

	row = 0;
	while (map->map[row])
	{
		col = 0;
		while (map->map[row][col])
		{
			if (judge_directon_chara(map->map[row][col]))
			{
				game->posy = (double)row + 0.5;
				game->posx = (double)col + 0.5;
				get_player_direction(game, map->map[row][col]);
			}
			col++;
		}
		row++;
	}
	return ;
}

void	init_game_data(t_data *data)
{
	serch_player(data->game, data->map);
	return ;
}
