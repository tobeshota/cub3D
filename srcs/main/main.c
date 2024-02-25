/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/02/25 16:30:39 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	init_map(&data, argc, argv);
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
