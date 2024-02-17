/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/02/17 19:17:43 by toshota          ###   ########.fr       */
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
	if (*angle == 360)
		*angle = 0;
	if (*angle == -2)
		*angle = 358;
	data->game->dirx = VECTOR * cos(get_radian(*angle));
	data->game->diry = -1 * (VECTOR * sin(get_radian(*angle)));
	data->game->camx = CAMERA / 2 * sin(get_radian(*angle));
	data->game->camy = CAMERA / 2 * cos(get_radian(*angle));
	ray_cast(data);
	return ;
}
