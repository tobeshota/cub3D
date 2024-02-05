/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/02/05 16:14:28 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_related.h"

static void	move_ray_cast(t_data *data, double frontback, double leftright)
{
	t_game	*game;

	game = data->game;
	if (frontback)
	{
		game->posx += frontback * cos(get_radian(game->ray->angle));
		game->posy += frontback * -sin(get_radian(game->ray->angle));
	}
	if (leftright)
	{
		game->posx += leftright * cos(get_radian(game->ray->angle - 90));
		game->posy += leftright * -sin(get_radian(game->ray->angle - 90));
	}
	ray_cast(data);
	return ;
}

static int	key_hook_list(int keycode, t_data *data)
{
	if (keycode == ESC)
		closing_process(data->game);
	if (keycode == KEY_A)
		move_ray_cast(data, false, -MOVE);
	if (keycode == KEY_W)
		move_ray_cast(data, MOVE, false);
	if (keycode == KEY_S)
		move_ray_cast(data, -MOVE, false);
	if (keycode == KEY_D)
		move_ray_cast(data, false, MOVE);
	if (keycode == KEY_LEFT)
		view_point_rotate(data, true, false);
	if (keycode == KEY_RIGHT)
		view_point_rotate(data, false, true);
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
