/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/02/03 18:36:07 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_related.h"

void	create_window(t_data *data)
{
	mlx_get_screen_size(
		data->game->mlx_ptr,
		&data->window_width,
		&data->window_height
		);
	data->game->win_ptr = mlx_new_window(
			data->game->mlx_ptr,
			data->window_width, data->window_height,
			"cub3D"
			);
	if (!data->game->win_ptr)
		return (free(data), print_error_msg(MALLOC_ERROR), exit(EXIT_FAILURE));
	return ;
}
