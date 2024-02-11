/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/02/06 12:11:01 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	dda_exec(t_map *map, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->sidedistx < ray->sidedisty)
		{
			ray->sidedistx += ray->deltadistx;
			ray->int_posx += ray->stepx;
			ray->side_dir = X_SIDE;
		}
		else
		{
			ray->sidedisty += ray->deltadisty;
			ray->int_posy += ray->stepy;
			ray->side_dir = Y_SIDE;
		}
		if (ray->int_posx < 0)
			ray->int_posx = 0;
		if (ray->int_posy < 0)
			ray->int_posy = 0;
		if (map->map[ray->int_posy][ray->int_posx] == '1')
			ray->hit = 1;
	}
	if (ray->side_dir == X_SIDE)
		ray->raydist = ray->sidedistx - ray->deltadistx;
	else
		ray->raydist = ray->sidedisty - ray->deltadisty;
}
