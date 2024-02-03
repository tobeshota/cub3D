/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/02/03 18:36:19 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_related.h"

void	init_mlx(t_data *data)
{
	t_game	*game;

	game = ft_calloc(sizeof(t_game), 1);
	if (!game)
		return (print_error_msg(MALLOC_ERROR),
			free_data(data),
			exit(EXIT_FAILURE));
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (print_error_msg("mlx_init error."),
			free_data(data),
			exit(EXIT_FAILURE));
	data->game = game;
	return ;
}
