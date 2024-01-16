/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:32:08 by csakamot          #+#    #+#             */
/*   Updated: 2024/01/17 04:59:05 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdbool.h>
# include "../libft/inc/libft.h"
# include "./define.h"

bool	judge_map_chara(const char chara);
size_t	blank_pass(char *str);
size_t	ft_array_len(char **array);
size_t	ft_path_len(char *str);
size_t	ft_line_len(char *str);
int		ft_strrncmp(const char *s1, const char *s2, size_t n);

#endif