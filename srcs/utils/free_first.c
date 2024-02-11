/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_first.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/02/05 22:38:27 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	free_str_array(char **array)
{
	size_t	row;

	row = 0;
	if (!array)
		return ;
	while (array[row] != NULL)
	{
		free(array[row]);
		row++;
	}
	free(array);
	return ;
}

void	free_map(t_map *map)
{
	if (map->no_texture)
		free(map->no_texture);
	if (map->so_texture)
		free(map->so_texture);
	if (map->we_texture)
		free(map->we_texture);
	if (map->ea_texture)
		free(map->ea_texture);
	if (map->fl_color)
		free(map->fl_color);
	if (map->ce_color)
		free (map->ce_color);
	if (map->map)
		free_str_array(map->map);
	free(map);
	return ;
}

void	free_img(t_img *img)
{
	if (img->img)
		free(img->img);
	free(img);
	return ;
}

void	free_game(t_game *game)
{
	if (game->mlx_ptr)
		free(game->mlx_ptr);
	if (game->win_ptr)
		free(game->win_ptr);
	if (game->ray)
		free(game->ray);
	if (game->texture)
		free(game->texture);
	if (game->img)
		free_img(game->img);
	free(game);
	return ;
}

void	free_data(t_data *data)
{
	if (data->map)
		free_map(data->map);
	if (data->game)
		free_game(data->game);
	return ;
}
