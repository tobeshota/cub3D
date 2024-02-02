/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/02/02 16:31:27 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	draw_wall(t_game *game, t_ray *ray, int x)
{
	int	y;

	y = 0;
	while (y < DISPLAY_H)
	{
		if (ray->drawstart <= y && y <= ray->drawend)
			my_mlx_pixel_put(game->img, x, y, 0x00FF0000);
		else
			my_mlx_pixel_put(game->img, x, y, 0xFF0000FF);
		y++;
	}
	return ;
}
