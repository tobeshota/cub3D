/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/01/20 16:05:07 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	set_map(t_map *map, t_mark *mark, char *map_src)
{
	map->map = input_map(map_src, mark);
	if (!check_data_position(mark))
		return (exit(EXIT_FAILURE));
	return ;
}
