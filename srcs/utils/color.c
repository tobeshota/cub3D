/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/02/05 20:21:34 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

unsigned int	get_color_number(int alpha, int red, int green, int blue)
{
	size_t			index;
	unsigned int	multiplication;
	unsigned int	color;

	index = 0;
	multiplication = 1;
	color = 0;
	while (index < RGBA)
	{
		if (index)
			multiplication *= EIGHT;
		if (index == 0)
			color += blue * multiplication;
		if (index == 1)
			color += green * multiplication;
		if (index == 2)
			color += red * multiplication;
		if (index == 3)
			color += alpha * multiplication;
		index++;
	}
	return (color);
}
