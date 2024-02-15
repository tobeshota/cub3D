/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_related.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/02/15 14:07:38 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_RELATED_H
# define MLX_RELATED_H

# include "libft.h"
# include "mlx.h"
# include "define.h"
# include "ray.h"
# include "utils.h"
# include "error.h"

void	init_mlx(t_data *data);
void	mlx_hook_list(t_data *data);
void	create_window(t_data *data);
int		closing_process(t_game *game);

#endif
