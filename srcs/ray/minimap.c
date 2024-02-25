/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/02/25 17:01:17 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	draw_ray_in_map(t_data *data, int dirx, int diry)
{
	int	i;
	int	j;

	i = 0;
	if (dirx < 0)
		dirx = 0;
	if (diry < 0)
		diry = 0;
	while (i < MINIMAP_SIDE * 4 / 5)
	{
		j = 0;
		while (j < MINIMAP_SIDE * 4 / 5)
		{
			my_mlx_pixel_put(data->game->img,
				dirx + i + 1,
				diry + j + 1,
				MINIMAP_PLAYER_COLOR);
			j++;
		}
		i++;
	}
	return ;
}

void	mlx_player_pixel_put_at_magnification(t_data *data, int magnification)
{
	int	pos_x_to_put_pixel;
	int	pos_y_to_put_pixel;
	int	i;
	int	j;

	pos_x_to_put_pixel = (data->game->posx - 0.5) * magnification;
	pos_y_to_put_pixel = (data->game->posy - 0.5) * magnification;
	i = 0;
	while (i < magnification)
	{
		j = 0;
		while (j < magnification)
		{
			my_mlx_pixel_put(data->game->img,
				pos_x_to_put_pixel + i,
				pos_y_to_put_pixel + j,
				MINIMAP_PLAYER_COLOR);
			j++;
		}
		i++;
	}
	draw_ray_in_map(data, (data->game->posx - 0.5 + data->game->dirx)
		* magnification, (data->game->posy - 0.5 + data->game->diry)
		* magnification);
}

void	mlx_put_map(t_data *data, int x, int y, unsigned int color)
{
	int		i;
	int		j;
	t_game	*game;

	game = data->game;
	i = 0;
	while (i < MINIMAP_SIDE)
	{
		j = 0;
		while (j < MINIMAP_SIDE)
		{
			my_mlx_pixel_put(game->img, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	put_minimap(t_data *data)
{
	int				y;
	int				x;
	unsigned int	color;

	color = 0;
	y = 0;
	while (data->map->map[y])
	{
		x = 0;
		while (data->map->map[y][x])
		{
			if (data->map->map[y][x] == WALL)
				color = MINIMAP_WALL_COLOR;
			else if (judge_directon_chara(data->map->map[y][x])
					|| data->map->map[y][x] == FLOOR)
				color = MINIMAP_FLOOR_COLOR;
			if (judge_directon_chara(data->map->map[y][x]) ||
				data->map->map[y][x] == WALL || data->map->map[y][x] == FLOOR)
				mlx_put_map(data, x * MINIMAP_SIDE, y * MINIMAP_SIDE, color);
			x++;
		}
		y++;
	}
	mlx_player_pixel_put_at_magnification(data, MINIMAP_SIDE);
}
