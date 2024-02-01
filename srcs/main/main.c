/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/02/01 15:17:53 by csakamot         ###   ########.fr       */
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

int	closing_process(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data	data;

	init_map(&data, argc, argv);
	print_map_variable(&data);
	init_mlx(&data);
	create_window(&data);
	init_game_data(&data);
	init_raycast(&data, data.game);
	test_ray_block(&data, data.game);
	// texturesを読み込む(csakamot)
	// init_textures(&data);
	// gameをはじめる(toshota)
	// start_game(&data);
	mlx_hook(data.game->win_ptr, 17, 1L << 2, closing_process, data.game);
	mlx_loop(data.game->mlx_ptr);
	free_data(&data);
	return (EXIT_SUCCESS);
}
