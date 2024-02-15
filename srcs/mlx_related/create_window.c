/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/02/15 14:27:01 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_related.h"
#include "../../minilibx-linux/mlx.h"
#include "../../minilibx-linux/mlx_int.h"

static void		my_mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey)
{
	XWindowAttributes	xwAttr;
	t_xvar				*xvar;

	xvar = mlx_ptr;
	XGetWindowAttributes(xvar->display, xvar->root, &xwAttr);
	(*sizex) = xwAttr.width;
	(*sizey) = xwAttr.height;
}


void	create_window(t_data *data)
{
	my_mlx_get_screen_size(
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
