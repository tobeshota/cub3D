/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/02/03 19:15:56 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_related.h"

static int	key_hook_list(int keycode, t_data *data)
{
	(void)data;
	if (keycode == ESC)
		closing_process(data->game);
	if (keycode == KEY_A)
		printf("A\n");
	if (keycode == KEY_W)
		printf("W\n");
	if (keycode == KEY_S)
		printf("S\n");
	if (keycode == KEY_D)
		printf("D\n");
	if (keycode == KEY_LEFT)
		printf("left\n");
	if (keycode == KEY_RIGHT)
		printf("right\n");
	printf("%d\n", keycode);
	return (true);
}

void	mlx_hook_list(t_data *data)
{
	mlx_hook(data->game->win_ptr, 17, 1L << 2, closing_process, data->game);
	mlx_key_hook(data->game->win_ptr, key_hook_list, data);
	mlx_expose_hook(data->game->win_ptr, ray_cast, data);
	return ;
}
