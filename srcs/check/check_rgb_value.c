/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/01/16 15:38:58 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/check.h"

bool	check_rgb_value(char **tmp)
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
				return (print_error_msg("Invalid rgb color."), false);
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
