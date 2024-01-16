/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   judge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/01/17 05:50:53 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/utils.h"

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
