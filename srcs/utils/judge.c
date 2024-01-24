/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   judge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/01/24 21:12:13 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

bool	judge_directon_chara(char chara)
{
	if (chara == NORTH
		|| chara == SOUTH
		|| chara == WEST
		|| chara == EAST)
		return (true);
	return (false);
}

bool	judge_map_chara(char chara)
{
	if (chara != WALL
		&& chara != FLOOR
		&& chara != NORTH
		&& chara != SOUTH
		&& chara != WEST
		&& chara != EAST
		&& chara != ' ')
		return (true);
	return (false);
}
