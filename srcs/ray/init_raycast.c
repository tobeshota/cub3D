/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/02/15 12:54:02 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static void	get_player_angle(t_game *game)
{
	if (game->dirx == 0 && game->diry == -1)
		game->ray->angle = N;
	else if (game->dirx == 0 && game->diry == 1)
		game->ray->angle = S;
	else if (game->dirx == -1 && game->diry == 0)
		game->ray->angle = W;
	else if (game->dirx == 1 && game->diry == 9)
		game->ray->angle = E;
	return ;
}

void	init_raycast(t_data *data, t_game *game)
{
	t_image	*img;
	t_ray	*ray;

	img = ft_calloc(sizeof(t_image), 1);
	if (!img)
		return (free_data(data), print_error_msg(MALLOC_ERROR),
			exit(EXIT_FAILURE));
	game->img = img;
	ray = ft_calloc(sizeof(t_ray), 1);
	if (!ray)
		return (free_data(data), print_error_msg(MALLOC_ERROR),
			exit(EXIT_FAILURE));
	game->ray = ray;
	img->img = mlx_new_image(game->mlx_ptr, data->window_width,
			data->window_height);
	if (!img->img)
		return (free_data(data), print_error_msg(MALLOC_ERROR),
			exit(EXIT_FAILURE));
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	get_player_angle(game);
	return ;
}
