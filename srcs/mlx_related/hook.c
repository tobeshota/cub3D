/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/02/03 20:22:27 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_related.h"

static void	move_ray_cast(t_data *data, double x, double y)
{
	data->game->posx += x;
	data->game->posy += y;
	ray_cast(data);
	return ;
}

static int	key_hook_list(int keycode, t_data *data)
{
	if (keycode == ESC)
		closing_process(data->game);
	if (keycode == KEY_A)
		move_ray_cast(data, -MOVE, 0);
	if (keycode == KEY_W)
		move_ray_cast(data, 0, -MOVE);
	if (keycode == KEY_S)
		move_ray_cast(data, 0, MOVE);
	if (keycode == KEY_D)
		move_ray_cast(data, MOVE, 0);
	if (keycode == KEY_LEFT)
		printf("left\n");
	if (keycode == KEY_RIGHT)
		printf("right\n");
	return (true);
}

void	mlx_hook_list(t_data *data)
{
	mlx_hook(data->game->win_ptr,
		DESTROY_NOTIFY,
		1L << 2,
		&closing_process,
		data->game
		);
	mlx_hook(data->game->win_ptr,
		KEY_PRESS,
		1L << 0,
		&key_hook_list,
		data
		);
	mlx_expose_hook(data->game->win_ptr, ray_cast, data);
	return ;
}
