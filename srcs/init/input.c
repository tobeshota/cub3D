/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/01/20 19:37:21 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

static bool	check_map_path(int argc, char **argv)
{
	if (argc != 2)
		return (print_error_msg(INVALID_ARGC), false);
	if (ft_strrncmp(argv[1], ".cub", 4))
		return (print_error_msg(NOT_CUB_MAP), false);
	return (true);
}

static char	*input_map_src(int fd)
{
	char	*one_line;
	char	*map_src;

	map_src = NULL;
	while (1)
	{
		one_line = get_next_line(fd);
		if (one_line == NULL)
			break ;
		map_src = str_connect(map_src, one_line);
		if (!map_src)
			return (NULL);
	}
	if (!map_src)
		return (print_error_msg("Empty map data."), NULL);
	return (map_src);
}

void	input_map_and_texture(t_map *map, int argc, char **argv)
{
	t_mark	mark;
	int		fd;
	char	*map_src;

	ft_memset(&mark, 0, sizeof(t_mark));
	check_map_path(argc, argv);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (perror(""), exit(EXIT_FAILURE));
	map_src = input_map_src(fd);
	if (close(fd) == -1)
		return (perror(""), exit(EXIT_FAILURE));
	if (!map_src)
	{
		close(fd);
		return (exit(EXIT_FAILURE));
	}
	set_texture_path(map, &mark, map_src);
	set_map(map, &mark, map_src);
	free(map_src);
	return ;
}
