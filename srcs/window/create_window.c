/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/01/27 16:53:38 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void	create_window(t_data *data)
{
	data->game->win_ptr = mlx_new_window(
			data->game->mlx_ptr,
			DISPLAY_W, DISPLAY_H,
			"cub3D"
			);
	if (!data->game->win_ptr)
		return (free(data), print_error_msg(MALLOC_ERROR), exit(EXIT_FAILURE));
	return ;
}
