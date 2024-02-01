/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/01/31 16:36:48 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	init_raycast(t_data *data, t_game *game)
{
	t_img	*img;

	img = ft_calloc(sizeof(t_img), 1);
	if (!img)
		return (
			free_data(data),
			print_error_msg(MALLOC_ERROR),
			exit(EXIT_FAILURE));
	game->img = img;
	img->img = mlx_new_image(
			game->mlx_ptr,
			data->window_width,
			data->window_height);
	if (!img->img)
		return (
			free_data(data),
			print_error_msg(MALLOC_ERROR),
			exit(EXIT_FAILURE));
	img->addr = mlx_get_data_addr(
			img->img,
			&img->bits_per_pixel,
			&img->line_length,
			&img->endian);
	return ;
}
