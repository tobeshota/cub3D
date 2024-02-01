/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/01/31 16:38:23 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	test_ray_block(t_data *data, t_game *game)
{
	my_mlx_pixel_put(game->img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(data->game->mlx_ptr, data->game->win_ptr, game->img->img, 0, 0);
	return ;
}
