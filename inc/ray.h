/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/02/17 19:18:56 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include <math.h>
# include "libft.h"
# include "../minilibx-linux/mlx.h"
# include "define.h"
# include "texture.h"
# include "utils.h"
# include "error.h"

void	init_raycast(t_data *data, t_game *game);
int		ray_cast(t_data *data);
void	ray_firing(t_game *game, t_ray *ray, int x);
void	dda_exec(t_map *map, t_ray *ray);
void	draw_wall(t_map *map, t_game *game, t_ray *ray, int x);
void	view_point_rotate(t_data *data, int dir_to_move);

#endif
