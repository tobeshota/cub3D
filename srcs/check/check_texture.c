/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/02/22 14:16:16 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

static char	*branch_error_msg_no_path(char *direction)
{
	char	*result;
	char	*tmp;

	tmp = ft_strjoin("Not exist ", direction);
	result = ft_strjoin(tmp, "_texture path.");
	if (!tmp || !result)
		return (print_error_msg(MALLOC_ERROR), exit(EXIT_FAILURE), NULL);
	free(tmp);
	return (result);
}

static bool	empty_texture_check(t_map *map)
{
	if (!*(map->no_texture))
		return (print_error_msg(branch_error_msg_no_path("NO")), true);
	if (!*(map->so_texture))
		return (print_error_msg(branch_error_msg_no_path("SO")), true);
	if (!*(map->we_texture))
		return (print_error_msg(branch_error_msg_no_path("WE")), true);
	if (!*(map->ea_texture))
		return (print_error_msg(branch_error_msg_no_path("EA")), true);
	return (false);
}

static bool does_file_exist(char *file_path)
{
	int	fd;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (false);
	return (close(fd), true);
}

static bool	exitst_texture_check(t_map *map)
{
	if (does_file_exist(map->no_texture) && does_file_exist(map->so_texture) && does_file_exist(map->we_texture) && does_file_exist(map->ea_texture) && does_file_exist(MINIMAP_FLOOR_PATH) && does_file_exist(MINIMAP_WALL_PATH))
		return (false);
	return (perror(""), true);

	// int	fd;

	// fd = open(map->no_texture, O_RDONLY);
	// if (fd == -1)
	// 	return (perror(""), true);
	// close(fd);
	// fd = open(map->so_texture, O_RDONLY);
	// if (fd == -1)
	// 	return (perror(""), true);
	// close(fd);
	// fd = open(map->we_texture, O_RDONLY);
	// if (fd == -1)
	// 	return (perror(""), true);
	// close(fd);
	// fd = open(map->ea_texture, O_RDONLY);
	// if (fd == -1)
	// 	return (perror(""), true);
	// close(fd);

	// fd = open(MINIMAP_FLOOR_PATH, O_RDONLY);
	// if (fd == -1)
	// 	return (perror(""), true);
	// close(fd);

	// fd = open(MINIMAP_WALL_PATH, O_RDONLY);
	// if (fd == -1)
	// 	return (perror(""), true);
	// close(fd);
	// return (false);
}

bool	check_texture(t_map *map)
{
	if (empty_texture_check(map))
		return (false);
	if (exitst_texture_check(map))
		return (false);
	return (true);
}
