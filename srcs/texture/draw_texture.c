/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/02/06 21:33:45 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"

void	draw_texture(t_game *game, t_texture *texture)
{
	char	*tmp;

	printf("bits_per_pixel:%d, line_length:%d, endian:%d\n", texture->north->bits_per_pixel, texture->north->line_length, texture->north->endian);
	for (int i = 0; i < 64; i++)
		for (int u = 0; u < 64; u++)
		{
			tmp = texture->north->addr + (i * texture->north->line_length + u * (texture->north->bits_per_pixel / 8));
			my_mlx_pixel_put(game->img, u, i, *(int *)tmp);
		}
	return ;
}
