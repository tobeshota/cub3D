/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/02/05 16:10:41 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	view_point_rotate(t_data *data, bool left, bool right)
{
	int	*angle;

	angle = &data->game->ray->angle;
	if (right)
		*angle -= ROTATE;
	if (left)
		*angle += ROTATE;
	if (*angle == 360)
		*angle = 0;
	if (*angle == -2)
		*angle = 358;
	data->game->dirx = VECTOR * cos(get_radian(*angle));
	data->game->diry = -1 * (VECTOR * sin(get_radian(*angle)));
	data->game->camx = CAMERA / 2 * sin(get_radian(*angle));
	data->game->camy = CAMERA / 2 * -1 * cos(get_radian(*angle));
	ray_cast(data);
	return ;
}
