/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/01/20 16:02:21 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <libc.h>
#include "cub3d.h"

static void	print_map_variable(t_data *data)
{
	printf("\n---texture path---\n");
	printf("%s: %s\n", NO, data->map->no_texture);
	printf("%s: %s\n", SO, data->map->so_texture);
	printf("%s: %s\n", WE, data->map->we_texture);
	printf("%s: %s\n", EA, data->map->ea_texture);
	printf("\n---rgb_color---\n");
	for (int index = 0; data->map->fl_color[index] != -1; index++)
		printf(" %s[%d]: %d", FL, index, data->map->fl_color[index]);
	printf("\n");
	for (int index = 0; data->map->ce_color[index] != -1; index++)
		printf(" %s[%d]: %d", CE, index, data->map->ce_color[index]);
	printf("\n\n---map---\n");
	for (int index = 0; data->map->map[index] != NULL; index++)
		printf("%s\n", data->map->map[index]);
}

int	main(int argc, char **argv)
{
	t_data	data;

	init_map(&data, argc, argv);
	print_map_variable(&data);
	// init_mlx(&data);
	free_data(&data);
	return (EXIT_SUCCESS);
}
