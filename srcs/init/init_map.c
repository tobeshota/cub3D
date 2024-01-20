/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/01/20 16:03:24 by toshota          ###   ########.fr       */
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
	data->map = map;
	return ;
}
