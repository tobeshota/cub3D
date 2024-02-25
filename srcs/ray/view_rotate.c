/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/02/25 13:07:52 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	view_point_rotate(t_data *data, int dir_to_move)
{
	int	*angle;

	angle = &data->game->ray->angle;
	if (dir_to_move == RIGHT)
		*angle -= ROTATE;
	else if (dir_to_move == LEFT)
		*angle += ROTATE;
	else
		return ;
	if (*angle == CIRCLE)
		*angle = 0;
	if (*angle == -ROTATE)
		*angle = CIRCLE - ROTATE;
	data->game->dirx = VECTOR * cos(get_radian(*angle));
	data->game->diry = -1 * (VECTOR * sin(get_radian(*angle)));
	data->game->camx = CAMERA / 2 * sin(get_radian(*angle));
	data->game->camy = CAMERA / 2 * cos(get_radian(*angle));
	ray_cast(data);
	return ;
}
