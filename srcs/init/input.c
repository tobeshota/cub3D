/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/01/16 16:07:16 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/init.h"

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
	char	*tmp;
	char	*one_line;
	char	*map_src;

	tmp = NULL;
	map_src = NULL;
	while (1)
	{
		one_line = get_next_line(fd);
		if (one_line == NULL)
			break ;
		if (map_src)
			tmp = ft_strdup(map_src);
		if (map_src && !tmp)
			return (perror(""), NULL);
		if (map_src)
			free(map_src);
		map_src = ft_strjoin(tmp, one_line);
		if (!map_src)
			return (perror(""), NULL);
		free(tmp);
		free(one_line);
	}
	return (map_src);
}

void	input_map_and_texture(t_map *map, int argc, char **argv)
{
	int		fd;
	char	*map_src;

	check_map_path(argc, argv);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (perror(""), exit(EXIT_FAILURE));
	map_src = input_map_src(fd);
	if (!map_src)
		return (exit(EXIT_FAILURE));
	set_texture_path(map, map_src);
	set_map(map, map_src);
	return ;
}
