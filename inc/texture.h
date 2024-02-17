/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/02/17 17:35:32 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include "libft.h"
# include "mlx.h"
# include "define.h"
# include "utils.h"
# include "check.h"
# include "error.h"

void			init_texture(t_data *data);
unsigned int	get_texture_color(t_game *game, t_ray *ray, int y);
void			draw_texture(t_game *game, t_texture *texture);

#endif