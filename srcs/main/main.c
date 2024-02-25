/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/02/25 14:56:59 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_map_variable(t_data *data)
{
	int	index;

	printf("\n---texture path---\n");
	printf("%s: %s\n", NO, data->map->no_texture);
	printf("%s: %s\n", SO, data->map->so_texture);
	printf("%s: %s\n", WE, data->map->we_texture);
	printf("%s: %s\n", EA, data->map->ea_texture);
	printf("\n---rgb_color---\n");
	index = -1;
	while (data->map->fl_color[++index] != -1)
		printf("%s[%d]: %3d ", FL, index, data->map->fl_color[index]);
	printf("\n");
	index = -1;
	while (data->map->ce_color[++index] != -1)
		printf("%s[%d]: %3d ", CE, index, data->map->ce_color[index]);
	printf("\n\n---map---\n");
	index = -1;
	while (data->map->map[++index] != NULL)
		printf("%s\n", data->map->map[index]);
}

int	main(int argc, char **argv)
{
	t_data	data;

	init_map(&data, argc, argv);
	print_map_variable(&data);
	init_mlx(&data);
	create_window(&data);
	init_texture(&data);
	init_game_data(&data);
	mlx_hook_list(&data);
	init_raycast(&data, data.game);
	ray_cast(&data);
	mlx_loop(data.game->mlx_ptr);
	free_data(&data);
	return (EXIT_SUCCESS);
}

#ifdef DEBUG

__attribute__((destructor)) void	end(void)
{
	system("leaks -q cub3D > /dev/stderr");
}

#endif
