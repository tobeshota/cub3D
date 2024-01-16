/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/01/16 16:08:46 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/init.h"

void	set_map(t_map *map, char *map_src)
{
	(void) map;
	(void) map_src;
	map->map = input_map(map_src);
	return ;
}
