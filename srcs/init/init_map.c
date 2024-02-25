/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/02/25 15:25:48 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	init_map(t_data *data, int argc, char **argv)
{
	t_map	*map;

	map = ft_calloc(sizeof(t_map), 1);
	if (map == NULL)
		return (perror(""), exit(EXIT_FAILURE));
	input_map_and_texture(map, argc, argv);
	if (!check_texture(map))
		return (exit(EXIT_FAILURE));
	if (!check_map(map))
		return (exit(EXIT_FAILURE));
	map->does_minimap_put = false;
	data->map = map;
	return ;
}
