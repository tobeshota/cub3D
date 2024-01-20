/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/01/20 16:23:16 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

bool	check_rgb_str(char **tmp)
{
	size_t	row;
	size_t	col;
	bool	flag;

	row = 0;
	while (tmp[row])
	{
		flag = false;
		col = 0;
		while (tmp[row][col] != '\0')
		{
			if (!ft_isdigit(tmp[row][col])
			&& tmp[row][col] != ' '
			&& tmp[row][col] != '	')
				return (print_error_msg("Invalid rgb value."), false);
			if (ft_isdigit(tmp[row][col]))
				flag = true;
			if (flag && (tmp[row][col] == ' ' || tmp[row][col] == '	'))
				return (print_error_msg("No space between numbers."), false);
			col++;
		}
		row++;
	}
	return (true);
}

bool	check_rgb_value(int *color)
{
	size_t	index;

	index = 0;
	while (color[index] != -1)
	{
		if (0 > color[index] || color[index] > 255)
			return (print_error_msg("Invalid rgb value."), false);
		index++;
	}
	if (index != 3)
		return (print_error_msg("Invalid rgb value."), false);
	return (true);
}
