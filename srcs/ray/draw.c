/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/02/11 17:26:05 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	draw_wall(t_map *map, t_game *game, t_ray *ray, int x)
{
	int				y;
	int				*ceil;
	int				*floor;
	unsigned int	color;

	y = 0;
	ceil = map->ce_color;
	floor = map->fl_color;
	while (y < DISPLAY_H)
	{
		if (y < ray->drawstart)
			color = get_color_number(false, ceil[0], ceil[1], ceil[2]);
		else if (y > ray->drawend)
			color = get_color_number(false, floor[0], floor[1], floor[2]);
		else
			color = get_texture_color(game, game->ray, y);
		my_mlx_pixel_put(game->img, x, y, color);
		y++;
	}
	return ;
}
