/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/01/13 17:26:06 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <libc.h>
#include "../../inc/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	printf("cub3D!");
	init_map(&data, argc, argv);
	return (EXIT_SUCCESS);
}
