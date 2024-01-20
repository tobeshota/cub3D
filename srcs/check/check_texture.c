/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/01/20 19:41:17 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

static bool	empty_texture_check(t_map *map)
{
	return (false);
}

bool	check_texture(t_map *map)
{
	if (empty_texture_check(map))
		return (false);
	return (true);
}
