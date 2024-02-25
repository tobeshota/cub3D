/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/02/25 15:30:18 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	ray_firing(t_game *game, t_ray *ray, int x)
{
	double	window_x;

	window_x = 2 * x / (double)DPI_W - 1;
	ray->raydirx = game->dirx + game->camx * window_x;
	ray->raydiry = game->diry + game->camy * window_x;
}

static void	calcu_sidedist(t_game *game, t_ray *ray)
{
	if (ray->raydirx > 0)
	{
		ray->stepx = 1;
		ray->sidedistx = (ray->int_posx + 1 - game->posx) * ray->deltadistx;
	}
	else
	{
		ray->stepx = -1;
		ray->sidedistx = (game->posx - ray->int_posx) * ray->deltadistx;
	}
	if (ray->raydiry > 0)
	{
		ray->stepy = 1;
		ray->sidedisty = (ray->int_posy + 1 - game->posy) * ray->deltadisty;
	}
	else
	{
		ray->stepy = -1;
		ray->sidedisty = (game->posy - ray->int_posy) * ray->deltadisty;
	}
	return ;
}

static void	calcu_dda_variable(t_game *game, t_ray *ray)
{
	ray->int_posx = (int)game->posx;
	ray->int_posy = (int)game->posy;
	if (ray->raydirx == 0)
		ray->deltadistx = __DBL_MAX__;
	else
		ray->deltadistx = (1 / ray->raydirx);
	if (ray->deltadistx < 0)
		ray->deltadistx *= -1;
	if (ray->raydiry == 0)
		ray->deltadisty = __DBL_MAX__;
	else
		ray->deltadisty = (1 / ray->raydiry);
	if (ray->deltadisty < 0)
		ray->deltadisty *= -1;
	calcu_sidedist(game, ray);
	return ;
}

static void	calcu_wall_height(t_ray *ray)
{
	ray->wall_h = (int)(DISPLAY_H / ray->raydist);
	ray->drawstart = - (ray->wall_h / 2) + (DISPLAY_H / 2);
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	ray->drawend = (ray->wall_h / 2) + (DISPLAY_H / 2);
	if (ray->drawend >= DISPLAY_H)
		ray->drawend = DISPLAY_H;
	ray->surplus = ray->wall_h / 2 - DISPLAY_H / 2;
	if (ray->surplus < 0)
		ray->surplus = 0;
	return ;
}

int	ray_cast(t_data *data)
{
	int		dot;
	t_map	*map;
	t_game	*game;

	map = data->map;
	game = data->game;
	dot = 0;
	while (dot < DISPLAY_W)
	{
		ray_firing(game, game->ray, dot);
		calcu_dda_variable(game, game->ray);
		game->ray->hit = 0;
		dda_exec(map, game->ray);
		calcu_wall_height(game->ray);
		draw_wall(map, game, game->ray, dot);
		dot++;
	}
	if (data->map->does_minimap_put == true)
		put_minimap(data);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->img, 0, 0);
	return (true);
}
