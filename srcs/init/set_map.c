/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/02/25 14:03:20 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	set_map(t_map *map, t_mark *mark, char *map_src)
{
	map->map = input_map(map_src, mark);
	if (!map->map)
		return (exit(EXIT_FAILURE));
	if (!check_data_position(mark))
		return (exit(EXIT_FAILURE));
	return ;
}
