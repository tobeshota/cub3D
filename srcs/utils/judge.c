/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   judge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/01/20 16:23:42 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

bool	judge_map_chara(char chara)
{
	if (chara != WALL
		&& chara != FLOOR
		&& chara != NORTH
		&& chara != SOUTH
		&& chara != EAST
		&& chara != WEST
		&& chara != ' ')
		return (true);
	return (false);
}
