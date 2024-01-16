/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/01/16 13:53:49 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H

# include <stdio.h>
# include "../libft/inc/libft.h"
# include "./define.h"
# include "./utils.h"
# include "./error.h"

int		check_input_nbrs(char *map_src, char *direction, size_t *position);
bool	check_path_line(char *str, size_t position, size_t len);
bool	check_rgb_value(char **tmp);

#endif