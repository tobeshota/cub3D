/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/01/15 16:05:31 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include <stdbool.h>
# include <stdio.h>
# include "../libft/inc/libft.h"
# include "./define.h"
# include "./utils.h"
# include "./error.h"

void	init_map(t_data *data, int argc, char **argv);
void	input_map(t_map *map, int argc, char **argv);
void	set_map(t_map *map, char *map_src);
void	set_texture_path(t_map *map, char *map_src);

#endif