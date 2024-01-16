/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_set_texture_path.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/01/16 15:00:50 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/check.h"

static char	*error_msg_jump_no_count(char *direction)
{
	char	*tmp;
	char	*result;

	tmp = ft_strjoin("NO ", direction);
	result = ft_strjoin(tmp, "_texture path.");
	if (!tmp || !result)
		return (exit(EXIT_FAILURE), NULL);
	return (result);
}

static char	*error_msg_jump_counts(char *direction)
{
	char	*tmp;
	char	*result;

	tmp = ft_strjoin("There are multiple ", direction);
	result = ft_strjoin(tmp, "_texture paths.");
	if (!tmp || !result)
		return (exit(EXIT_FAILURE), NULL);
	return (result);
}

int	check_input_nbrs(char *map, char *direction, size_t *position)
{
	int		count;
	int		index;
	size_t	len;

	count = 0;
	index = 0;
	len = ft_strlen(direction);
	while (map[index] != '\0')
	{
		if (index == 0 || (map[index] != 0 && map[index - 1] == '\n'))
		{
			index += blank_pass(&map[index]);
			if (ft_strncmp(&map[index], direction, len) == 0)
			{
				*position = index;
				count++;
			}
		}
		index++;
	}
	if (count == 0)
		print_error_msg(error_msg_jump_no_count(direction));
	else if (count >= 2)
		print_error_msg(error_msg_jump_counts(direction));
	return (count);
}
