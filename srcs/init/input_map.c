/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/02/25 14:04:03 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

static bool	find_map_data_line(char *map_src, size_t *index)
{
	bool	flag;

	flag = false;
	while (map_src[*index] != '\0' && map_src[*index] != '\n')
	{
		if (judge_map_chara(map_src[*index]))
		{
			*index += ft_line_len(&map_src[*index]);
			return (false);
		}
		else if (!judge_map_chara(map_src[*index]))
			flag = true;
		*index += 1;
	}
	if (!flag)
		return (false);
	return (true);
}

static size_t	nbr_map_line(char *map_src)
{
	size_t	index;
	bool	flag;
	size_t	map_row;

	index = 0;
	flag = false;
	map_row = 0;
	while (map_src[index] != '\0')
	{
		flag = find_map_data_line(map_src, &index);
		if (map_row && !flag)
			break ;
		else if (flag)
			map_row++;
		if (map_src[index] != '\0')
			index++;
	}
	return (map_row);
}

static size_t	find_map_start_position(char *map_src)
{
	size_t	index;
	size_t	start;
	bool	flag;

	index = 0;
	start = 0;
	flag = false;
	while (map_src[index] != '\0')
	{
		start = index;
		flag = find_map_data_line(map_src, &index);
		if (flag)
			break ;
		index++;
	}
	return (start);
}

static void	create_map_data(char *map_src,
			t_mark *mark, char **map, size_t map_row)
{
	size_t	count;
	size_t	start;
	size_t	line_len;

	count = 0;
	start = find_map_start_position(map_src);
	mark->map = start;
	while (count < map_row)
	{
		line_len = ft_line_len(&map_src[start]);
		if (line_len > MAX_SIZE)
			return (print_error_msg("Map is too huge."), free_str_array(map));
		map[count] = ft_substr(map_src, start, line_len);
		if (!map[count])
			return (print_error_msg(MALLOC_ERROR));
		start += line_len + 1;
		count++;
	}
	map[count] = NULL;
	return ;
}

char	**input_map(char *map_src, t_mark *mark)
{
	size_t	map_row;
	char	**result;

	result = NULL;
	map_row = nbr_map_line(map_src);
	if (map_row > MAX_SIZE)
		return (print_error_msg("Map is too huge."), NULL);
	result = ft_calloc(sizeof(char *), map_row + 1);
	if (!result)
		return (print_error_msg(MALLOC_ERROR), NULL);
	create_map_data(map_src, mark, result, map_row);
	return (result);
}
