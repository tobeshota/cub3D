/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/01/20 16:04:58 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

char	*input_texture_path(char *map_src, size_t position)
{
	size_t	path_len;
	char	*result;

	path_len = 0;
	result = NULL;
	position += blank_pass(&map_src[position + 2]) + 2;
	path_len = ft_path_len(&map_src[position]);
	check_path_line(map_src, position, path_len);
	result = ft_calloc(sizeof(char), path_len + 1);
	if (!result)
		return (print_error_msg(MALLOC_ERROR), NULL);
	ft_strlcpy(result, &map_src[position], path_len + 1);
	return (result);
}

static int	*input_value(char **array)
{
	size_t	len;
	size_t	row;
	int		*result;

	len = ft_array_len(array);
	row = 0;
	result = ft_calloc(sizeof(int), len + 1);
	if (!result)
		return (print_error_msg(MALLOC_ERROR), NULL);
	while (array[row])
	{
		result[row] = ft_atoi(array[row]);
		row++;
	}
	result[row] = -1;
	return (result);
}

static int	*input_rgb_value(char *str)
{
	int		*rgb_value;
	char	**tmp;

	rgb_value = NULL;
	tmp = ft_split(str, ',');
	if (!tmp)
		return (print_error_msg(MALLOC_ERROR), NULL);
	check_rgb_str(tmp);
	rgb_value = input_value(tmp);
	free_str_array(tmp);
	check_rgb_value(rgb_value);
	return (rgb_value);
}

int	*input_texture_rgb(char *map_src, size_t position)
{
	int		*rgb_color;
	char	*tmp;
	size_t	path_len;

	path_len = 0;
	rgb_color = NULL;
	position += blank_pass(&map_src[position + 1]) + 1;
	path_len = ft_line_len(&map_src[position]);
	tmp = ft_calloc(sizeof(char), path_len + 1);
	if (!tmp)
		return (print_error_msg(MALLOC_ERROR), NULL);
	ft_strlcpy(tmp, &map_src[position], path_len + 1);
	rgb_color = input_rgb_value(tmp);
	free(tmp);
	return (rgb_color);
}
