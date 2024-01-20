/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_set_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/01/20 16:23:02 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

bool	check_data_position(t_mark *mark)
{
	if (mark->no > mark->map
		|| mark->so > mark->map
		|| mark->we > mark->map
		|| mark->ea > mark->map
		|| mark->fl > mark->map
		|| mark->ce > mark->map)
		return (
			print_error_msg("Variables are declared after the map."),
			false
		);
	return (true);
}
