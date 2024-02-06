/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/02/06 13:56:59 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"

static bool	get_img_data(t_game *game, char *path, char dir)
{
	t_img	*direction;

	if (!direction)
		return (false);
	direction->img = mlx_xpm_file_to_image(game->mlx_ptr, path,
			&game->texture->tex_w, &game->texture->tex_h);
	direction->addr = mlx_get_data_addr(direction->img,
			&direction->bits_per_pixel,
			&direction->line_length, &direction->endian);
	if (dir == NORTH)
		game->texture->north = direction;
	if (dir == SOUTH)
		game->texture->south = direction;
	if (dir == WEST)
		game->texture->west = direction;
	if (dir == EAST)
		game->texture->east = direction;
	return (true);
}

static bool	input_texture(t_map *map, t_game *game)
{
	if (!get_img_data(game, map->no_texture, NORTH))
		return (false);
	if (!get_img_data(game, map->so_texture, SOUTH))
		return (false);
	if (!get_img_data(game, map->we_texture, WEST))
		return (false);
	if (!get_img_data(game, map->ea_texture, EAST))
		return (false);
	return (true);
}

void	init_texture(t_data *data)
{
	t_texture	*texture;

	texture = ft_calloc(sizeof(t_texture), 1);
	if (!texture)
		return (print_error_msg(MALLOC_ERROR),
			free_data(data),
			exit(EXIT_FAILURE));
	texture->tex_w = TEX_W;
	texture->tex_h = TEX_H;
	data->game->texture = texture;
	if (!input_texture(data->map, data->game))
		return (print_error_msg(MALLOC_ERROR),
			free_data(data),
			exit(EXIT_FAILURE));
	return ;
}
