/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/02/17 17:05:29 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_related.h"

static void	move_ray_cast(t_data *data, double frontback, double leftright)
{
	t_game	*game;
	double	angle;
	double	multiplication;

	game = data->game;
	angle = 0;
	multiplication = 0;
	if (frontback)
	{
		multiplication = frontback;
		angle = get_radian(game->ray->angle);
	}
	if (leftright)
	{
		multiplication = leftright;
		angle = get_radian(game->ray->angle - 90);
	}
	game->posx += multiplication * cos(angle);
	game->posy += multiplication * -sin(angle);
	if (data->map->map[(int)game->posy][(int)game->posx] == '1')
	{
		game->posx -= multiplication * cos(angle);
		game->posy -= multiplication * -sin(angle);
	}
	ray_cast(data);
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

static int	mouse_hook_list(int x, int y, t_data *data)
{
	mlx_mouse_move(data->game->mlx_ptr, data->game->win_ptr, x, y);
	printf("%d, %d\n", x, y);
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
	mlx_hook(data->game->win_ptr,
		6,
		1L << 6,
		&mouse_hook_list,
		data
		);
	mlx_expose_hook(data->game->win_ptr, ray_cast, data);
	return ;
}
