/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/02/07 14:22:48 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"

unsigned int	get_texture_color(t_ray *ray, t_img *img, int x, int y)
{
	double			row;
	double			col;
	unsigned int	*color;

	row = ((y - ray->drawstart) * TEX_H / ray->wall_h);
	col = ((x * TEX_W / ray->wall_w) % TEX_W);
	color = texture_bit_shift(img, (size_t)col, (size_t)row);
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
