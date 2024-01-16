/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/01/16 15:50:01 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <libc.h>
#include "../../inc/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	init_map(&data, argc, argv);
	return (EXIT_SUCCESS);
}

// void	print_map_variable(t_data *data)
// {
// 	printf("%s: %s\n", NO, data->map->no_texture);
// 	printf("%s: %s\n", SO, data->map->so_texture);
// 	printf("%s: %s\n", WE, data->map->we_texture);
// 	printf("%s: %s\n", EA, data->map->ea_texture);
// 	for (int index = 0; data->map->fl_color[index] != -1; index++)
// 		printf("%s[%d]: %d\n", FL, index, data->map->fl_color[index]);
// 	for (int index = 0; data->map->ce_color[index] != -1; index++)
// 		printf("%s[%d]: %d\n", CE, index, data->map->ce_color[index]);
// }
