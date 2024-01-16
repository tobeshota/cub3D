/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/01/16 17:13:56 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/init.h"

static bool	find_map_data_line(const char *map_src, size_t *index)
{
	bool	flag;

	flag = false;
	while (map_src[*index] != '\0'
		|| (*index != 0 && map_src[*index - 1] != '\n'))
	{
		if (judge_map_chara(map_src[*index]))
			return (false);
		else if (!judge_map_chara(map_src[*index]) && map_src[*index] != ' ')
			flag = true;
		*index++;
	}
	if (!flag)
		return (false);
	return (true);
}

static size_t	nbr_map_line(const char *map_src)
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
		else
			map_row++;
	}
	return (map_row);
}

static char	**create_map_data(char *map_src, size_t map_row)
{
	
}

char	**input_map(char *map_src)
{
	size_t	map_row;
	char	**result;

	result = NULL;
	map_row = nbr_map_line(map_src);
	result = ft_calloc(sizeof(char *), map_row + 1);
	if (!result)
		return (print_error_msg(MALLOC_ERROR), NULL);
	result = create_map_data(map_src, map_row);
	return (result);
}
