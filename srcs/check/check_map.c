/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/01/20 19:41:12 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

static bool	empty_map_check(t_map *map)
{
	return (false);
}

bool	check_map(t_map *map)
{
	if (empty_map_check(map))
		return (false);
	return (true);
}
