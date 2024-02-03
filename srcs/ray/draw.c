/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/02/03 18:24:21 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	draw_wall(t_game *game, t_ray *ray, int x)
{
	int				y;
	unsigned int	color;

	y = 0;
	color = RED;
	while (y < DISPLAY_H)
	{
		if (ray->side_dir == X_SIDE)
			color = RED - 0x00330000;
		if (ray->drawstart <= y && y <= ray->drawend)
			my_mlx_pixel_put(game->img, x, y, color);
		else
			my_mlx_pixel_put(game->img, x, y, 0xFF0000FF);
		y++;
	}
	return ;
}
