/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/02/15 12:54:02 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"

static t_image	*get_texture_dir(t_texture *texture, t_ray *ray)
{
	t_image	*direction;

	direction = NULL;
	if (ray->side_dir == Y_SIDE && ray->raydiry < 0)
		direction = texture->north;
	if (ray->side_dir == Y_SIDE && ray->raydiry > 0)
		direction = texture->south;
	if (ray->side_dir == X_SIDE && ray->raydirx < 0)
		direction = texture->west;
	if (ray->side_dir == X_SIDE && ray->raydirx > 0)
		direction = texture->east;
	return (direction);
}

unsigned int	get_texture_color(t_game *game, t_ray *ray, int y)
{
	double			row;
	double			col;
	t_image			*dir;
	unsigned int	*color;

	dir = get_texture_dir(game->texture, ray);
	if (ray->side_dir == X_SIDE)
		col = game->posy + ray->raydist * ray->raydiry;
	else
		col = game->posx + ray->raydist * ray->raydirx;
	col = (col - (int)col) * TEX_W;
	row = ((y - ray->drawstart + ray->surplus) * TEX_H / ray->wall_h);
	color = texture_bit_shift(dir, (int)col, row);
	return (*color);
}

void	draw_texture(t_game *game, t_texture *texture)
{
	unsigned int	*tmp;

	for (int i = 0; i < 64; i++)
		for (int u = 0; u < 64; u++)
		{
			tmp = texture_bit_shift(texture->north, u, i);
			my_mlx_pixel_put(game->img, u, i, *tmp);
		}
	return ;
}
